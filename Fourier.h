#pragma once

extern double *imp[2][2], *spec[2][2];
extern int implen, speclen;

extern double XRangeImp[2], YRangeImp[2], XRangeSpec[2], YRangeSpec[2], XScaleImp, YScaleImp, XScaleSpec, YScaleSpec;

namespace Fourier
{
	void alloc(int num);
	void function(int index, int left, int right);
}