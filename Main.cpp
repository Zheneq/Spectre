#include <cstdlib>
#include <cmath>

#include "UI.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

// Test
std::vector<float> RawHand[2];
double *imp[2][2] = {{NULL, NULL}, {NULL, NULL}}, *spec[2][2] = {{NULL, NULL}, {NULL, NULL}};
int implen = 0, speclen = 0;

double XRangeImp[2] = {0, 5}, YRangeImp[2] = {-2, 2};
double XScaleImp = 1 / (XRangeImp[1] - XRangeImp[0]);
double YScaleImp = 1 / (YRangeImp[1] - YRangeImp[0]);

double XRangeSpec[2] = {-3, 3}, YRangeSpec[2] = {-2, 2};
double XScaleSpec = 1 / (XRangeSpec[1] - XRangeSpec[0]);
double YScaleSpec = 1 / (YRangeSpec[1] - YRangeSpec[0]);
//// Test

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	// Test
	Fourier::alloc(100);
	for(int i=0; i<implen; ++i)
	{
		imp[1][0][i] = imp[0][0][i] = i*.05F;
		imp[0][1][i] = sin(imp[0][0][i]);
		imp[1][1][i] = cos(imp[0][0][i]);
	}
	for(int i=0; i<speclen; ++i)
	{
		spec[1][0][i] = spec[0][0][i] = i*.05F - 2;
		spec[0][1][i] = sin(10*spec[0][0][i]);
		spec[1][1][i] = cos(10*spec[0][0][i]);
	}
	//// Test

    Spectre::UI form;
    Application::Run(%form);
}

// Test
void Fourier::alloc(int num)
{
	if(imp[0][0]) free(imp[0][0]);
	if(imp[0][1]) free(imp[0][1]);
	if(imp[1][0]) free(imp[1][0]);
	if(imp[1][1]) free(imp[1][1]);
	if(spec[0][0]) free(spec[0][0]);
	if(spec[0][1]) free(spec[0][1]);
	if(spec[1][0]) free(spec[1][0]);
	if(spec[1][1]) free(spec[1][1]);


	implen = speclen = num;
	imp[0][0] = (double*)malloc(sizeof(double)*implen);
	imp[0][1] = (double*)malloc(sizeof(double)*implen);
	imp[1][0] = (double*)malloc(sizeof(double)*implen);
	imp[1][1] = (double*)malloc(sizeof(double)*implen);
	spec[0][0] = (double*)malloc(sizeof(double)*speclen);
	spec[0][1] = (double*)malloc(sizeof(double)*speclen);
	spec[1][0] = (double*)malloc(sizeof(double)*speclen);
	spec[1][1] = (double*)malloc(sizeof(double)*speclen);
}

// Test