#pragma once
#include "Fourier.h"
#include <iostream>
#include <vector>
#include <cmath>
extern std::vector<float> RawHand[2];
extern float PointsPerSecond;
extern char textbuffer[512];

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


			RedPen = gcnew Pen(Color::Red, 1.0f);
			GreenPen = gcnew Pen(Color::Green, 3.0f);
			AxisPen = gcnew Pen(Color::Black, 3.0f);
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




	private: System::Windows::Forms::TrackBar^  trackBar3;



	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::PictureBox^  pbxSpec;
	private: System::Windows::Forms::TrackBar^  trackBar1;



	private: System::Windows::Forms::PictureBox^  pbxImp;
	private: System::Windows::Forms::Label^  lblPreset;
	private: System::Windows::Forms::Panel^  uiGfx;
	private: System::Windows::Forms::Panel^  panPresetControl;
	private: System::Windows::Forms::Panel^  panPresetControl2;

	private: System::Windows::Forms::RadioButton^  rdbPreset24;
	private: System::Windows::Forms::RadioButton^  rdbPreset23;
	private: System::Windows::Forms::RadioButton^  rdbPreset22;
	private: System::Windows::Forms::RadioButton^  rdbPreset21;
	private: System::Windows::Forms::Panel^  panPresetControl1;

	private: System::Windows::Forms::RadioButton^  rdbPreset14;
	private: System::Windows::Forms::RadioButton^  rdbPreset13;
	private: System::Windows::Forms::RadioButton^  rdbPreset12;
	private: System::Windows::Forms::RadioButton^  rdbPreset11;
	private: System::Windows::Forms::Button^  btnTrap;
	private: System::Windows::Forms::Panel^  uiTrap;
	private: System::Windows::Forms::Label^  lblTrap;
	private: System::Windows::Forms::TrackBar^  trbTrap;
	private: System::Windows::Forms::Button^  btnBack;
	private: System::Windows::Forms::Panel^  uiGlobal;
	private: System::Windows::Forms::Label^  lblSpecWidth2;
	private: System::Windows::Forms::Label^  lblSpecWidth1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;

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
			this->btnTrap = (gcnew System::Windows::Forms::Button());
			this->btnPreset = (gcnew System::Windows::Forms::Button());
			this->uiPreset = (gcnew System::Windows::Forms::Panel());
			this->panPresetControl = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panPresetControl2 = (gcnew System::Windows::Forms::Panel());
			this->rdbPreset24 = (gcnew System::Windows::Forms::RadioButton());
			this->rdbPreset23 = (gcnew System::Windows::Forms::RadioButton());
			this->rdbPreset22 = (gcnew System::Windows::Forms::RadioButton());
			this->rdbPreset21 = (gcnew System::Windows::Forms::RadioButton());
			this->panPresetControl1 = (gcnew System::Windows::Forms::Panel());
			this->rdbPreset14 = (gcnew System::Windows::Forms::RadioButton());
			this->rdbPreset13 = (gcnew System::Windows::Forms::RadioButton());
			this->rdbPreset12 = (gcnew System::Windows::Forms::RadioButton());
			this->rdbPreset11 = (gcnew System::Windows::Forms::RadioButton());
			this->lblPreset = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->pbxSpec = (gcnew System::Windows::Forms::PictureBox());
			this->pbxImp = (gcnew System::Windows::Forms::PictureBox());
			this->uiGfx = (gcnew System::Windows::Forms::Panel());
			this->uiTrap = (gcnew System::Windows::Forms::Panel());
			this->lblTrap = (gcnew System::Windows::Forms::Label());
			this->trbTrap = (gcnew System::Windows::Forms::TrackBar());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->uiGlobal = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblSpecWidth2 = (gcnew System::Windows::Forms::Label());
			this->lblSpecWidth1 = (gcnew System::Windows::Forms::Label());
			this->uiMainMenu->SuspendLayout();
			this->uiPreset->SuspendLayout();
			this->panPresetControl->SuspendLayout();
			this->panPresetControl2->SuspendLayout();
			this->panPresetControl1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxSpec))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxImp))->BeginInit();
			this->uiGfx->SuspendLayout();
			this->uiTrap->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbTrap))->BeginInit();
			this->uiGlobal->SuspendLayout();
			this->SuspendLayout();
			// 
			// uiMainMenu
			// 
			this->uiMainMenu->BackColor = System::Drawing::SystemColors::ControlDark;
			this->uiMainMenu->Controls->Add(this->btnTrap);
			this->uiMainMenu->Controls->Add(this->btnPreset);
			this->uiMainMenu->Location = System::Drawing::Point(45, 12);
			this->uiMainMenu->Name = L"uiMainMenu";
			this->uiMainMenu->Size = System::Drawing::Size(364, 296);
			this->uiMainMenu->TabIndex = 15;
			// 
			// btnTrap
			// 
			this->btnTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnTrap->Location = System::Drawing::Point(3, 69);
			this->btnTrap->Name = L"btnTrap";
			this->btnTrap->Size = System::Drawing::Size(350, 60);
			this->btnTrap->TabIndex = 2;
			this->btnTrap->Text = L"Trapezoid";
			this->btnTrap->UseVisualStyleBackColor = true;
			this->btnTrap->Click += gcnew System::EventHandler(this, &UI::btnTrap_Click);
			// 
			// btnPreset
			// 
			this->btnPreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnPreset->Location = System::Drawing::Point(3, 3);
			this->btnPreset->Name = L"btnPreset";
			this->btnPreset->Size = System::Drawing::Size(350, 60);
			this->btnPreset->TabIndex = 1;
			this->btnPreset->Text = L"Preset";
			this->btnPreset->UseVisualStyleBackColor = true;
			this->btnPreset->Click += gcnew System::EventHandler(this, &UI::btnPreset_Click);
			// 
			// uiPreset
			// 
			this->uiPreset->BackColor = System::Drawing::Color::Gray;
			this->uiPreset->Controls->Add(this->panPresetControl);
			this->uiPreset->Controls->Add(this->lblPreset);
			this->uiPreset->Controls->Add(this->trackBar1);
			this->uiPreset->Location = System::Drawing::Point(426, 15);
			this->uiPreset->Name = L"uiPreset";
			this->uiPreset->Size = System::Drawing::Size(398, 427);
			this->uiPreset->TabIndex = 16;
			this->uiPreset->Visible = false;
			// 
			// panPresetControl
			// 
			this->panPresetControl->BackColor = System::Drawing::Color::Silver;
			this->panPresetControl->Controls->Add(this->label7);
			this->panPresetControl->Controls->Add(this->label6);
			this->panPresetControl->Controls->Add(this->label5);
			this->panPresetControl->Controls->Add(this->label4);
			this->panPresetControl->Controls->Add(this->panPresetControl2);
			this->panPresetControl->Controls->Add(this->panPresetControl1);
			this->panPresetControl->Location = System::Drawing::Point(20, 181);
			this->panPresetControl->Name = L"panPresetControl";
			this->panPresetControl->Size = System::Drawing::Size(245, 224);
			this->panPresetControl->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(43, 67);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Треугольник";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(43, 48);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Косинус";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(43, 86);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Прямоугольник";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(43, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Гаусс";
			// 
			// panPresetControl2
			// 
			this->panPresetControl2->BackColor = System::Drawing::Color::DarkOrange;
			this->panPresetControl2->Controls->Add(this->rdbPreset24);
			this->panPresetControl2->Controls->Add(this->rdbPreset23);
			this->panPresetControl2->Controls->Add(this->rdbPreset22);
			this->panPresetControl2->Controls->Add(this->rdbPreset21);
			this->panPresetControl2->Location = System::Drawing::Point(186, 29);
			this->panPresetControl2->Name = L"panPresetControl2";
			this->panPresetControl2->Size = System::Drawing::Size(29, 139);
			this->panPresetControl2->TabIndex = 1;
			// 
			// rdbPreset24
			// 
			this->rdbPreset24->AutoSize = true;
			this->rdbPreset24->Location = System::Drawing::Point(0, 57);
			this->rdbPreset24->Name = L"rdbPreset24";
			this->rdbPreset24->Size = System::Drawing::Size(14, 13);
			this->rdbPreset24->TabIndex = 8;
			this->rdbPreset24->UseVisualStyleBackColor = true;
			this->rdbPreset24->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset23
			// 
			this->rdbPreset23->AutoSize = true;
			this->rdbPreset23->Location = System::Drawing::Point(0, 38);
			this->rdbPreset23->Name = L"rdbPreset23";
			this->rdbPreset23->Size = System::Drawing::Size(14, 13);
			this->rdbPreset23->TabIndex = 7;
			this->rdbPreset23->UseVisualStyleBackColor = true;
			this->rdbPreset23->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset22
			// 
			this->rdbPreset22->AutoSize = true;
			this->rdbPreset22->Location = System::Drawing::Point(0, 19);
			this->rdbPreset22->Name = L"rdbPreset22";
			this->rdbPreset22->Size = System::Drawing::Size(14, 13);
			this->rdbPreset22->TabIndex = 6;
			this->rdbPreset22->UseVisualStyleBackColor = true;
			this->rdbPreset22->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset21
			// 
			this->rdbPreset21->AutoSize = true;
			this->rdbPreset21->Checked = true;
			this->rdbPreset21->Location = System::Drawing::Point(0, 0);
			this->rdbPreset21->Name = L"rdbPreset21";
			this->rdbPreset21->Size = System::Drawing::Size(14, 13);
			this->rdbPreset21->TabIndex = 5;
			this->rdbPreset21->TabStop = true;
			this->rdbPreset21->UseVisualStyleBackColor = true;
			this->rdbPreset21->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// panPresetControl1
			// 
			this->panPresetControl1->BackColor = System::Drawing::Color::DarkOrange;
			this->panPresetControl1->Controls->Add(this->rdbPreset14);
			this->panPresetControl1->Controls->Add(this->rdbPreset13);
			this->panPresetControl1->Controls->Add(this->rdbPreset12);
			this->panPresetControl1->Controls->Add(this->rdbPreset11);
			this->panPresetControl1->Location = System::Drawing::Point(147, 29);
			this->panPresetControl1->Name = L"panPresetControl1";
			this->panPresetControl1->Size = System::Drawing::Size(29, 139);
			this->panPresetControl1->TabIndex = 0;
			// 
			// rdbPreset14
			// 
			this->rdbPreset14->AutoSize = true;
			this->rdbPreset14->Location = System::Drawing::Point(0, 57);
			this->rdbPreset14->Name = L"rdbPreset14";
			this->rdbPreset14->Size = System::Drawing::Size(14, 13);
			this->rdbPreset14->TabIndex = 3;
			this->rdbPreset14->UseVisualStyleBackColor = true;
			this->rdbPreset14->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset13
			// 
			this->rdbPreset13->AutoSize = true;
			this->rdbPreset13->Location = System::Drawing::Point(0, 38);
			this->rdbPreset13->Name = L"rdbPreset13";
			this->rdbPreset13->Size = System::Drawing::Size(14, 13);
			this->rdbPreset13->TabIndex = 2;
			this->rdbPreset13->UseVisualStyleBackColor = true;
			this->rdbPreset13->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset12
			// 
			this->rdbPreset12->AutoSize = true;
			this->rdbPreset12->Location = System::Drawing::Point(0, 19);
			this->rdbPreset12->Name = L"rdbPreset12";
			this->rdbPreset12->Size = System::Drawing::Size(14, 13);
			this->rdbPreset12->TabIndex = 1;
			this->rdbPreset12->UseVisualStyleBackColor = true;
			this->rdbPreset12->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset11
			// 
			this->rdbPreset11->AutoSize = true;
			this->rdbPreset11->Checked = true;
			this->rdbPreset11->Location = System::Drawing::Point(0, 0);
			this->rdbPreset11->Name = L"rdbPreset11";
			this->rdbPreset11->Size = System::Drawing::Size(14, 13);
			this->rdbPreset11->TabIndex = 0;
			this->rdbPreset11->TabStop = true;
			this->rdbPreset11->UseVisualStyleBackColor = true;
			this->rdbPreset11->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// lblPreset
			// 
			this->lblPreset->AutoSize = true;
			this->lblPreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblPreset->Location = System::Drawing::Point(13, 12);
			this->lblPreset->Name = L"lblPreset";
			this->lblPreset->Size = System::Drawing::Size(364, 37);
			this->lblPreset->TabIndex = 14;
			this->lblPreset->Text = L"Фиксированный импульс";
			this->lblPreset->TextAlign = System::Drawing::ContentAlignment::TopCenter;
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
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(261, 204);
			this->trackBar3->Maximum = 20;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(252, 45);
			this->trackBar3->TabIndex = 13;
			this->trackBar3->Value = 18;
			this->trackBar3->Visible = false;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			this->trackBar3->ValueChanged += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(3, 204);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(252, 45);
			this->trackBar2->TabIndex = 12;
			this->trackBar2->Value = 75;
			this->trackBar2->Visible = false;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			this->trackBar2->ValueChanged += gcnew System::EventHandler(this, &UI::trackBar2_ValueChanged);
			// 
			// pbxSpec
			// 
			this->pbxSpec->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxSpec->Location = System::Drawing::Point(19, 244);
			this->pbxSpec->Name = L"pbxSpec";
			this->pbxSpec->Size = System::Drawing::Size(640, 214);
			this->pbxSpec->TabIndex = 7;
			this->pbxSpec->TabStop = false;
			this->pbxSpec->Click += gcnew System::EventHandler(this, &UI::onClick);
			this->pbxSpec->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UI::onSpecPaint);
			// 
			// pbxImp
			// 
			this->pbxImp->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxImp->Location = System::Drawing::Point(19, 24);
			this->pbxImp->Name = L"pbxImp";
			this->pbxImp->Size = System::Drawing::Size(640, 214);
			this->pbxImp->TabIndex = 6;
			this->pbxImp->TabStop = false;
			this->pbxImp->Click += gcnew System::EventHandler(this, &UI::onClick);
			this->pbxImp->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UI::onImpPaint);
			// 
			// uiGfx
			// 
			this->uiGfx->BackColor = System::Drawing::Color::Maroon;
			this->uiGfx->Controls->Add(this->trackBar3);
			this->uiGfx->Controls->Add(this->trackBar2);
			this->uiGfx->Controls->Add(this->pbxImp);
			this->uiGfx->Controls->Add(this->pbxSpec);
			this->uiGfx->Location = System::Drawing::Point(21, 504);
			this->uiGfx->Name = L"uiGfx";
			this->uiGfx->Size = System::Drawing::Size(676, 474);
			this->uiGfx->TabIndex = 17;
			this->uiGfx->Visible = false;
			// 
			// uiTrap
			// 
			this->uiTrap->BackColor = System::Drawing::Color::DarkGreen;
			this->uiTrap->Controls->Add(this->lblTrap);
			this->uiTrap->Controls->Add(this->trbTrap);
			this->uiTrap->Location = System::Drawing::Point(60, 315);
			this->uiTrap->Name = L"uiTrap";
			this->uiTrap->Size = System::Drawing::Size(327, 430);
			this->uiTrap->TabIndex = 17;
			this->uiTrap->Visible = false;
			// 
			// lblTrap
			// 
			this->lblTrap->AutoSize = true;
			this->lblTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->lblTrap->Location = System::Drawing::Point(13, 12);
			this->lblTrap->Name = L"lblTrap";
			this->lblTrap->Size = System::Drawing::Size(371, 37);
			this->lblTrap->TabIndex = 14;
			this->lblTrap->Text = L"Криволинейная трапеция";
			this->lblTrap->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// trbTrap
			// 
			this->trbTrap->Location = System::Drawing::Point(10, 130);
			this->trbTrap->Maximum = 200;
			this->trbTrap->Name = L"trbTrap";
			this->trbTrap->Size = System::Drawing::Size(255, 45);
			this->trbTrap->TabIndex = 11;
			this->trbTrap->Value = 10;
			this->trbTrap->Scroll += gcnew System::EventHandler(this, &UI::TrapWidthChanged);
			this->trbTrap->ValueChanged += gcnew System::EventHandler(this, &UI::TrapWidthChanged);
			// 
			// btnBack
			// 
			this->btnBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->btnBack->Location = System::Drawing::Point(7, 210);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(204, 57);
			this->btnBack->TabIndex = 18;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &UI::btnBack_Click);
			// 
			// uiGlobal
			// 
			this->uiGlobal->BackColor = System::Drawing::Color::SlateBlue;
			this->uiGlobal->Controls->Add(this->label3);
			this->uiGlobal->Controls->Add(this->label2);
			this->uiGlobal->Controls->Add(this->label1);
			this->uiGlobal->Controls->Add(this->lblSpecWidth2);
			this->uiGlobal->Controls->Add(this->lblSpecWidth1);
			this->uiGlobal->Controls->Add(this->btnBack);
			this->uiGlobal->Location = System::Drawing::Point(703, 472);
			this->uiGlobal->Name = L"uiGlobal";
			this->uiGlobal->Size = System::Drawing::Size(273, 270);
			this->uiGlobal->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(246, 37);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Ширина спектра";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->label2->Location = System::Drawing::Point(10, 157);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 39);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Крас";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->label1->Location = System::Drawing::Point(10, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 39);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Зел";
			// 
			// lblSpecWidth2
			// 
			this->lblSpecWidth2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lblSpecWidth2->AutoSize = true;
			this->lblSpecWidth2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblSpecWidth2->Location = System::Drawing::Point(132, 160);
			this->lblSpecWidth2->Name = L"lblSpecWidth2";
			this->lblSpecWidth2->Size = System::Drawing::Size(41, 39);
			this->lblSpecWidth2->TabIndex = 20;
			this->lblSpecWidth2->Text = L"--";
			// 
			// lblSpecWidth1
			// 
			this->lblSpecWidth1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lblSpecWidth1->AutoSize = true;
			this->lblSpecWidth1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblSpecWidth1->Location = System::Drawing::Point(132, 101);
			this->lblSpecWidth1->Name = L"lblSpecWidth1";
			this->lblSpecWidth1->Size = System::Drawing::Size(41, 39);
			this->lblSpecWidth1->TabIndex = 19;
			this->lblSpecWidth1->Text = L"--";
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 733);
			this->Controls->Add(this->uiGfx);
			this->Controls->Add(this->uiGlobal);
			this->Controls->Add(this->uiTrap);
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
			this->panPresetControl->ResumeLayout(false);
			this->panPresetControl->PerformLayout();
			this->panPresetControl2->ResumeLayout(false);
			this->panPresetControl2->PerformLayout();
			this->panPresetControl1->ResumeLayout(false);
			this->panPresetControl1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxSpec))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbxImp))->EndInit();
			this->uiGfx->ResumeLayout(false);
			this->uiGfx->PerformLayout();
			this->uiTrap->ResumeLayout(false);
			this->uiTrap->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trbTrap))->EndInit();
			this->uiGlobal->ResumeLayout(false);
			this->uiGlobal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		bool bDrawing; // В данный момент рисуем мышкой (кнопка мыши нажата)
		Point def;
		Point last;
		WMode ActiveMode;

		Pen ^RedPen, ^GreenPen, ^AxisPen;
		
		System::Void AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e)
		{
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

			// global
			uiGlobal->Left = 0;
			uiGlobal->Top = ClientSize.Height - uiGlobal->Height;

			// uiMainMenu
			btnPreset->Left = (ClientSize.Width - btnPreset->Width) / 2;
			btnTrap->Left = btnPreset->Left;

			// uiPreset
			lblPreset->Left = (ClientSize.Width - lblPreset->Width) / 2;

			// uiTrap
			lblTrap->Left = (ClientSize.Width - lblTrap->Width) / 2;

			
			// uiGfx
			uiGfx->Width  = ClientSize.Width - LeftPanelWidth - Spacing;
			uiGfx->Height = ClientSize.Height - TopPanelHeight - Spacing;
			uiGfx->Left   = LeftPanelWidth;
			uiGfx->Top    = TopPanelHeight;

			pbxImp->Width   = uiGfx->Width;
			pbxSpec->Width  = pbxImp->Width;
			pbxImp->Height  = (uiGfx->Height - Spacing) / 2;
			pbxSpec->Height = pbxImp->Height;

			pbxImp->Left  = 0;
			pbxSpec->Left = 0;
			pbxImp->Top   = 0;
			pbxSpec->Top  = pbxImp->Height + Spacing;
			
			RawHand[0].resize(pbxImp->Width, 0);
			RawHand[1].resize(pbxImp->Width, 0);

			InvalidateAll();
		}
		System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
			uiMainMenu->Visible = true;
			uiPreset->Visible = false;
			uiTrap->Visible = false;
			uiGfx->Visible = false;
			uiGlobal->Visible = false;
		}
		System::Void btnPreset_Click(System::Object^  sender, System::EventArgs^  e)
		{
			uiMainMenu->Visible = false;
			uiPreset->Visible = true;
			uiGfx->Visible = true;
			uiGlobal->Visible = true;
		}
		System::Void btnTrap_Click(System::Object^  sender, System::EventArgs^  e)
		{
			uiMainMenu->Visible = false;
			uiTrap->Visible = true;
			uiGfx->Visible = true;
			uiGlobal->Visible = true;
		}
		System::Void InvalidateAll()
		{
			pbxImp->Invalidate();
			pbxSpec->Invalidate();
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
				          (float)((1 - (y / 8 /* buf[0].MaxSpec*/ + 0.125) * 0.8) * pbxSpec->Height));
		}
		PointF BackTransformImp(float x, float y, int index)
		{
			return PointF((float)(x * buf[index].len / pbxImp->Width),
				          (float)((1 - (y / pbxImp->Height)) / 0.8 - 0.125));
		}
		PointF BackTransformSpec(float x, float y, int index)
		{
			return PointF((float)(x * buf[index].len / trackBar2->Value/ pbxSpec->Width),
				          (float)(((1 - (y / pbxSpec->Height))/ 0.8 - 0.125) * 8 /* buf[index].MaxSpec*/));
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
			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			// Draw axes
			PointF p;
			for (int i = -100; i < 100; ++i)
			{
				p = TransformImp(buf[0].len / 2 + i * PointsPerSecond, 0, 0);
				e->Graphics->DrawLine(AxisPen, p.X, p.Y + 3, p.X, p.Y + 15);
			}
			p = TransformImp(buf[0].len / 2, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X - 2000, p.Y + 3, p.X + 2000, p.Y + 3);

			array<PointF>^ curvePoints = TransformPointsImp(0, e);
			//e->Graphics->DrawCurve(GreenPen, curvePoints, 0, curvePoints->Length-1, .5F);
			e->Graphics->DrawLines(GreenPen, curvePoints);
			curvePoints = TransformPointsImp(1, e);
			//e->Graphics->DrawCurve(RedPen, curvePoints, 0, curvePoints->Length-1, .5F);
			e->Graphics->DrawLines(RedPen, curvePoints);

		}
		void DrawSpec(PaintEventArgs^ e)
		{
			PointF p;
			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			// Draw axes
			for (int i = -100; i < 100; ++i)
			{
				p = TransformSpec(i * buf[0].len / PointsPerSecond, 0, 0);
				e->Graphics->DrawLine(AxisPen, p.X, p.Y + 3, p.X, p.Y + 15);
			}
			p = TransformSpec(0, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X - 5, p.Y + 3, p.X + 4000, p.Y + 3);

//			for (int i = 0; i < 10; ++i)
//			{
//				p = TransformSpec(0, i, 0);
//				e->Graphics->DrawLine(AxisPen, p.X + 2, p.Y, p.X + 15, p.Y);
//			}

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

			sprintf(textbuffer, "%.2f Гц", buf[0].SpecWidth * PointsPerSecond / buf[0].len);
			lblSpecWidth1->Text = gcnew String(textbuffer);
			sprintf(textbuffer, "%.2f Гц", buf[1].SpecWidth * PointsPerSecond / buf[1].len);
			lblSpecWidth2->Text = gcnew String(textbuffer);
		}


private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 E_0 = 15 * trackBar1->Value;
			 buf[0].generate_gauss(100);
			 buf[1].generate_rect();
			 InvalidateAll();
}
private: System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 InvalidateAll();
}
private: System::Void PresetFuncChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(rdbPreset11->Checked)
				 buf[0].generate_gauss_f_p();
			 if(rdbPreset12->Checked)
				 buf[0].generate_sin_f_p();
			 if(rdbPreset13->Checked)
				 buf[0].generate_tri_f_p();
			 if(rdbPreset14->Checked)
				 buf[0].generate_rect();
			 
			 if(rdbPreset21->Checked)
				 buf[1].generate_gauss_f_p();
			 if(rdbPreset22->Checked)
				 buf[1].generate_sin_f_p();
			 if(rdbPreset23->Checked)
				 buf[1].generate_tri_f_p();
			 if(rdbPreset24->Checked)
				 buf[1].generate_rect();

			 InvalidateAll();

}
private: System::Void TrapWidthChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (trbTrap->Value)
				 buf[0].generate_gauss(trbTrap->Value);
			 else
				 buf[0].generate_rect();

			 InvalidateAll();
}

/*
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
		
//			if(last == def) last = e->Location;

//			int beg = Math::Min(last.X, e->X);
//			int end = Math::Max(last.X, e->X);
//			for(int i = beg; i <=end; ++i)
//			{
//				RawHand[idx][i] = last.Y + ((float)e->Y-last.Y)*(i-beg+1)/(end-beg+1);
//			}

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


*/

};
}
