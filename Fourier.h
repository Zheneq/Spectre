#pragma once
#include "../FFTW/fftw3.h"
#include <string.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#pragma comment(lib, "../FFTW/libfftw3-3")

extern float PointsPerSecond;
extern double E_0;
extern const double E_0_def;
const long double pi = M_PI;
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

			if (i == (int)(len / PointsPerSecond)) std::cout << "  SpecSqrSum [0:1] = " << SpecSqrSum << '\n';
		}
		std::cout << "  SpecSqrSum = " << SpecSqrSum << '\n';

		int i;
		double temp = Level * SpecSqrSum;
		for (i = 0; (temp > 0) && (i <= len / 2); ++i)
		{
			temp -= pow(spec[i], 2);
		}
		SpecWidth = i; //- ((.5*spec[i] < Level*SpecSqrSum - t) ? 0 : 1);
		std::cout << "  SpecWidth = " << SpecWidth << '\n';

		/////////////////////////////
		double tt = 0;
		for (int i = 0; i < SpecWidth; ++i)
		{
			tt += pow(spec[i], 2);
		}
		std::cout << "     " << tt << '/' << Level * SpecSqrSum << " (" << Level << " of " << SpecSqrSum << ")" << '\n';

	}

	void check_energy(){

		double energy = E_0;

		for (int i = 0; i < len; i++){
			energy -= imp[i]*imp[i];
		}
		

		int length = (int)(energy * .5);
		if(length > 0) 
		{
			for(int i = length; i < len/2; i++)
			{
				imp[i - length] = imp[i];
			}

			for(int i = len - length - 1; i > len/2; i--)
			{
				imp[i + length] = imp[i];
			}

			for(int i = len/2 - length; i <= (len/2 + length); i++)
			{
				imp[i] = 1.0;
			}
		}
		std::cout << "check energy: E0 = " << E_0 << ", Efunc = " << E_0 - energy
			<< ", Efixed = " << E_0 - energy + 2*length << std::endl;
	}

	void generate_null()
	{
		std::cout << "gen null\n";
		memset(imp, 0, sizeof(double)*len);
		fourier();
	}

	void generate_gauss(double param)
	{
		std::cout << "gen gauss\n";
		for (int i = 0; i < len; i++)
		{
			imp[i] = exp(-((i-len/2)*(i-len/2)/(param*param)));
		}
		check_energy();
		fourier();
	}

	void generate_rect()
	{
		std::cout << "gen rect\n";
		memset(imp, 0, sizeof(double)*len);
		check_energy();
		fourier();

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

		std::cout << "l=" << Level << " (" << (Level == DefaultLevel) << ")\n";
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
		std::cout << "gen rect 2\n";
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
		std::cout << "tri_f_p ";
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
		std::cout << "gauss_f_p ";
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
		std::cout << "sin_f_p ";
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