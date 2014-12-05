#include "UI.h"

namespace Spectre {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			ShowMessage(gcnew String("Закончить график нужно \n в правом кружке."), true);
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

		ShowMessage(gcnew String("Возьмите левый кружок и\nнарисуйте им график импульса.\nЗакончить график нужно\nв правом кружке."), false);
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

}