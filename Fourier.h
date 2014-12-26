#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "../FFTW/fftw3.h"
#include <string.h>
#include <iostream>

#pragma comment(lib, "../FFTW/libfftw3-3")

using namespace std;

// DEPRECATED
extern double E_0;
extern const double E_0_def;

extern float PointsPerSecond;
extern int ImpHalfWidth;
const long double pi = 3.14159265358979323846;
extern double Level, DefaultLevel;

void SpecInvalidate();

struct buffer 
{
	double *imp;
	double *spec;

	fftw_complex *cspec;
	fftw_plan p;
	int len;

	double MaxSpec;
	int SpecWidth;

	buffer() : imp(NULL), spec(NULL), cspec(NULL), len(0), p(NULL), MaxSpec(1) {}

	~buffer()
	{
		free();
	}

	void free()
	{
		if(imp) fftw_free(imp);
		imp = NULL;
		if(spec) fftw_free(spec);
		spec = NULL;
		if(cspec) fftw_free(cspec);
		cspec = NULL;
		if(p) fftw_destroy_plan(p);
		p = NULL;
	}

	void alloc(int n)
	{
		free();
		len = n;
		imp = (double*)fftw_malloc(sizeof(double)*len);
		spec = (double*)fftw_malloc(sizeof(double)*(len/2+1));
		cspec = fftw_alloc_complex(sizeof(double)*(len/2+1));
		p = fftw_plan_dft_r2c_1d(len, imp, cspec, FFTW_ESTIMATE);
	}

	void fourier()
	{
		fftw_execute(p);
		for (int i = 0; i <= len / 2; i++)
		{
			spec[i] = 2 * sqrt((cspec[i][0] * cspec[i][0] + cspec[i][1] * cspec[i][1]) / len);
		}

	
		double SpecSqrSum = 0;
		MaxSpec = 0;
		for(int i = 0; i <= len/2; i++)
		{
			SpecSqrSum += pow(spec[i], 2);
			if (spec[i] > MaxSpec) MaxSpec = spec[i];

			if (i == (int)(len / PointsPerSecond)) cout << "  SpecSqrSum [0:1] = " << SpecSqrSum << '\n';
		}
		cout << "  SpecSqrSum = " << SpecSqrSum << '\n';

		int i;
		double temp = Level * SpecSqrSum;
		for (i = 0; (temp > 0) && (i <= len / 2); ++i)
		{
			temp -= pow(spec[i], 2);
		}
		SpecWidth = i; //- ((.5*spec[i] < Level*SpecSqrSum - t) ? 0 : 1);
		cout << "  SpecWidth = " << SpecWidth << '\n';

		/////////////////////////////
		double tt = 0;
		for (int i = 0; i < SpecWidth; ++i)
		{
			tt += pow(spec[i], 2);
		}
		cout << "     " << tt << '/' << Level * SpecSqrSum << " (" << Level << " of " << SpecSqrSum << ")" << '\n';

		/////////////////////////////
/*
// Хранить в спеке квадрат (для отладки)
		for (int i = 0; i <= len/2; ++i)
		{
			spec[i] *= spec[i];
		}
*/
	}
	double imp_sqr_int(int x)
	{
		double res = 0;
		int r = len / 2 + x;
		if (r >= len) r = len - 1;
		for (int i = len / 2; i <= r; ++i)
		{
			res += pow(imp[i], 2);
		}
		return res;
	}

/*
	double imp_sqr_int_inv(double y)
	{
		int x;
		for (x = 0; x < len / 2; ++x)
		{
			y -= pow(imp[x], 2);
			if (y <= 0)
			{
				cout << "imp_sqr_int_inv: overhead = " << -y << endl;
				return x;
			}
		}
	}
*/

	double calc_sum(int Median, double IntSqr, /*out*/ int &left, /*out*/ int &right)
	{
		// Суммируем, постепенно симметрично отступая от средневзвешенного
		double Sum = Level * IntSqr;
		for(int i = 0; i < len/2; ++i)
		{
			if(Median + i >= len)
			{
				cout << "Median is odd (+)\n";
			}
			else
			{
				Sum -= pow(imp[Median + i], 2);
				right = Median + i;
				if(Sum < 0) break;
			}
			
			if(Median - i < 0)
			{
				cout << "Median is odd (-)\n";
			}
			else
			{
				Sum -= pow(imp[Median - i], 2);
				left = Median - i;
				if(Sum < 0) break;
			}
		}
		return Sum;
	}
	int calc_width()
	{
		// Делим график на чанки
		const int CHUNK_SIZE = 128;
		int ChunkCount = len / CHUNK_SIZE;
		int Shift = (len % CHUNK_SIZE) / 2;
		double *Chunks = new double[ChunkCount];

		// Суммируем на каждом
		double IntSqr = 0;
		for (int i = 0; i < ChunkCount; ++i)
		{
			Chunks[i] = 0;
			for (int j = 0; j < CHUNK_SIZE; ++j)
			{
				Chunks[i] += pow(imp[Shift + CHUNK_SIZE * i + j], 2);
			}
			IntSqr += Chunks[i];
		}

		// TODO: Не случится ли чего, если он будет не нулём, но очень маленьким?
		if (IntSqr == 0) return 0;

		// Находим средневзвешенное
		double _Median = 0;
		for (int i = 0; i < ChunkCount; ++i)
			_Median += (Shift + CHUNK_SIZE * i + CHUNK_SIZE / 2) * Chunks[i] / IntSqr;
		int Median = (int)_Median;

		delete[] Chunks;
/*
		// Немного подправляем массив для меньших потерь округления
		double _IntSqr = IntSqr;
		IntSqr = round(IntSqr * .1) * 10; // Точность, где же ты?
		double RoundingCoef = sqrt(IntSqr / _IntSqr);
		for (int i = 0; i < len; ++i)
		{
			imp[i] *= RoundingCoef;
		}
*/
		// Суммируем, постепенно симметрично отступая от средневзвешенного
		int left, right;
		double Sum = calc_sum(Median, IntSqr, left, right);

		// Небольшие жадные подправки
		bool adjusted = false;
		while (left >= 0 && (pow(imp[left - 1], 2) > pow(imp[right], 2)))
		{
			--left;
			--right;
			adjusted = true;
		}
		while (right < len && (pow(imp[right + 1], 2) > pow(imp[left], 2)))
		{

			++left;
			++right;
			adjusted = true;
		}
		if (adjusted)
		{
			Median = (left + right) / 2;
			// Суммируем, постепенно симметрично отступая от нового средневзвешенного
			Sum = calc_sum(Median, IntSqr, left, right);
		}

		int width = right - left;
		cout << "\twidth = " << width << ", overhead = " << Sum << ", left = " << left <<
			", right = " << right << endl;

		return width;

	}
	void check_energy()
	{
		int halfwidth = calc_width() / 2;
		if (halfwidth > ImpHalfWidth)
		{
			cout << "\tWidth is too big (more than needed by " << halfwidth - ImpHalfWidth << ")\n";
		}
		if (halfwidth >= ImpHalfWidth)
		{
			return;
		}

		int x; // Сколько нужно добавить
		// Добавляем ширины
		if (halfwidth == 0)
		{
			x = round(ImpHalfWidth / Level);
		}
		else
		{
			FILE *f = fopen("deb.txt", "w");

			int l = 0, r = len / 2;
			double e = Level * imp_sqr_int(len); // Требуемое значение энергии внутри отсечек   ( типа imp_sqr_int(inf) )
			for (x = 0; (imp_sqr_int(ImpHalfWidth - x) + fmin(x, ImpHalfWidth)) > Level * (imp_sqr_int(len) + x); ++x) // x > e + Level * x - imp_sqr_int(ImpHalfWidth - x)
			{
				fprintf(f, "%d %lf\n", x, (imp_sqr_int(ImpHalfWidth - x) + fmin(x, ImpHalfWidth)) / (imp_sqr_int(len) + x));
				if (x > 1000)// ImpHalfWidth)
				{
					cout << "ERROR\n";
					x = 0;
					break;
				}
			}

			fclose(f);
		}

		int length = ++x;

		/////////////////////////////////
/*
		double energy = E_0;

		for (int i = 0; i < len; i++){
			energy -= imp[i]*imp[i];
		}
		

		int length = (int)(energy * .5);
*/


		if(length > 0) 
		{
			for(int i = length; i < len/2 - 1; i++)
			{
				imp[i - length] = imp[i];
			}

			for(int i = len - length - 1; i > len/2; i--)
			{
				imp[i + length] = imp[i];
			}

			for(int i = len/2 - length - 1; i <= (len/2 + length); i++)
			{
				imp[i] = 1.0;
			}
		}
/*
		cout << "check energy: E0 = " << E_0 << ", Efunc = " << E_0 - energy
			<< ", Efixed = " << E_0 - energy + 2*length << endl;
*/
		halfwidth = calc_width() / 2;
		cout << "New halfwidth = " << halfwidth << " (" << ImpHalfWidth << " needed)\n";
	}

	void generate_null()
	{
		cout << "gen null\n";
		memset(imp, 0, sizeof(double)*len);
		fourier();
	}

	void generate_gauss(double param)
	{
		cout << "gen gauss\n";
		for (int i = 0; i < len; i++)
		{
			imp[i] = exp(-((i-len/2)*(i-len/2)/(param*param)));
		}
		check_energy();
		fourier();
	}

	void generate_rect()
	{
		cout << "gen rect\n";
		memset(imp, 0, sizeof(double)*len);
		check_energy();
		fourier();
/*
		// Хотфикс кривой отсечки
		int t;
		for (t = 1; t < len / 2 + 1; t++)
		{
			if (spec[t - 1] > spec[t] && spec[t] < spec[t + 1])
				break;
		}
		double SubSum = 0, FullSum, NewLevel;
		for (int i = 0; i < t; ++i)
			SubSum += pow(spec[i], 2);
		FullSum = SubSum;
		for (int i = t; i < len / 2 + 1; ++i)
			FullSum += pow(spec[i], 2);
		NewLevel = SubSum / FullSum;
		if (abs(NewLevel - DefaultLevel) < .05)
			Level = NewLevel;
		else
			Level = DefaultLevel;
*/
		cout << "l=" << Level << " (" << (Level == DefaultLevel) << ")\n";
		// Пересчитываем ширину
		/*
		double ts = 0;
		int i;
		for (i = 0; ts / FullSum < Level && i < len / 2 + 1; ++i)
		{
			ts += pow(spec[i], 2);
		}
		SpecWidth = i;
		*/
		cout << "gen rect 2\n";
		SpecInvalidate();
		//fourier();
	}

	void generate_tri_f_p()
	{
		double length = (double)(E_0) * 1.5;
		for (int i = 0; i < len/2 - length - 1; i++)
		{
			imp[i] = 0.0;
		}

		for (int i = len/2 - length - 1; i < len/2; i++)
		{
			imp[i] = (i - (len/2 - length - 1))/length;
		}

		for (int i = len/2; i < len/2 + length - 1; i++)
		{
            imp[i] = ((length - 1 + len/2) - i)/length;
		}

		for(int i = len/2 + length - 1; i < len; i++)
		{
			imp[i] = 0.0;
		}
		cout << "tri_f_p ";
		check_energy();
		fourier();
	}

	void generate_gauss_f_p()
	{
		double length = (double)(E_0);
		for (int i = 0; i < len; i++)
		{
			imp[i] = exp(-((i-len/2 + 1)*(i-len/2 + 1)/pow(.638*length/sqrt(2/pi),2)));
		}
		cout << "gauss_f_p ";
		check_energy();
		fourier();
	}

	void generate_sin_f_p()
	{
		double length = (double)(E_0);
		for (int i = 0; i < len/2 - length - 1; i++)
		{
			imp[i] = 0.0;
		}

		for (int i = len/2 - length - 1; i < len/2; i++)
		{
			imp[i] = sin((pi/2)*((i - (len/2 - length - 1))/length));
		}

		for (int i = len/2; i < len/2 + length - 1; i++)
		{
			imp[i] = sin((pi/2)*(((len/2 + length - 1) - i)/length));
		}

		for (int i = len/2 + length - 1; i < len; i++)
		{
			imp[i] = 0.0;
		}
		cout << "sin_f_p ";
		check_energy();
		fourier();
	}
};

extern buffer buf[2];

float Interpolate(float start, float finish, float t);

namespace Fourier
{
	void function(int index, int left, int right);
}