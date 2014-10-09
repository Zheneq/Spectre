#pragma once
#include <fftw3.h>
#pragma comment(lib, "../FFTW/libfftw3-3")

struct buffer 
{
	double *imp;
	double *spec;

	fftw_complex *cspec;
	fftw_plan p;
	int len;

	double MaxSpec;

	buffer() : imp(NULL), spec(NULL), len(0), p(NULL), MaxSpec(1e-10) {}

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
		if(p) fftw_destroy_plan(p);
		p = NULL;
	}

	void alloc(int n)
	{
		free();
		len = n;
		imp = (double*)fftw_malloc(sizeof(double)*len);
		spec = (double*)fftw_malloc(sizeof(double)*(len/2+1));
		p = fftw_plan_dft_r2c_1d(len, imp, cspec, FFTW_ESTIMATE);
	}

	void fourier()
	{
		fftw_execute(p);

		MaxSpec = 0;
		for(int i = 0; i < len/2 + 1; i++)
		{
			spec[i] = (sqrt(cspec[i][0]*cspec[i][0]+cspec[i][1]*cspec[i][1]))/len;
			if(spec[i] > MaxSpec) MaxSpec = spec[i];
		}
	}
};

extern buffer buf[2];

namespace Fourier
{
	void function(int index, int left, int right);
}