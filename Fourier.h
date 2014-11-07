#pragma once
#include "../FFTW/fftw3.h"
#include <string.h>
#include <iostream>
#include <math.h>
#pragma comment(lib, "../FFTW/libfftw3-3")

extern double E_0;
const long double pi = 3.14159265359;
const double Level = .95;

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
		int i;
		MaxSpec = 0;
		double SpecSum = 0, t = 0;
		for(i = 0; i < len/2 + 1; i++)
		{
			spec[i] = (cspec[i][0]*cspec[i][0]+cspec[i][1]*cspec[i][1])/len;
			if(spec[i] > MaxSpec) MaxSpec = spec[i];
			SpecSum += spec[i];
		}
		for (i = 0; t/SpecSum < Level && i < len / 2 + 1; ++i)
		{
			t += spec[i];
		}
		SpecWidth = i;
	}

	void check_energy(){

		double energy = E_0;

		for (int i = 0; i < len; i++){
			energy -= imp[i]*imp[i];
		}
		

		int length = (int)(energy * .5);
		if(length <= 0) return;

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

		std::cout << "check energy: E0 = " << E_0 << ", Efunc = " << E_0 - energy
			<< ", Efixed = " << E_0 - energy + 2*length << std::endl;
	}

	void generate_null()
	{
		memset(imp, 0, sizeof(double)*len);
		fourier();
	}

	void generate_gauss(double param)
	{
		for (int i = 0; i < len; i++)
		{
			imp[i] = exp(-((i-len/2)*(i-len/2)/(param*param)));
		}
		check_energy();
		fourier();
	}

	void generate_rect()
	{
		memset(imp, 0, sizeof(double)*len);
		check_energy();
		fourier();
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
			imp[i] = exp(-((i-len/2 + 1)*(i-len/2 + 1)/(((length)/sqrt(pi))*((length)/sqrt(pi)))));
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