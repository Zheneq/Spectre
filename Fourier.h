#pragma once
#include <fftw3.h>

struct buffer 
{
	double *imp;
	double *spec;
	fftw_plan p;
	int len;

	buffer() : imp(NULL), spec(NULL), len(0) {}
	~buffer()
	{
		free();
	}

	void free()
	{
		if(imp) fftw_free(imp);
		imp = NULL;
		if(imp) fftw_free(spec);
		spec = NULL;
	}

	void alloc(int n)
	{
		free();
		imp = (double*)fftw_malloc(sizeof(double)*n);
		imp = (double*)fftw_malloc(sizeof(double)*n);
	}
};

extern double *imp[2][2], *spec[2][2];
extern int implen, speclen;

extern double XRangeImp[2], YRangeImp[2], XRangeSpec[2], YRangeSpec[2], XScaleImp, YScaleImp, XScaleSpec, YScaleSpec;

namespace Fourier
{
	void function(int index, int left, int right);
}