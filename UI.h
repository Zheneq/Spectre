#pragma once
#include "Fourier.h"
#include <iostream>
#include <vector>
#include <cmath>
extern std::vector<float> RawHand[2];

enum WMode
{
	MD_MainMenu,
	MD_Preset,
};

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
			ActiveMode = MD_MainMenu;
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
	private: System::Windows::Forms::Panel^  uiMainMenu;
	protected:
	private: System::Windows::Forms::Button^  btnPreset;
	private: System::Windows::Forms::Panel^  uiPreset;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  rdb2;
	private: System::Windows::Forms::RadioButton^  rdb1;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  rdbHand;
	private: System::Windows::Forms::RadioButton^  rdbFunc;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::PictureBox^  pbxSpec;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Panel^  pnlFunc;
	private: System::Windows::Forms::ComboBox^  cbxRight;
	private: System::Windows::Forms::ComboBox^  cbxLeft;
	private: System::Windows::Forms::PictureBox^  pbxImp;
	private: System::Windows::Forms::Label^  lblPreset;

	protected: 

















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
			this->uiMainMenu = (gcnew System::Windows::Forms::Panel());
			this->btnPreset = (gcnew System::Windows::Forms::Button());
			this->uiPreset = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rdb2 = (gcnew System::Windows::Forms::RadioButton());
			this->rdb1 = (gcnew System::Windows::Forms::RadioButton());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->rdbHand = (gcnew System::Windows::Forms::RadioButton());
			this->rdbFunc = (gcnew System::Windows::Forms::RadioButton());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->pbxSpec = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->pnlFunc = (gcnew System::Windows::Forms::Panel());
			this->cbxRight = (gcnew System::Windows::Forms::ComboBox());
			this->cbxLeft = (gcnew System::Windows::Forms::ComboBox());
			this->pbxImp = (gcnew System::Windows::Forms::PictureBox());
			this->lblPreset = (gcnew System::Windows::Forms::Label());
			this->uiMainMenu->SuspendLayout();
			this->uiPreset->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSpec))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->pnlFunc->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxImp))->BeginInit();
			this->SuspendLayout();
			// 
			// uiMainMenu
			// 
			this->uiMainMenu->BackColor = System::Drawing::SystemColors::ControlDark;
			this->uiMainMenu->Controls->Add(this->btnPreset);
			this->uiMainMenu->Location = System::Drawing::Point(221, 12);
			this->uiMainMenu->Name = L"uiMainMenu";
			this->uiMainMenu->Size = System::Drawing::Size(568, 294);
			this->uiMainMenu->TabIndex = 15;
			// 
			// btnPreset
			// 
			this->btnPreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnPreset->Location = System::Drawing::Point(85, 80);
			this->btnPreset->Name = L"btnPreset";
			this->btnPreset->Size = System::Drawing::Size(350, 60);
			this->btnPreset->TabIndex = 1;
			this->btnPreset->Text = L"Preset";
			this->btnPreset->UseVisualStyleBackColor = true;
			this->btnPreset->Click += gcnew System::EventHandler(this, &UI::btnPreset_Click);
			// 
			// uiPreset
			// 
			this->uiPreset->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->uiPreset->Controls->Add(this->lblPreset);
			this->uiPreset->Controls->Add(this->panel1);
			this->uiPreset->Controls->Add(this->trackBar3);
			this->uiPreset->Controls->Add(this->panel2);
			this->uiPreset->Controls->Add(this->trackBar2);
			this->uiPreset->Controls->Add(this->pbxSpec);
			this->uiPreset->Controls->Add(this->trackBar1);
			this->uiPreset->Controls->Add(this->pnlFunc);
			this->uiPreset->Controls->Add(this->pbxImp);
			this->uiPreset->Location = System::Drawing::Point(35, 51);
			this->uiPreset->Name = L"uiPreset";
			this->uiPreset->Size = System::Drawing::Size(919, 480);
			this->uiPreset->TabIndex = 16;
			this->uiPreset->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Controls->Add(this->rdb2);
			this->panel1->Controls->Add(this->rdb1);
			this->panel1->Location = System::Drawing::Point(10, 65);
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
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(13, 232);
			this->trackBar3->Maximum = 20;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(252, 45);
			this->trackBar3->TabIndex = 13;
			this->trackBar3->Value = 1;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel2->Controls->Add(this->rdbHand);
			this->panel2->Controls->Add(this->rdbFunc);
			this->panel2->Location = System::Drawing::Point(75, 65);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(158, 29);
			this->panel2->TabIndex = 5;
			this->panel2->Visible = false;
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
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(13, 181);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(252, 45);
			this->trackBar2->TabIndex = 12;
			this->trackBar2->Value = 50;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			// 
			// pbxSpec
			// 
			this->pbxSpec->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxSpec->Location = System::Drawing::Point(267, 288);
			this->pbxSpec->Name = L"pbxSpec";
			this->pbxSpec->Size = System::Drawing::Size(640, 214);
			this->pbxSpec->TabIndex = 7;
			this->pbxSpec->TabStop = false;
			this->pbxSpec->Click += gcnew System::EventHandler(this, &UI::onClick);
			this->pbxSpec->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UI::onSpecPaint);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(10, 130);
			this->trackBar1->Maximum = 32;
			this->trackBar1->Minimum = 8;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(255, 45);
			this->trackBar1->TabIndex = 11;
			this->trackBar1->Value = 8;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &UI::trackBar1_ValueChanged);
			// 
			// pnlFunc
			// 
			this->pnlFunc->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->pnlFunc->Controls->Add(this->cbxRight);
			this->pnlFunc->Controls->Add(this->cbxLeft);
			this->pnlFunc->Location = System::Drawing::Point(10, 102);
			this->pnlFunc->Name = L"pnlFunc";
			this->pnlFunc->Size = System::Drawing::Size(265, 29);
			this->pnlFunc->TabIndex = 10;
			this->pnlFunc->Visible = false;
			// 
			// cbxRight
			// 
			this->cbxRight->FormattingEnabled = true;
			this->cbxRight->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Разрыв", L"Линейная", L"Гаусс", L"Синус" });
			this->cbxRight->Location = System::Drawing::Point(130, 3);
			this->cbxRight->Name = L"cbxRight";
			this->cbxRight->Size = System::Drawing::Size(121, 21);
			this->cbxRight->TabIndex = 11;
			this->cbxRight->Text = L"Справа";
			// 
			// cbxLeft
			// 
			this->cbxLeft->FormattingEnabled = true;
			this->cbxLeft->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Разрыв", L"Линейная", L"Гаусс", L"Синус" });
			this->cbxLeft->Location = System::Drawing::Point(3, 3);
			this->cbxLeft->Name = L"cbxLeft";
			this->cbxLeft->Size = System::Drawing::Size(121, 21);
			this->cbxLeft->TabIndex = 10;
			this->cbxLeft->Text = L"Слева";
			// 
			// pbxImp
			// 
			this->pbxImp->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxImp->Location = System::Drawing::Point(267, 68);
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
			// lblPreset
			// 
			this->lblPreset->AutoSize = true;
			this->lblPreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblPreset->Location = System::Drawing::Point(13, 12);
			this->lblPreset->Name = L"lblPreset";
			this->lblPreset->Size = System::Drawing::Size(167, 37);
			this->lblPreset->TabIndex = 14;
			this->lblPreset->Text = L"Заголовок";
			this->lblPreset->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 534);
			this->Controls->Add(this->uiPreset);
			this->Controls->Add(this->uiMainMenu);
			this->Name = L"UI";
			this->Text = L"UI";
			this->Load += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->ResizeEnd += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->Resize += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->StyleChanged += gcnew System::EventHandler(this, &UI::AdaptToWindowSize);
			this->uiMainMenu->ResumeLayout(false);
			this->uiPreset->ResumeLayout(false);
			this->uiPreset->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSpec))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->pnlFunc->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxImp))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		bool bDrawing; // В данный момент рисуем мышкой (кнопка мыши нажата)
		Point def;
		Point last;
		WMode ActiveMode;
		
		System::Void AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e)
		{
			uiMainMenu->Left = 0;
			uiMainMenu->Top = 0;
			uiMainMenu->Width = ClientSize.Width;
			uiMainMenu->Height = ClientSize.Height;
			uiPreset->Left = 0;
			uiPreset->Top = 0;
			uiPreset->Width = ClientSize.Width;
			uiPreset->Height = ClientSize.Height;

			// uiMainMenu
			btnPreset->Left = (ClientSize.Width - btnPreset->Width) / 2;

			// uiPreset
			int Spacing = 10;

			lblPreset->Left = (ClientSize.Width - lblPreset->Width) / 2;

			int AwailableWidth  = ClientSize.Width  - pbxImp->Left - Spacing;
			int AwailableHeight = ClientSize.Height - pbxImp->Top  - Spacing * 2;
			
			pbxImp->Width = AwailableWidth;
			pbxSpec->Width = AwailableWidth;
			pbxImp->Height = AwailableHeight / 2;
			pbxSpec->Height = AwailableHeight / 2;

			pbxSpec->Left = pbxImp->Left;
			pbxSpec->Top  = pbxImp->Top + pbxImp->Height + Spacing;
			
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

		PointF TransformImp(double x, double y, int index)
		{
			return PointF((float)((x / buf[index].len * trackBar3->Value - (trackBar3->Value-1)*.5) * pbxImp->Width),
				          (float)((1 - (y + 0.125) * 0.8) * pbxImp->Height));
		}
		PointF TransformSpec(double x, double y, int index)
		{
			return PointF((float)(x / buf[index].len * trackBar2->Value * pbxSpec->Width),
				          (float)((1 - y / buf[0].MaxSpec) * pbxSpec->Height));
		}
		PointF BackTransformImp(float x, float y, int index)
		{
			return PointF((float)(x * buf[index].len / pbxImp->Width),
				          (float)((1 - (y / pbxImp->Height)) / 0.8 - 0.125));
		}
		PointF BackTransformSpec(float x, float y, int index)
		{
			return PointF((float)(x * buf[index].len / trackBar2->Value/ pbxSpec->Width),
				          (float)((1 - (y / pbxSpec->Height)) * buf[index].MaxSpec));
		}

		array<PointF>^ TransformPointsImp(int index, PaintEventArgs^ e)
		{
			array<PointF>^ res = gcnew array<PointF>(buf[index].len);
			int i;
			for(i=0; i<buf[index].len; i++)
			{
				res[i] = TransformImp(i, buf[index].imp[i], index);
				if (res[i].X > pbxImp->Width) break;
			}
			if (i < buf[index].len) array<PointF>::Resize(res, i);
			return res;
		}
		array<PointF>^ TransformPointsSpec(int index, PaintEventArgs^ e)
		{
			register int speclen = buf[index].len/2 + 1;
			array<PointF>^ res = gcnew array<PointF>(speclen);
			int i;
			for(i=0; i<speclen; i++)
			{
				res[i] = TransformSpec(i, buf[index].spec[i], index);
				if (res[i].X > pbxSpec->Width) break;
			}
			if (i < buf[index].len) array<PointF>::Resize(res, i);
			return res;
		}
		
		
		void DrawImp(PaintEventArgs^ e)
		{
			
			Pen^ RedPen = gcnew Pen( Color::Red, 1.0f );
			Pen^ GreenPen = gcnew Pen( Color::Green, 3.0f );
			Pen^ AxisPen = gcnew Pen( Color::Black, 1.0f );

			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			// Draw axes
			//e->Graphics->DrawLine(AxisPen, TransformImp(XRangeImp[0], 0), TransformImp(XRangeImp[1], 0));
			//e->Graphics->DrawLine(AxisPen, TransformImp(0, YRangeImp[0]), TransformImp(0, YRangeImp[1]));

			array<PointF>^ curvePoints = TransformPointsImp(0, e);
			//e->Graphics->DrawCurve(GreenPen, curvePoints, 0, buf[0].len-1, .5F);
			e->Graphics->DrawLines(GreenPen, curvePoints);
			curvePoints = TransformPointsImp(1, e);
			//e->Graphics->DrawCurve(RedPen, curvePoints, 0, buf[1].len-1, .5F);
			e->Graphics->DrawLines(RedPen, curvePoints);
		}
		void DrawSpec(PaintEventArgs^ e)
		{
			Pen^ RedPen = gcnew Pen( Color::Red,1.0f );
			Pen^ GreenPen = gcnew Pen( Color::Green, 3.0f );
			Pen^ AxisPen = gcnew Pen( Color::Black, 1.0f );

			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			// Draw axes
			//e->Graphics->DrawLine(AxisPen, TransformSpec(XRangeSpec[0], 0), TransformSpec(XRangeSpec[1], 0));
			//e->Graphics->DrawLine(AxisPen, TransformSpec(0, YRangeSpec[0]), TransformSpec(0, YRangeSpec[1]));

			array<PointF>^ curvePoints = TransformPointsSpec(0, e);
			//e->Graphics->DrawCurve(GreenPen, curvePoints, 0, buf[0].len/2, .5F);
			e->Graphics->DrawLines(GreenPen, curvePoints);
			curvePoints = TransformPointsSpec(1, e);
			//e->Graphics->DrawCurve(RedPen, curvePoints, 0, buf[1].len/2, .5F);
			e->Graphics->DrawLines(RedPen, curvePoints);
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
			RawHand[idx][e->X] = (float)e->Y;
			RefreshHand();
		}
		System::Void RefreshHand()
		{
			const int idx = (int)rdb2->Checked;
			for(int i=0; i<pbxImp->Width; ++i)
			{
				PointF t = BackTransformImp((float)i, RawHand[idx][i], idx);
				buf[idx].imp[i] = t.X;
				buf[idx].imp[i] = t.Y;
			}
			pbxImp->Invalidate();
		}

private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 E_0 = /*buf[0].len * .0*/15 * trackBar1->Value;
			 buf[0].generate_gauss(100);
			 buf[1].generate_rect();
			 InvalidateAll();
		 }
private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 InvalidateAll();
		 }
		System::Void btnPreset_Click(System::Object^  sender, System::EventArgs^  e)
		{
			uiMainMenu->Visible = false;
			uiPreset->Visible = true;
		}
};
}
