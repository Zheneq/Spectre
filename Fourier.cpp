#include <stdlib.h>
#include <stdio.h>
#include "Fourier.h"

buffer buf[2];

// DEPRECATED
const double E_0_def = 300;
double E_0 = E_0_def;

int ImpHalfWidth = 270;
double DefaultLevel = 0.90282233018308548168257003610692; // .90457703976772257201578964538544;
double Level = DefaultLevel;
int implen, len;

float Interpolate(float start, float finish, float t)
{
	// Ћинейна€ интерпол€ци€
	return start + (finish - start)*t;
}

void SpecInvalidate()
{
	buf[0].fourier();
	buf[1].fourier();
}