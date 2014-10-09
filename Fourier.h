#pragma once
#include <fftw3.h>
#pragma comment(lib, "../FFTW/libfftw3-3")

struct buffer 
{
	double *imp;
	double *spec;
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
		// p = 
	}
};

extern buffer buf[2];

namespace Fourier
{
	void function(int index, int left, int right);
}