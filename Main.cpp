#include <cstdlib>
#include <cmath>

#include "UI.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

// Test
std::vector<float> RawHand[2];
char textbuffer[512];
//buffer buf[2];
//double *imp[2][2] = {{NULL, NULL}, {NULL, NULL}}, *spec[2][2] = {{NULL, NULL}, {NULL, NULL}};
float PointsPerSecond = 300;

//// Test

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	// Test
	buf[0].alloc(16384);
	buf[1].alloc(16384);
	buf[0].generate_gauss(100);
	buf[1].generate_rect();
	//// Test

    Spectre::UI form;
	form.SetBounds(0,0,640,480);
    Application::Run(%form);
}