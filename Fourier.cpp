#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Fourier.h"

buffer buf[2];

const double E_0_def = 300;
double E_0 = E_0_def;
int implen, len;

float Interpolate(float start, float finish, float t)
{
	// Ћинейна€ интерпол€ци€
	return start + (finish - start)*t;
}