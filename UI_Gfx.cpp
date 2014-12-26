#include "UI.h"

namespace Spectre {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	PointF UI::TransformImp(double x, double y, int index)
	{
		return PointF((float)((x / buf[index].len * ImpXMult - (ImpXMult - 1)*.5) * pbxImp->Width),
			(float)((1 - (y + 0.125) * 0.8) * pbxImp->Height));
	}
	PointF UI::TransformSpec(double x, double y, int index)
	{
		return PointF((float)((x / buf[index].len) * SpecXMult * pbxSpec->Width + YAxis),
			(float)((1 - (y * SpecYMult + 0.125) * 0.8) * pbxSpec->Height));
	}
	PointF UI::BackTransformImp(float x, float y, int index)
	{
		return PointF((float)((x / pbxImp->Width + (ImpXMult - 1)*.5) * buf[index].len / ImpXMult),
			(float)((1 - (y / pbxImp->Height)) / 0.8 - 0.125));
	}
	PointF UI::BackTransformSpec(float x, float y, int index)
	{
		return PointF((float)((x - YAxis) * buf[index].len / (SpecXMult * pbxSpec->Width)),
			(float)(((1 - y / pbxSpec->Height) / 0.8 - 0.125) / SpecYMult));
	}

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
			if (!i) continue;

			p = TransformImp(buf[0].len / 2 + i * PointsPerSecond, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X, p.Y, p.X, p.Y + 15);
			sprintf(textbuffer, "%d", i);
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 15, p.Y + 15);
		}
		p = TransformImp(buf[0].len / 2, 1, 0);
//		e->Graphics->DrawLine(AxisPen, YAxis, p.Y, YAxis - 12, p.Y);
		e->Graphics->DrawLine(AxisPen, p.X, p.Y, p.X - 12, p.Y);
		sprintf(textbuffer, "%d", 1);
//		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, YAxis - 42, p.Y - 15);
		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 42, p.Y - 40);

		e->Graphics->DrawLine(AxisPen, p.X, p.Y - 2000, p.X, p.Y + 2000);
		p = TransformImp(buf[0].len / 2, 0, 0);
		e->Graphics->DrawLine(AxisPen, p.X - 2000, p.Y, p.X + 2000, p.Y);
//		e->Graphics->DrawLine(AxisPen, YAxis, p.Y - 2000, YAxis, p.Y + 2000);

		if (!bDrawingMode)
		{
			array<PointF>^ curvePoints = TransformPointsImp(0, e);
			//e->Graphics->DrawCurve(SecondPen, curvePoints, 0, curvePoints->Length-1, .5F);
			e->Graphics->DrawLines(SecondPen, curvePoints);
			curvePoints = TransformPointsImp(1, e);
			//e->Graphics->DrawCurve(FirstPen, curvePoints, 0, curvePoints->Length-1, .5F);
			e->Graphics->DrawLines(FirstPen, curvePoints);
		}
		else
		{
			e->Graphics->FillEllipse(
				SecondPen->Brush,
				Start.X - Radius - SecondPen->Width / 2, Start.Y - Radius - SecondPen->Width / 2,
				Radius * 2, Radius * 2);
			e->Graphics->FillEllipse(
				SecondPen->Brush,
				Finish.X - Radius - SecondPen->Width / 2, Finish.Y - Radius - SecondPen->Width / 2,
				Radius * 2, Radius * 2);
			e->Graphics->DrawLines(SecondPen, RawHand);
		}

		sprintf(textbuffer, "t, ñ");
		//		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, pbxImp->Width - 80, p.Y + 10);

	}
	void UI::DrawSpec(PaintEventArgs^ e)
	{
		PointF p;
		e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

		if (uiHand->Visible)
		{
			double t;
			t = Math::Max(buf[0].SpecWidth, buf[1].SpecWidth);
			if (t != 0) SpecXMult = .75 * buf[0].len / t;
			t = Math::Max(buf[0].MaxSpec, buf[1].MaxSpec);
			if (t != 0) SpecYMult = 1.0 / t;

			std::cout << "MaxSpec " << buf[0].MaxSpec << ' ' << buf[1].MaxSpec << '\n';
			std::cout << "        " << t << ' ' << SpecYMult << '\n';
		}

		// Draw frame
		e->Graphics->DrawLine(FramePen, 0, 0, pbxSpec->Width - 1, 0);
		e->Graphics->DrawLine(FramePen, 0, pbxSpec->Height - 1, pbxSpec->Width - 1, pbxSpec->Height - 1);
		e->Graphics->DrawLine(FramePen, 0, 0, 0, pbxSpec->Height - 1);
		e->Graphics->DrawLine(FramePen, pbxSpec->Width - 1, 0, pbxSpec->Width - 1, pbxSpec->Height - 1);
		// Draw axes
		p = BackTransformSpec(pbxSpec->Width , 0, 0);
		int GridStep = (p.X * PointsPerSecond / buf[0].len + 5) * 0.1;
		if (GridStep < 1) GridStep = 1;

		for (int i = 0; i < 15; ++i)
		{
			p = TransformSpec(i * GridStep * buf[0].len / PointsPerSecond, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X, p.Y, p.X, p.Y + 15);
			sprintf(textbuffer, "%d", i * GridStep);
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 15, p.Y + 15);
		}
		p = TransformSpec(0, 0, 0);
		e->Graphics->DrawLine(AxisPen, p.X, p.Y, p.X + 4000, p.Y);
		e->Graphics->DrawLine(AxisPen, p.X, p.Y - 4000, p.X, p.Y);

		for (int i = 0; i < 10; ++i)
		{
			p = TransformSpec(0, i, 0);
			e->Graphics->DrawLine(AxisPen, p.X, p.Y, p.X - 15, p.Y);
			//sprintf(textbuffer, "%d", i);
			//e->Graphics->DrawString(gcnew String(textbuffer), font, brush, p.X - 42, p.Y - 15);
		}

		array<PointF>^ curvePoints = TransformPointsSpec(0, e);
		//e->Graphics->DrawCurve(SecondPen, curvePoints, 0, curvePoints->Length-1, .5F);
		e->Graphics->DrawLines(SecondPen, curvePoints);
		curvePoints = TransformPointsSpec(1, e);
		//e->Graphics->DrawCurve(FirstPen, curvePoints, 0, curvePoints->Length-1, .5F);
		e->Graphics->DrawLines(FirstPen, curvePoints);

		p = TransformSpec(buf[0].SpecWidth, 0, 0);
		e->Graphics->DrawLine(_SecondPen, p.X, p.Y - 2000, p.X, p.Y + 15);
		p = TransformSpec(buf[1].SpecWidth, 0, 0);
		e->Graphics->DrawLine(_FirstPen, p.X, p.Y - 2000, p.X, p.Y + 15);

		sprintf(textbuffer, "f, Ãö");
		//		e->Graphics->DrawString(gcnew String(textbuffer), font, brush, pbxImp->Width - 100, p.Y + 10);


		double RealSpecWidth[2];
		RealSpecWidth[0] = buf[0].SpecWidth * PointsPerSecond / buf[0].len + 0.005;
		RealSpecWidth[1] = buf[1].SpecWidth * PointsPerSecond / buf[1].len + 0.005;


		sprintf(textbuffer, "%.2f Ãö", RealSpecWidth[0]);
		lblSpecWidth1->Text = gcnew String(textbuffer);
		sprintf(textbuffer, "%.2f Ãö", RealSpecWidth[1]);
		lblSpecWidth2->Text = gcnew String(textbuffer);



//		sprintf(textbuffer, "%.1lf", RealSpecWidth[0] * buf[0].Energy / PointsPerSecond);
		sprintf(textbuffer, "%.2lf", 2.0 * ImpHalfWidth / PointsPerSecond * RealSpecWidth[0]);
		lblC1->Text = gcnew String(textbuffer);

//		sprintf(textbuffer, "%.1lf", RealSpecWidth[1] * buf[0].Energy / PointsPerSecond);
		sprintf(textbuffer, "%.2lf", 2.0 * ImpHalfWidth / PointsPerSecond * RealSpecWidth[1]);
		lblC2->Text = gcnew String(textbuffer);
	}
}