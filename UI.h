#pragma once
#include "Fourier.h"
#include <iostream>
#include <vector>
#include <cmath>
extern std::vector<float> RawHand[2];

namespace Spectre {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
	public:
		UI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			bDrawing = false;
			Point def = Point(-1,-1);
			Point last = def;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::RadioButton^  rdb2;
	private: System::Windows::Forms::RadioButton^  rdb1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  rdbHand;
	private: System::Windows::Forms::RadioButton^  rdbFunc;
	private: System::Windows::Forms::PictureBox^  pbxImp;
	private: System::Windows::Forms::PictureBox^  pbxSpec;
	private: System::Windows::Forms::Panel^  pnlFunc;

	private: System::Windows::Forms::ComboBox^  cbxRight;
	private: System::Windows::Forms::ComboBox^  cbxLeft;



	protected: 




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rdb2 = (gcnew System::Windows::Forms::RadioButton());
			this->rdb1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->rdbHand = (gcnew System::Windows::Forms::RadioButton());
			this->rdbFunc = (gcnew System::Windows::Forms::RadioButton());
			this->pbxImp = (gcnew System::Windows::Forms::PictureBox());
			this->pbxSpec = (gcnew System::Windows::Forms::PictureBox());
			this->pnlFunc = (gcnew System::Windows::Forms::Panel());
			this->cbxRight = (gcnew System::Windows::Forms::ComboBox());
			this->cbxLeft = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxImp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxSpec))->BeginInit();
			this->pnlFunc->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Controls->Add(this->rdb2);
			this->panel1->Controls->Add(this->rdb1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(59, 29);
			this->panel1->TabIndex = 4;
			// 
			// rdb2
			// 
			this->rdb2->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdb2->AutoSize = true;
			this->rdb2->Location = System::Drawing::Point(32, 3);
			this->rdb2->Name = L"rdb2";
			this->rdb2->Size = System::Drawing::Size(23, 23);
			this->rdb2->TabIndex = 3;
			this->rdb2->Tag = L"";
			this->rdb2->Text = L"2";
			this->rdb2->UseVisualStyleBackColor = true;
			// 
			// rdb1
			// 
			this->rdb1->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdb1->AutoSize = true;
			this->rdb1->Checked = true;
			this->rdb1->Location = System::Drawing::Point(3, 3);
			this->rdb1->Name = L"rdb1";
			this->rdb1->Size = System::Drawing::Size(23, 23);
			this->rdb1->TabIndex = 2;
			this->rdb1->TabStop = true;
			this->rdb1->Tag = L"";
			this->rdb1->Text = L"1";
			this->rdb1->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel2->Controls->Add(this->rdbHand);
			this->panel2->Controls->Add(this->rdbFunc);
			this->panel2->Location = System::Drawing::Point(77, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(158, 29);
			this->panel2->TabIndex = 5;
			// 
			// rdbHand
			// 
			this->rdbHand->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbHand->AutoSize = true;
			this->rdbHand->Location = System::Drawing::Point(72, 3);
			this->rdbHand->Name = L"rdbHand";
			this->rdbHand->Size = System::Drawing::Size(79, 23);
			this->rdbHand->TabIndex = 5;
			this->rdbHand->Tag = L"";
			this->rdbHand->Text = L"Ручной ввод";
			this->rdbHand->UseVisualStyleBackColor = true;
			this->rdbHand->CheckedChanged += gcnew System::EventHandler(this, &UI::HideFunc);
			// 
			// rdbFunc
			// 
			this->rdbFunc->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbFunc->AutoSize = true;
			this->rdbFunc->Checked = true;
			this->rdbFunc->Location = System::Drawing::Point(3, 3);
			this->rdbFunc->Name = L"rdbFunc";
			this->rdbFunc->Size = System::Drawing::Size(63, 23);
			this->rdbFunc->TabIndex = 4;
			this->rdbFunc->TabStop = true;
			this->rdbFunc->Tag = L"";
			this->rdbFunc->Text = L"Функция";
			this->rdbFunc->UseVisualStyleBackColor = true;
			// 
			// pbxImp
			// 
			this->pbxImp->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxImp->Location = System::Drawing::Point(15, 47);
			this->pbxImp->Name = L"pbxImp";
			this->pbxImp->Size = System::Drawing::Size(640, 214);
			this->pbxImp->TabIndex = 6;
			this->pbxImp->TabStop = false;
			this->pbxImp->Click += gcnew System::EventHandler(this, &UI::onClick);
			this->pbxImp->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UI::onImpPaint);
			this->pbxImp->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::EnableDrawing);
			this->pbxImp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::HandDrawing);
			this->pbxImp->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::DisableDrawing);
			// 
			// pbxSpec
			// 
			this->pbxSpec->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxSpec->Location = System::Drawing::Point(15, 267);
			this->pbxSpec->Name = L"pbxSpec";
			this->pbxSpec->Size = System::Drawing::Size(640, 214);
			this->pbxSpec->TabIndex = 7;
			this->pbxSpec->TabStop = false;
			this->pbxSpec->Click += gcnew System::EventHandler(this, &UI::onClick);
			this->pbxSpec->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UI::onSpecPaint);
			// 
			// pnlFunc
			// 
			this->pnlFunc->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->pnlFunc->Controls->Add(this->cbxRight);
			this->pnlFunc->Controls->Add(this->cbxLeft);
			this->pnlFunc->Location = System::Drawing::Point(241, 12);
			this->pnlFunc->Name = L"pnlFunc";
			this->pnlFunc->Size = System::Drawing::Size(265, 29);
			this->pnlFunc->TabIndex = 10;
			// 
			// cbxRight
			// 
			this->cbxRight->FormattingEnabled = true;
			this->cbxRight->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Разрыв", L"Линейная", L"Гаусс", L"Синус"});
			this->cbxRight->Location = System::Drawing::Point(130, 3);
			this->cbxRight->Name = L"cbxRight";
			this->cbxRight->Size = System::Drawing::Size(121, 21);
			this->cbxRight->TabIndex = 11;
			this->cbxRight->Text = L"Справа";
			this->cbxRight->SelectedIndexChanged += gcnew System::EventHandler(this, &UI::FuncChanged);
			// 
			// cbxLeft
			// 
			this->cbxLeft->FormattingEnabled = true;
			this->cbxLeft->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Разрыв", L"Линейная", L"Гаусс", L"Синус"});
			this->cbxLeft->Location = System::Drawing::Point(3, 3);
			this->cbxLeft->Name = L"cbxLeft";
			this->cbxLeft->Size = System::Drawing::Size(121, 21);
			this->cbxLeft->TabIndex = 10;
			this->cbxLeft->Text = L"Слева";
			this->cbxLeft->SelectedIndexChanged += gcnew System::EventHandler(this, &UI::FuncChanged);
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 502);
			this->Controls->Add(this->pnlFunc);
			this->Controls->Add(this->pbxSpec);
			this->Controls->Add(this->pbxImp);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"UI";
			this->Text = L"UI";
			this->Load += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->ResizeEnd += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->Resize += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->StyleChanged += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxImp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxSpec))->EndInit();
			this->pnlFunc->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		bool bDrawing; // В данный момент рисуем мышкой (кнопка мыши нажата)
		Point def;
		Point last;
		
		System::Void AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e)
		{
			int AwailableWidth  = ClientSize.Width - pbxImp->Left * 2;
			int AwailableHeight = ClientSize.Height - pbxImp->Top - pbxImp->Left;
			
			pbxImp->Width = AwailableWidth;
			pbxSpec->Width = AwailableWidth;
			pbxImp->Height = AwailableHeight / 2;
			pbxSpec->Height = AwailableHeight / 2;

			pbxSpec->Left = pbxImp->Left;
			pbxSpec->Top  = pbxImp->Top + pbxImp->Height + pbxImp->Left;
			
			RawHand[0].resize(pbxImp->Width, 0);
			RawHand[1].resize(pbxImp->Width, 0);

			InvalidateAll();
		}
		System::Void InvalidateAll()
		{
			pbxImp->Invalidate();
			pbxSpec->Invalidate();
		}
		System::Void HideFunc(System::Object^  sender, System::EventArgs^  e) {
			pnlFunc->Visible = rdbFunc->Checked;
		}
		
		System::Void onClick(System::Object^  sender, System::EventArgs^  e)
		{
			InvalidateAll();
		}
		System::Void onImpPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
			DrawImp(e);
		}
		System::Void onSpecPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
			DrawSpec(e);
		}

		PointF TransformImp(double x, double y)
		{
			return PointF((float)((x - XRangeImp[0]) * XScaleImp * pbxImp->Width),
				          (float)((1 - (y - YRangeImp[0]) * YScaleImp) * pbxImp->Height));
		}
		PointF TransformSpec(double x, double y)
		{
			return PointF((float)((x - XRangeSpec[0]) * XScaleSpec * pbxSpec->Width),
				          (float)((1 - (y - YRangeSpec[0]) * YScaleSpec) * pbxSpec->Height));
		}
		PointF BackTransformImp(float x, float y)
		{
			return PointF((float)(x / (XScaleImp * pbxImp->Width) + XRangeImp[0]),
				          (float)((1 - (y / pbxImp->Height)) / YScaleImp + YRangeImp[0]));
		}
		PointF BackTransformSpec(float x, float y)
		{
			return PointF((float)(x / (XScaleSpec * pbxSpec->Width) + XRangeSpec[0]),
				          (float)((1 - (y / pbxSpec->Height)) / YScaleSpec + YRangeSpec[0]));
		}

		array<PointF>^ TransformPointsImp(int index, PaintEventArgs^ e)
		{
			array<PointF>^ res = gcnew array<PointF>(implen);
			for(int i=0; i<implen; i++)
			{
				res[i] = TransformImp(imp[index][0][i], imp[index][1][i]);
			}
			return res;
		}
		array<PointF>^ TransformPointsSpec(int index, PaintEventArgs^ e)
		{
			array<PointF>^ res = gcnew array<PointF>(speclen);
			for(int i=0; i<speclen; i++)
			{
				res[i] = TransformSpec(spec[index][0][i], spec[index][1][i]);
			}
			return res;
		}
		
		
		void DrawImp(PaintEventArgs^ e)
		{
			
			Pen^ RedPen = gcnew Pen( Color::Red,3.0f );
			Pen^ GreenPen = gcnew Pen( Color::Green, 2.0f );
			Pen^ AxisPen = gcnew Pen( Color::Black, 1.0f );

			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			// Draw axes
			e->Graphics->DrawLine(AxisPen, TransformImp(XRangeImp[0], 0), TransformImp(XRangeImp[1], 0));
			e->Graphics->DrawLine(AxisPen, TransformImp(0, YRangeImp[0]), TransformImp(0, YRangeImp[1]));

			array<PointF>^ curvePoints = TransformPointsImp(0, e);
			e->Graphics->DrawCurve(GreenPen, curvePoints, 0, implen-1, .5F);
			curvePoints = TransformPointsImp(1, e);
			e->Graphics->DrawCurve(RedPen, curvePoints, 0, implen-1, .5F);
		}
		void DrawSpec(PaintEventArgs^ e)
		{
			Pen^ RedPen = gcnew Pen( Color::Red,3.0f );
			Pen^ GreenPen = gcnew Pen( Color::Green, 2.0f );
			Pen^ AxisPen = gcnew Pen( Color::Black, 1.0f );

			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			// Draw axes
			e->Graphics->DrawLine(AxisPen, TransformSpec(XRangeSpec[0], 0), TransformSpec(XRangeSpec[1], 0));
			e->Graphics->DrawLine(AxisPen, TransformSpec(0, YRangeSpec[0]), TransformSpec(0, YRangeSpec[1]));

			array<PointF>^ curvePoints = TransformPointsSpec(0, e);
			e->Graphics->DrawCurve(GreenPen, curvePoints, 0, implen-1, .5F);
			curvePoints = TransformPointsSpec(1, e);
			e->Graphics->DrawCurve(RedPen, curvePoints, 0, implen-1, .5F);
		}

		System::Void FuncChanged(System::Object^  sender, System::EventArgs^  e)
		{
			/*
			if(cbxLeft->SelectedIndex >= 0 || cbxRight->SelectedIndex >= 0)
				Fourier::function((int)rdb2->Checked, cbxLeft->SelectedIndex + 1, cbxRight->SelectedIndex + 1);
			//*/
			std::cout << (int)rdb2->Checked << ' ' << cbxLeft->SelectedIndex << ' ' << cbxRight->SelectedIndex << std::endl;
		}

		

		System::Void EnableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			bDrawing = true;
		}
		System::Void DisableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			bDrawing = false;
		}

		System::Void HandDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			if(!rdbHand->Checked || !bDrawing)
				return;
			
			const int idx = (int)rdb2->Checked;
/*		
			if(last == def) last = e->Location;

			int beg = Math::Min(last.X, e->X);
			int end = Math::Max(last.X, e->X);
			for(int i = beg; i <=end; ++i)
			{
				RawHand[idx][i] = last.Y + ((float)e->Y-last.Y)*(i-beg+1)/(end-beg+1);
			}
*/
			RawHand[idx][e->X] = e->Y;
			RefreshHand();
		}
		System::Void RefreshHand()
		{
			const int idx = (int)rdb2->Checked;
			for(int i=0; i<pbxImp->Width; ++i)
			{
				PointF t = BackTransformImp((float)i, RawHand[idx][i]);
				imp[idx][0][i] = t.X;
				imp[idx][1][i] = t.Y;
			}
			pbxImp->Invalidate();
		}
};
}
