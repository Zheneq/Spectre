#include <cstdlib>
#include <cmath>

#include "UI.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

// Test
std::vector<float> RawHand[2];
buffer buf[2];
//double *imp[2][2] = {{NULL, NULL}, {NULL, NULL}}, *spec[2][2] = {{NULL, NULL}, {NULL, NULL}};

//// Test

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	// Test
	buf[0].alloc(100);
	buf[1].alloc(100);
	for(int i=0; i<buf[0].len; ++i)
	{
		buf[0].imp[i] = sin(i*.05F);
		buf[1].imp[i] = cos(i*.05F);
	}
	for(int i=0; i<buf[0].len/2+1; ++i)
	{
		buf[0].spec[i] = sin(10*(i*.05F - 2));
		buf[1].spec[i] = cos(10*(i*.05F - 2));
	}
	//// Test

    Spectre::UI form;
    Application::Run(%form);
}