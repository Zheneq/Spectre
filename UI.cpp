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
		uiPreset->BackColor = clr;
		uiTrap->BackColor = clr;
		uiHand->BackColor = clr;
		uiGlobal->BackColor = clr;
		uiGfx->BackColor = clr;
		panPresetControl->BackColor = clr;
		panPresetControl1->BackColor = clr;
		panPresetControl2->BackColor = clr;

		txtImp->Font = font;
		txtSpec->Font = font;
	}

	System::Void UI::AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e)
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

		// global
		uiGlobal->Left = 0;
		uiGlobal->Top = ClientSize.Height - uiGlobal->Height;

		// uiMainMenu
		btnPreset->Left = (ClientSize.Width - btnPreset->Width) / 2;
		btnTrap->Left = btnPreset->Left;
		btnTrap->Width = btnPreset->Width;
		btnHand->Left = btnPreset->Left;
		btnHand->Width = btnPreset->Width;
		btnExit->Left = btnPreset->Left;
		btnExit->Width = btnPreset->Width;

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
			pbxImp->Top = 2 * Spacing + txtImp->Height;
			pbxSpec->Top = pbxImp->Top;

			txtImp->Top = 0;
			txtSpec->Top = 0;
			txtImp->Left = (pbxImp->Width - txtImp->Width) / 2;
			txtSpec->Left = pbxSpec->Left + (pbxSpec->Width - txtSpec->Width) / 2;
		}


		RawHand = gcnew array<Point>(pbxImp->Width);
		ResetHand();

		InvalidateAll();
	}
	System::Void UI::btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
		uiMainMenu->Visible = true;
		uiPreset->Visible = false;
		uiTrap->Visible = false;
		uiHand->Visible = false;
		uiGfx->Visible = false;
		uiGlobal->Visible = false;
		bDrawingMode = false;

		E_0 = E_0_def;
	}
	System::Void UI::btnPreset_Click(System::Object^  sender, System::EventArgs^  e)
	{
		PresetFuncChanged(sender, e);

		uiMainMenu->Visible = false;
		uiPreset->Visible = true;
		uiGfx->Visible = true;
		uiGlobal->Visible = true;
		uiGfx->BringToFront();
		uiGlobal->BringToFront();

		SpecXMult = 118;
		ImpXMult = 14;
		SpecYMult = 0.3125;
	}
	System::Void UI::btnTrap_Click(System::Object^  sender, System::EventArgs^  e)
	{
		buf[1].generate_rect();
		TrapWidthChanged(sender, e);

		uiMainMenu->Visible = false;
		uiTrap->Visible = true;
		uiGfx->Visible = true;
		uiGlobal->Visible = true;
		uiGfx->BringToFront();
		uiGlobal->BringToFront();

		SpecXMult = 118;
		ImpXMult = 14;
		SpecYMult = 0.3125;
	}
	System::Void UI::btnHand_Click(System::Object^  sender, System::EventArgs^  e) {
		buf[0].generate_null();
		buf[1].generate_null();
		btnReset_Click(sender, e);

		uiMainMenu->Visible = false;
		uiHand->Visible = true;
		uiGfx->Visible = true;
		uiGlobal->Visible = true;
		uiGfx->BringToFront();
		uiGlobal->BringToFront();
		bDrawingMode = true;

		SpecYMult = 0.125;
	}
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

	PointF UI::TransformImp(double x, double y, int index)
	{
		return PointF((float)((x / buf[index].len * ImpXMult - (ImpXMult - 1)*.5) * pbxImp->Width),
			(float)((1 - (y + 0.125) * 0.8) * pbxImp->Height));
	}
	PointF UI::TransformSpec(double x, double y, int index)
	{
		return PointF((float)((x / buf[index].len) * SpecXMult * pbxSpec->Width + 40),
			(float)((1 - (y * SpecYMult + 0.125) * 0.8) * pbxSpec->Height));
	}
	PointF UI::BackTransformImp(float x, float y, int index)
	{
		return PointF((float)((x / pbxImp->Width + (ImpXMult - 1)*.5) * buf[index].len / ImpXMult),
			(float)((1 - (y / pbxImp->Height)) / 0.8 - 0.125));
	}
	//		PointF UI::BackTransformSpec(float x, float y, int index)
	//		{
	//			return PointF((float)(x * buf[index].len / SpecXMult/ pbxSpec->Width),
	//				          (float)(((1 - (y / pbxSpec->Height))/ 0.8 - 0.125) * 8 * SpecYMult));
	//		}

	array<PointF>^ UI::TransformPointsImp(int index, PaintEventArgs^ e)
	{
		array<PointF>^ res = gcnew array<PointF>(buf[index].len);
		int i;
		for (i = 0; i<buf[index].len; i++)
		{
			res[i] = TransformImp(i, buf[index].imp[i], index);
			if (res[i].X > pbxImp->Width) break;
		}
		if (i < buf[index].len) array<PointF>::Resize(res, i);
		return res;
	}
	array<PointF>^ UI::TransformPointsSpec(int index, PaintEventArgs^ e)
	{
		register int speclen = buf[index].len / 2 + 1;
		array<PointF>^ res = gcnew array<PointF>(speclen);
		int i;
		for (i = 0; i<speclen; i++)
		{
			res[i] = TransformSpec(i, buf[index].spec[i], index);
			if (res[i].X > pbxSpec->Width) break;
		}
		if (i < buf[index].len) array<PointF>::Resize(res, i);
		return res;
	}


	void UI::DrawImp(PaintEventArgs^ e)
	{
		float YAxis = 40.0f;

		e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

		// Draw frame
		e->Graphics->DrawLine(FramePen, 0, 0, pbxImp->Width - 1, 0);
		e->Graphics->DrawLine(FramePen, 0, pbxImp->Height - 1, pbxImp->Width - 1, pbxImp->Height - 1);
		e->Graphics->DrawLine(FramePen, 0, 0, 0, pbxImp->Height - 1);
		e->Graphics->DrawLine(FramePen, pbxImp->Width - 1, 0, pbxImp->Width - 1, pbxImp->Height - 1);
		// Draw axes
		PointF p;
		for (int i = -10; i < 10; ++i)
		{
			p = TransformImp(buf[0].len / 2 + i * PointsPerSecond, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X, p.Y + 3, p.X, p.Y + 15);
			sprintf(textbuffer, "%d", i);
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 15, p.Y + 15);
		}
		p = TransformImp(0, 1, 0);
		e->Graphics->DrawLine(AxisPen, YAxis, p.Y, YAxis - 12, p.Y);
		sprintf(textbuffer, "%d", 1);
		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, YAxis - 42, p.Y - 15);

		p = TransformImp(buf[0].len / 2, 0, 0);
		e->Graphics->DrawLine(AxisPen, p.X - 2000, p.Y + 3, p.X + 2000, p.Y + 3);
		e->Graphics->DrawLine(AxisPen, YAxis, p.Y - 2000, YAxis, p.Y + 2000);

		if (!bDrawingMode)
		{
			array<PointF>^ curvePoints = TransformPointsImp(0, e);
			//e->Graphics->DrawCurve(GreenPen, curvePoints, 0, curvePoints->Length-1, .5F);
			e->Graphics->DrawLines(GreenPen, curvePoints);
			curvePoints = TransformPointsImp(1, e);
			//e->Graphics->DrawCurve(RedPen, curvePoints, 0, curvePoints->Length-1, .5F);
			e->Graphics->DrawLines(RedPen, curvePoints);
		}
		else
		{
			e->Graphics->FillEllipse(
				GreenPen->Brush,
				Start.X - Radius - GreenPen->Width / 2, Start.Y - Radius - GreenPen->Width / 2,
				Radius * 2, Radius * 2);
			e->Graphics->FillEllipse(
				GreenPen->Brush,
				Finish.X - Radius - GreenPen->Width / 2, Finish.Y - Radius - GreenPen->Width / 2,
				Radius * 2, Radius * 2);
			e->Graphics->DrawLines(GreenPen, RawHand);
		}

		sprintf(textbuffer, "t, с");
		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, pbxImp->Width - 80, p.Y + 10);

	}
	void UI::DrawSpec(PaintEventArgs^ e)
	{
		PointF p;
		e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

		if (uiHand->Visible)
		{
			if (int t = Math::Max(buf[0].SpecWidth, buf[1].SpecWidth)) SpecXMult = .9 * buf[0].len / t;
		}

		// Draw frame
		e->Graphics->DrawLine(FramePen, 0, 0, pbxSpec->Width - 1, 0);
		e->Graphics->DrawLine(FramePen, 0, pbxSpec->Height - 1, pbxSpec->Width - 1, pbxSpec->Height - 1);
		e->Graphics->DrawLine(FramePen, 0, 0, 0, pbxSpec->Height - 1);
		e->Graphics->DrawLine(FramePen, pbxSpec->Width - 1, 0, pbxSpec->Width - 1, pbxSpec->Height - 1);
		// Draw axes
		for (int i = 0; i < 20; ++i)
		{
			p = TransformSpec(i * buf[0].len / PointsPerSecond, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X, p.Y + 3, p.X, p.Y + 15);
			sprintf(textbuffer, "%d", i);
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 15, p.Y + 15);
		}
		p = TransformSpec(0, 0, 0);
		e->Graphics->DrawLine(AxisPen, p.X - 2, p.Y + 3, p.X + 4000, p.Y + 3);
		e->Graphics->DrawLine(AxisPen, p.X - 2, p.Y - 4000, p.X - 2, p.Y);

		for (int i = 0; i < 10; ++i)
		{
			p = TransformSpec(0, i, 0);
			e->Graphics->DrawLine(AxisPen, p.X - 2, p.Y, p.X - 15, p.Y);
			sprintf(textbuffer, "%d", i);
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 42, p.Y - 15);
		}

		array<PointF>^ curvePoints = TransformPointsSpec(0, e);
		//e->Graphics->DrawCurve(GreenPen, curvePoints, 0, curvePoints->Length-1, .5F);
		e->Graphics->DrawLines(GreenPen, curvePoints);
		curvePoints = TransformPointsSpec(1, e);
		//e->Graphics->DrawCurve(RedPen, curvePoints, 0, curvePoints->Length-1, .5F);
		e->Graphics->DrawLines(RedPen, curvePoints);

		p = TransformSpec(buf[0].SpecWidth, 0, 0);
		e->Graphics->DrawLine(GreenPen, p.X, p.Y - 2000, p.X, p.Y + 15);
		p = TransformSpec(buf[1].SpecWidth, 0, 0);
		e->Graphics->DrawLine(RedPen, p.X, p.Y - 2000, p.X, p.Y + 15);

		sprintf(textbuffer, "f, Гц");
		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, pbxImp->Width - 100, p.Y + 10);


		float RealSpecWidth[2];
		RealSpecWidth[0] = buf[0].SpecWidth * PointsPerSecond / buf[0].len + .01;
		RealSpecWidth[1] = buf[1].SpecWidth * PointsPerSecond / buf[1].len + .01;


		sprintf(textbuffer, "%.2f Гц", RealSpecWidth[0]);
		lblSpecWidth1->Text = gcnew String(textbuffer);
		sprintf(textbuffer, "%.2f Гц", RealSpecWidth[1]);
		lblSpecWidth2->Text = gcnew String(textbuffer);



		sprintf(textbuffer, "%.2f", RealSpecWidth[0] * E_0 / PointsPerSecond);
		lblC1->Text = gcnew String(textbuffer);

		sprintf(textbuffer, "%.2f", RealSpecWidth[1] * E_0 / PointsPerSecond);
		lblC2->Text = gcnew String(textbuffer);
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


	System::Void UI::EnableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 PointF t = BackTransformImp(e->X, e->Y, 0);
			 std::cout << "Click " << t.X << ", " << t.Y << "\n";

			 if (pow(e->X - Start.X, 2) + pow(e->Y - Start.Y, 2) > pow(Radius, 2))
				 return;

			 std::cout << "EnableDrawing " << bDrawingMode << "\n";
			 bDrawing = true;
		 }
	System::Void UI::DisableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 std::cout << "DisableDrawing " << bDrawingMode << "\n";
			 bDrawing = false;
			 last = def;

			 //			for(int i = 2; i < RawHand->Length-2; ++i)
			 //			{
			 //				RawHand[i].Y = (RawHand[i].Y + 0.6*(RawHand[i-1].Y+RawHand[i+1].Y)+ 0.1*(RawHand[i-2].Y+RawHand[i+2].Y))/2.4;
			 //			}
		 }
	System::Void UI::HandDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		 {
			 if (!bDrawingMode || !bDrawing)
				 return;

			 Point Mouse = e->Location;

			 //			const int idx = (int)rdb2->Checked;
			 int idx = 0; //

			 if (Mouse.X < 0 || Mouse.X >= RawHand->Length)
			 {
				 DisableDrawing(sender, e);
				 return;
			 }

			 if (Mouse.X < last.X)
				 Mouse.X = last.X;

			 if (last == def)
				 last = Mouse;

			 int beg = Math::Min(last.X, Mouse.X);
			 int end = Math::Max(last.X, Mouse.X);
			 int bas = Math::Min(last.Y, Mouse.Y);

			 //			for(int i = beg; i <=end; ++i)
			 //			{
			 //				//RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-last.X+1)/(Mouse.X-last.X+1);
			 //				RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-beg+1)/(end-beg+1);
			 //			}

			 for (int i = last.X; i <= Mouse.X; ++i)
			 {
				 //RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-last.X+1)/(Mouse.X-last.X+1);
				 RawHand[i].Y = last.Y + ((float)Mouse.Y - last.Y)*(i - beg + 1) / (end - beg + 1);
			 }
			 // Если влево рисовать нельзя, этот цикл не нужен
			 for (int i = Mouse.X; i <= last.X; ++i)
			 {
				 //RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-last.X+1)/(Mouse.X-last.X+1);
				 RawHand[i].Y = Mouse.Y + ((float)last.Y - Mouse.Y)*(i - beg + 1) / (end - beg + 1);
			 }

			 last = Mouse;
			 Start = Mouse;

			 for (int i = Start.X + 1; i < Finish.X; ++i)
			 {
				 RawHand[i].Y = Start.Y + (Finish.Y - Start.Y)*(i - Start.X) / (Finish.X - Start.X);
			 }

			 // Если довели до конца
			 if (pow(Start.X - Finish.X, 2) + pow(Start.Y - Finish.Y, 2) < pow(Radius*1.5, 2))
			 {
				 bDrawingMode = false;
				 FinalizeHand();
			 }
			 else if (Start.X > Finish.X)
			 {
				 // Плохой рисунок
				 bDrawingMode = false;
				 ShowMessage(gcnew String("Закончить график нужно \n в правом кружке."));
				 btnReset_Click(sender, e);
			 }

			 pbxImp->Invalidate();
		 }

	System::Void UI::ResetHand()
		 {
			 PointF t = TransformImp(0, 0, 0);
			 for (int i = 0; i < RawHand->Length; ++i)
			 {
				 RawHand[i].X = i;
				 RawHand[i].Y = t.Y;
			 }
			 Start = TransformImp(StartDef.X, StartDef.Y, 0);
			 Finish = TransformImp(FinishDef.X, FinishDef.Y, 0);
		 }
	System::Void UI::btnReset_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 ResetHand();
			 buf[0].generate_null();
			 buf[1].generate_null();
			 bDrawingMode = true;
			 InvalidateAll();


			 ShowMessage(gcnew String("Возьмите левый кружок и\nнарисуйте им график импульса.\nЗакончить график нужно\nв правом кружке."));
		 }
	void UI::FinalizeHand()
		 {
			 std::cout << "Finalize\n";
			 //RawHand
			 array<PointF> ^temp = gcnew array<PointF>(RawHand->Length);
			 for (int i = 0; i < temp->Length; ++i)
			 {
				 temp[i] = BackTransformImp(RawHand[i].X, RawHand[i].Y, 0);
			 }
			 for (int i = 1; i < temp->Length; ++i)
			 {
				 for (int j = temp[i - 1].X + 1; j <= temp[i].X; ++j)
				 {
					 buf[0].imp[j] = Interpolate(temp[i - 1].Y, temp[i].Y, (j - temp[i - 1].X) / (temp[i].X - temp[i - 1].X));
				 }
			 }

			 float t = 0, te;
			 for (int i = 0; i < buf[0].len; ++i) t += buf[0].imp[i] * buf[0].imp[i];
			 std::cout << t << "\n";
			 //te = E_0;
			 E_0 = t; // Больше говнокода богу говнокода!
			 buf[1].generate_rect();
			 //E_0 = te; // Зато работает

			 buf[0].fourier();
			 InvalidateAll();
		 }

	System::Void UI::ShowMessage(String ^msg)
	{
		lblMessage->Text = msg;
		lblMessage->Visible = true;
		MsgTime = 0;
		tmrMessage->Enabled = true;
	}

	System::Void UI::tmrMessage_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		MsgTime++;
		if (MsgTime > 60)
		{
			lblMessage->Visible = false;
			tmrMessage->Enabled = false;
		}
	}
	System::Void UI::btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

}