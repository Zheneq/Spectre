#include "UI.h"

namespace Spectre {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	System::Void UI::InvalidateAll()
	{
		pbxImp->Invalidate();
		pbxSpec->Invalidate();
	}
	System::Void UI::onClick(System::Object^  sender, System::EventArgs^  e)
	{
		//			InvalidateAll();
	}
	System::Void UI::onImpPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		DrawImp(e);
	}
	System::Void UI::onSpecPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		DrawSpec(e);
	}




	System::Void UI::trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 E_0 = 15 * trackBar1->Value;
			 PresetFuncChanged(sender, e);
			 /*
			 buf[0].generate_gauss(100);
			 buf[1].generate_rect();
			 */
			 InvalidateAll();
}
	System::Void UI::trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		ImpXMult = trackBar3->Value;
		SpecXMult = trackBar2->Value;
		std::cout << "tb2 " << SpecXMult << '\n' << "tb3 " << ImpXMult << '\n';
		InvalidateAll();
}
	System::Void UI::trackBar4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		SpecYMult = 1.25 / (float)trackBar4->Value;
		std::cout << "SpecYMult " << SpecYMult << '\n';
		InvalidateAll();
}
	System::Void UI::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		FILE *f = fopen("dump.txt", "w");
		for (int i = 0; i <= buf[0].len / 2; ++i)
		{
			fprintf(f, "%d, %lf\n", i, pow(buf[0].spec[i], 2));
		}
		fprintf(f, "\n\n");
		for (int i = 0; i <= buf[1].len / 2; ++i)
		{
			fprintf(f, "%d, %lf\n", i, pow(buf[1].spec[i], 2));
		}
		fclose(f);
	}

	System::Void UI::PresetFuncChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (rdbPreset11->Checked)
				 buf[0].generate_gauss_f_p();
			 if (rdbPreset12->Checked)
				 buf[0].generate_sin_f_p();
			 if (rdbPreset13->Checked)
				 buf[0].generate_tri_f_p();
			 if (rdbPreset14->Checked)
				 buf[0].generate_rect();

			 if (rdbPreset21->Checked)
				 buf[1].generate_gauss_f_p();
			 if (rdbPreset22->Checked)
				 buf[1].generate_sin_f_p();
			 if (rdbPreset23->Checked)
				 buf[1].generate_tri_f_p();
			 if (rdbPreset24->Checked)
				 buf[1].generate_rect();

			 InvalidateAll();

}
	System::Void UI::TrapWidthChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (trbTrap->Value)
				 buf[0].generate_gauss(trbTrap->Value);
			 else
				 buf[0].generate_rect();
			 InvalidateAll();
		 }



	System::Void UI::ShowMessage(String ^msg, bool bImportant)
	{
		if (!tmrMessage->Enabled || bImportant)
		{
			lblMessage->Text = msg;
			lblMessage->Visible = true;
			MsgTime = 0;
			tmrMessage->Enabled = true;
		}
	}

	System::Void UI::tmrMessage_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		MsgTime++;
		if (MsgTime > 60 || bDrawing)
		{
			lblMessage->Visible = false;
			tmrMessage->Enabled = false;
		}
	}

	System::Void UI::PicLoaded(System::Object ^, System::ComponentModel::AsyncCompletedEventArgs ^)
	{
		_AdaptToWindowSize();
	}
}