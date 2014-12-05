#include "UI.h"

namespace Spectre {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	System::Void UI::RefreshColorScheme()
	{
		Color clr = System::Drawing::Color::White;

		uiMainMenu->BackColor = clr;
		uiFaq->BackColor = clr;
		uiPreset->BackColor = clr;
		uiTrap->BackColor = clr;
		uiHand->BackColor = clr;
		uiAuthors->BackColor = clr;
		uiGlobal->BackColor = clr;
		uiGfx->BackColor = clr;
		panPresetControl->BackColor = clr;
		panPresetControl1->BackColor = clr;
		panPresetControl2->BackColor = clr;

		txtImp->Font = font;
		txtSpec->Font = font;

		lblTitle->Text = "Влияние формы импульса\nна ширину его спектра";
	}

	System::Void UI::AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e)
	{
		_AdaptToWindowSize();
	}

	System::Void UI::_AdaptToWindowSize()
	{
		// Проверяем, изменились ли размеры окна
		static int w = -1, h = -1;
		if (ClientSize.Width == w && ClientSize.Height == h)
			return;
		w = ClientSize.Width;
		h = ClientSize.Height;
		// -------------------------------------

		int Spacing = 10;
		int LeftPanelWidth = 280;
		int TopPanelHeight = 80;

		uiMainMenu->Left = 0;
		uiMainMenu->Top = 0;
		uiMainMenu->Width = ClientSize.Width;
		uiMainMenu->Height = ClientSize.Height;
		uiPreset->Left = 0;
		uiPreset->Top = 0;
		uiPreset->Width = ClientSize.Width;
		uiPreset->Height = ClientSize.Height;
		uiTrap->Left = 0;
		uiTrap->Top = 0;
		uiTrap->Width = ClientSize.Width;
		uiTrap->Height = ClientSize.Height;
		uiHand->Left = 0;
		uiHand->Top = 0;
		uiHand->Width = ClientSize.Width;
		uiHand->Height = ClientSize.Height;
		uiFaq->Left = 0;
		uiFaq->Top = 0;
		uiFaq->Width = ClientSize.Width;
		uiFaq->Height = ClientSize.Height;
		uiAuthors->Left = 0;
		uiAuthors->Top = 0;
		uiAuthors->Width = ClientSize.Width;
		uiAuthors->Height = ClientSize.Height;

		btnBack->Left = Spacing;
		btnBack->Top = ClientSize.Height - Spacing - btnBack->Height;

		// global
		uiGlobal->Left = 0;
		uiGlobal->Top = ClientSize.Height - uiGlobal->Height;

		// uiMainMenu
		lblTitle->Left = (ClientSize.Width - lblTitle->Width) / 2;

		pbxPhys->Top = Spacing;
		pbxPhys->Left = Spacing;
		pbxCMC->Top = Spacing;
		pbxCMC->Left = ClientSize.Width - 150 /*pbxCMC->Width*/ - Spacing;

		btnExit->Top = ClientSize.Height - btnExit->Height - Spacing;
		btnAuthors->Top = btnExit->Top - btnAuthors->Height - Spacing;
		btnHand->Top = btnAuthors->Top - btnHand->Height - Spacing;
		btnTrap->Top = btnHand->Top - btnTrap->Height - Spacing;
		btnPreset->Top = btnTrap->Top - btnPreset->Height - Spacing;
		btnFaq->Top = btnPreset->Top - btnFaq->Height - Spacing;

		btnPreset->Left = (ClientSize.Width - btnPreset->Width) / 2;
		btnFaq->Left = btnPreset->Left;
		btnFaq->Width = btnPreset->Width;
		btnTrap->Left = btnPreset->Left;
		btnTrap->Width = btnPreset->Width;
		btnHand->Left = btnPreset->Left;
		btnHand->Width = btnPreset->Width;
		btnAuthors->Left = btnPreset->Left;
		btnAuthors->Width = btnPreset->Width;
		btnExit->Left = btnPreset->Left;
		btnExit->Width = btnPreset->Width;

		// uiFaq
		pbxFaq->Left = 0;
		pbxFaq->Top = 0;
		pbxFaq->Width = uiFaq->Width;
		pbxFaq->Height = uiFaq->Height;

		// uiPreset
		lblPreset->Left = (ClientSize.Width - lblPreset->Width) / 2;

		// uiTrap
		lblTrap->Left = (ClientSize.Width - lblTrap->Width) / 2;

		// uiHand
		lblHand->Left = (ClientSize.Width - lblHand->Width) / 2;


		// uiGfx
		uiGfx->Width = ClientSize.Width - LeftPanelWidth - Spacing;
		uiGfx->Height = ClientSize.Height - TopPanelHeight - Spacing;
		uiGfx->Left = LeftPanelWidth;
		uiGfx->Top = TopPanelHeight;

		if (0)
		{
			pbxImp->Width = uiGfx->Width;
			pbxSpec->Width = pbxImp->Width;
			pbxImp->Height = (uiGfx->Height - Spacing) / 2;
			pbxSpec->Height = pbxImp->Height;

			pbxImp->Left = 0;
			pbxSpec->Left = 0;
			pbxImp->Top = 0;
			pbxSpec->Top = pbxImp->Height + Spacing;
		}
		else
		{
			pbxImp->Width = Math::Min((uiGfx->Width - Spacing) / 2, uiGfx->Height - Spacing * 3 - txtImp->Height);
			pbxImp->Height = pbxImp->Width;

			pbxSpec->Width = pbxImp->Width;
			pbxSpec->Height = pbxImp->Height;

			pbxImp->Left = 0;
			pbxSpec->Left = pbxImp->Width + Spacing;
			pbxImp->Top = (uiGfx->Height - pbxImp->Height + txtImp->Height) / 2;
			pbxSpec->Top = pbxImp->Top;

			txtImp->Top = 0;
			txtSpec->Top = 0;
			txtImp->Left = (pbxImp->Width - txtImp->Width) / 2;
			txtSpec->Left = pbxSpec->Left + (pbxSpec->Width - txtSpec->Width) / 2;

			txtImpY->Left = pbxImp->Left;
			txtImpY->Top = pbxImp->Top - txtImpY->Height;
			txtSpecY->Left = pbxSpec->Left;
			txtSpecY->Top = pbxSpec->Top - txtSpecY->Height;

			txtImpX->Left = pbxImp->Right - txtImpX->Width;
			txtImpX->Top = pbxImp->Bottom;
			txtSpecX->Left = pbxSpec->Right - txtSpecX->Width;
			txtSpecX->Top = pbxSpec->Bottom;

			lblMessage->Top = pbxImp->Top + Spacing;
			lblMessage->Left = pbxImp->Left + Spacing;
		}


		RawHand = gcnew array<Point>(pbxImp->Width);
		ResetHand();

		uiGfx->BringToFront();
		uiGlobal->BringToFront();
		btnBack->BringToFront();

		InvalidateAll();
	}
	System::Void UI::btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
		Back();
	}
	System::Void UI::Back() {
		uiMainMenu->Visible = true;
		uiFaq->Visible = false;
		uiPreset->Visible = false;
		uiTrap->Visible = false;
		uiHand->Visible = false;
		uiAuthors->Visible = false;
		uiGfx->Visible = false;
		uiGlobal->Visible = false;
		bDrawingMode = false;
		lblMessage->Visible = false;
		btnBack->Visible = false;

		E_0 = E_0_def;
	}
	System::Void UI::btnFaq_Click(System::Object^  sender, System::EventArgs^  e) {
		uiMainMenu->Visible = false;
		uiFaq->Visible = true;
		btnBack->Visible = true;
		btnBack->BringToFront();
	}
	System::Void UI::btnPreset_Click(System::Object^  sender, System::EventArgs^  e)
	{
		PresetFuncChanged(sender, e);

		uiMainMenu->Visible = false;
		uiPreset->Visible = true;
		uiGfx->Visible = true;
		uiGlobal->Visible = true;
		btnBack->Visible = true;
		btnBack->BringToFront();

		SpecXMult = 118;
		ImpXMult = 13;
		SpecYMult = 0.15;
	}
	System::Void UI::btnTrap_Click(System::Object^  sender, System::EventArgs^  e)
	{
		buf[1].generate_rect();
		TrapWidthChanged(sender, e);

		uiMainMenu->Visible = false;
		uiTrap->Visible = true;
		uiGfx->Visible = true;
		uiGlobal->Visible = true;
		btnBack->Visible = true;
		btnBack->BringToFront();

		SpecXMult = 118;
		ImpXMult = 13;
		SpecYMult = 0.15;
	}
	System::Void UI::btnHand_Click(System::Object^  sender, System::EventArgs^  e) {
		buf[0].generate_null();
		buf[1].generate_null();
		btnReset_Click(sender, e);

		uiMainMenu->Visible = false;
		uiHand->Visible = true;
		uiGfx->Visible = true;
		uiGlobal->Visible = true;
		btnBack->Visible = true;
		btnBack->BringToFront();
		bDrawingMode = true;

		ImpXMult = 13;
		SpecYMult = 0.125;
	}
	System::Void UI::btnAuthors_Click(System::Object^  sender, System::EventArgs^  e) {
		uiMainMenu->Visible = false;
		uiAuthors->Visible = true;
		btnBack->Visible = true;
		btnBack->BringToFront();
	}
	System::Void UI::btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
}