#pragma once

struct buffer 
{
	double *impX, *impY;
	int len;

	buffer() : impX(NULL), impY(NULL), len(0) {}
	~buffer()
	{
		free();
	}

	void free()
	{
		if(impX) fftw_free(impX);
		if(impY) fftw_free(impY);
	}

	void alloc(int n)
	{
		free();
		impX = (double*)fftw_malloc(sizeof(double)*n);
		impY = (double*)fftw_malloc(sizeof(double)*n);
	}
};

extern double *imp[2][2], *spec[2][2];
extern int implen, speclen;

extern double XRangeImp[2], YRangeImp[2], XRangeSpec[2], YRangeSpec[2], XScaleImp, YScaleImp, XScaleSpec, YScaleSpec;

namespace Fourier
{



	void alloc(int num);
	void function(int index, int left, int right);
}