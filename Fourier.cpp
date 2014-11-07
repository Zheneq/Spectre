#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Fourier.h"

buffer buf[2];

double E_0 = 300;
int implen, len;

float Interpolate(float start, float finish, float t)
{
	// Ћинейна€ интерпол€ци€
	return start + (finish - start)*t;
}