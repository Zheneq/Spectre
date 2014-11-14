#pragma once
#include "Fourier.h"
#include <iostream>
#include <vector>
#include <cmath>
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
	private ref class UI : public System::Windows::Forms::Form
	{
	public:
		UI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			bDrawing = false;
			bDrawingMode = false;
			def = Point(-1,-1);
			last = def;
			SpecMult = 1;

			StartDef = Point(7800, 0);
			FinishDef = Point(8584, 0);
			Radius = 8;

			RedPen = gcnew Pen(Color::Red, 1.0f);
			GreenPen = gcnew Pen(Color::Green, 3.0f);
			AxisPen = gcnew Pen(Color::Black, 3.0f);
			FramePen = gcnew Pen(Color::Black, 1.0f);
			brush = gcnew SolidBrush(Color::Black);
			font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold);
			//	gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Bold,
			//	System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
			//
			RefreshColorScheme();
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



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnHand;
	private: System::Windows::Forms::Panel^  uiHand;
	private: System::Windows::Forms::Label^  lblHand;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblC2;
	private: System::Windows::Forms::Label^  lblC1;
	private: System::Windows::Forms::Timer^  tmrMessage;
	private: System::Windows::Forms::Label^  lblMessage;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->uiMainMenu = (gcnew System::Windows::Forms::Panel());
			this->btnHand = (gcnew System::Windows::Forms::Button());
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
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->uiTrap = (gcnew System::Windows::Forms::Panel());
			this->lblTrap = (gcnew System::Windows::Forms::Label());
			this->trbTrap = (gcnew System::Windows::Forms::TrackBar());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->uiGlobal = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblC2 = (gcnew System::Windows::Forms::Label());
			this->lblC1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblSpecWidth2 = (gcnew System::Windows::Forms::Label());
			this->lblSpecWidth1 = (gcnew System::Windows::Forms::Label());
			this->uiHand = (gcnew System::Windows::Forms::Panel());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lblHand = (gcnew System::Windows::Forms::Label());
			this->tmrMessage = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->uiMainMenu->SuspendLayout();
			this->uiPreset->SuspendLayout();
			this->panPresetControl->SuspendLayout();
			this->panPresetControl2->SuspendLayout();
			this->panPresetControl1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSpec))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxImp))->BeginInit();
			this->uiGfx->SuspendLayout();
			this->uiTrap->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trbTrap))->BeginInit();
			this->uiGlobal->SuspendLayout();
			this->uiHand->SuspendLayout();
			this->SuspendLayout();
			// 
			// uiMainMenu
			// 
			this->uiMainMenu->BackColor = System::Drawing::SystemColors::ControlDark;
			this->uiMainMenu->Controls->Add(this->btnExit);
			this->uiMainMenu->Controls->Add(this->btnHand);
			this->uiMainMenu->Controls->Add(this->btnTrap);
			this->uiMainMenu->Controls->Add(this->btnPreset);
			this->uiMainMenu->Location = System::Drawing::Point(45, 12);
			this->uiMainMenu->Name = L"uiMainMenu";
			this->uiMainMenu->Size = System::Drawing::Size(375, 296);
			this->uiMainMenu->TabIndex = 15;
			// 
			// btnHand
			// 
			this->btnHand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnHand->Location = System::Drawing::Point(3, 135);
			this->btnHand->Name = L"btnHand";
			this->btnHand->Size = System::Drawing::Size(350, 60);
			this->btnHand->TabIndex = 3;
			this->btnHand->Text = L"Ручной ввод";
			this->btnHand->UseVisualStyleBackColor = true;
			this->btnHand->Click += gcnew System::EventHandler(this, &UI::btnHand_Click);
			// 
			// btnTrap
			// 
			this->btnTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnTrap->Location = System::Drawing::Point(3, 69);
			this->btnTrap->Name = L"btnTrap";
			this->btnTrap->Size = System::Drawing::Size(350, 60);
			this->btnTrap->TabIndex = 2;
			this->btnTrap->Text = L"Криволинейная трапеция";
			this->btnTrap->UseVisualStyleBackColor = true;
			this->btnTrap->Click += gcnew System::EventHandler(this, &UI::btnTrap_Click);
			// 
			// btnPreset
			// 
			this->btnPreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnPreset->Location = System::Drawing::Point(3, 3);
			this->btnPreset->Name = L"btnPreset";
			this->btnPreset->Size = System::Drawing::Size(450, 60);
			this->btnPreset->TabIndex = 1;
			this->btnPreset->Text = L"Фиксированный импульс";
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
			this->panPresetControl->Location = System::Drawing::Point(0, 90);
			this->panPresetControl->Name = L"panPresetControl";
			this->panPresetControl->Size = System::Drawing::Size(280, 250);
			this->panPresetControl->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(5, 110);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(99, 31);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Треуг.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(5, 60);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(126, 31);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Косинус";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(5, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 31);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Прям.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(5, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 31);
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
			this->panPresetControl2->Location = System::Drawing::Point(230, 0);
			this->panPresetControl2->Name = L"panPresetControl2";
			this->panPresetControl2->Size = System::Drawing::Size(50, 250);
			this->panPresetControl2->TabIndex = 1;
			// 
			// rdbPreset24
			// 
			this->rdbPreset24->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset24->Checked = true;
			this->rdbPreset24->Location = System::Drawing::Point(0, 150);
			this->rdbPreset24->Name = L"rdbPreset24";
			this->rdbPreset24->Size = System::Drawing::Size(50, 50);
			this->rdbPreset24->TabIndex = 8;
			this->rdbPreset24->TabStop = true;
			this->rdbPreset24->UseVisualStyleBackColor = true;
			this->rdbPreset24->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset23
			// 
			this->rdbPreset23->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset23->Location = System::Drawing::Point(0, 100);
			this->rdbPreset23->Name = L"rdbPreset23";
			this->rdbPreset23->Size = System::Drawing::Size(50, 50);
			this->rdbPreset23->TabIndex = 7;
			this->rdbPreset23->UseVisualStyleBackColor = true;
			this->rdbPreset23->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset22
			// 
			this->rdbPreset22->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset22->Location = System::Drawing::Point(0, 50);
			this->rdbPreset22->Name = L"rdbPreset22";
			this->rdbPreset22->Size = System::Drawing::Size(50, 50);
			this->rdbPreset22->TabIndex = 6;
			this->rdbPreset22->UseVisualStyleBackColor = true;
			this->rdbPreset22->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset21
			// 
			this->rdbPreset21->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset21->Location = System::Drawing::Point(0, 0);
			this->rdbPreset21->Name = L"rdbPreset21";
			this->rdbPreset21->Size = System::Drawing::Size(50, 50);
			this->rdbPreset21->TabIndex = 5;
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
			this->panPresetControl1->Location = System::Drawing::Point(180, 0);
			this->panPresetControl1->Name = L"panPresetControl1";
			this->panPresetControl1->Size = System::Drawing::Size(50, 250);
			this->panPresetControl1->TabIndex = 0;
			// 
			// rdbPreset14
			// 
			this->rdbPreset14->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset14->Location = System::Drawing::Point(0, 150);
			this->rdbPreset14->Name = L"rdbPreset14";
			this->rdbPreset14->Size = System::Drawing::Size(50, 50);
			this->rdbPreset14->TabIndex = 3;
			this->rdbPreset14->UseVisualStyleBackColor = true;
			this->rdbPreset14->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset13
			// 
			this->rdbPreset13->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset13->Location = System::Drawing::Point(0, 100);
			this->rdbPreset13->Name = L"rdbPreset13";
			this->rdbPreset13->Size = System::Drawing::Size(50, 50);
			this->rdbPreset13->TabIndex = 2;
			this->rdbPreset13->UseVisualStyleBackColor = true;
			this->rdbPreset13->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset12
			// 
			this->rdbPreset12->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset12->Location = System::Drawing::Point(0, 50);
			this->rdbPreset12->Name = L"rdbPreset12";
			this->rdbPreset12->Size = System::Drawing::Size(50, 50);
			this->rdbPreset12->TabIndex = 1;
			this->rdbPreset12->UseVisualStyleBackColor = true;
			this->rdbPreset12->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// rdbPreset11
			// 
			this->rdbPreset11->Appearance = System::Windows::Forms::Appearance::Button;
			this->rdbPreset11->Checked = true;
			this->rdbPreset11->Location = System::Drawing::Point(0, 0);
			this->rdbPreset11->Name = L"rdbPreset11";
			this->rdbPreset11->Size = System::Drawing::Size(50, 50);
			this->rdbPreset11->TabIndex = 0;
			this->rdbPreset11->TabStop = true;
			this->rdbPreset11->UseVisualStyleBackColor = true;
			this->rdbPreset11->CheckedChanged += gcnew System::EventHandler(this, &UI::PresetFuncChanged);
			// 
			// lblPreset
			// 
			this->lblPreset->AutoSize = true;
			this->lblPreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold));
			this->lblPreset->Location = System::Drawing::Point(13, 12);
			this->lblPreset->Name = L"lblPreset";
			this->lblPreset->Size = System::Drawing::Size(610, 55);
			this->lblPreset->TabIndex = 14;
			this->lblPreset->Text = L"Фиксированный импульс";
			this->lblPreset->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(11, 346);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Minimum = 8;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(255, 45);
			this->trackBar1->TabIndex = 11;
			this->trackBar1->Value = 8;
			this->trackBar1->Visible = false;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &UI::trackBar1_ValueChanged);
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
			this->pbxImp->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::EnableDrawing);
			this->pbxImp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::HandDrawing);
			this->pbxImp->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::DisableDrawing);
			// 
			// uiGfx
			// 
			this->uiGfx->BackColor = System::Drawing::Color::Maroon;
			this->uiGfx->Controls->Add(this->lblMessage);
			this->uiGfx->Controls->Add(this->trackBar3);
			this->uiGfx->Controls->Add(this->trackBar2);
			this->uiGfx->Controls->Add(this->pbxImp);
			this->uiGfx->Controls->Add(this->pbxSpec);
			this->uiGfx->Location = System::Drawing::Point(20, 475);
			this->uiGfx->Name = L"uiGfx";
			this->uiGfx->Size = System::Drawing::Size(676, 474);
			this->uiGfx->TabIndex = 17;
			this->uiGfx->Visible = false;
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->BackColor = System::Drawing::Color::Transparent;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMessage->Location = System::Drawing::Point(3, 5);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(170, 31);
			this->lblMessage->TabIndex = 14;
			this->lblMessage->Text = L"Сообщение";
			this->lblMessage->Visible = false;
			// 
			// uiTrap
			// 
			this->uiTrap->BackColor = System::Drawing::Color::DarkGreen;
			this->uiTrap->Controls->Add(this->label8);
			this->uiTrap->Controls->Add(this->label2);
			this->uiTrap->Controls->Add(this->lblTrap);
			this->uiTrap->Controls->Add(this->trbTrap);
			this->uiTrap->Location = System::Drawing::Point(39, 324);
			this->uiTrap->Name = L"uiTrap";
			this->uiTrap->Size = System::Drawing::Size(327, 430);
			this->uiTrap->TabIndex = 17;
			this->uiTrap->Visible = false;
			// 
			// lblTrap
			// 
			this->lblTrap->AutoSize = true;
			this->lblTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblTrap->Location = System::Drawing::Point(13, 12);
			this->lblTrap->Name = L"lblTrap";
			this->lblTrap->Size = System::Drawing::Size(623, 55);
			this->lblTrap->TabIndex = 14;
			this->lblTrap->Text = L"Криволинейная трапеция";
			this->lblTrap->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// trbTrap
			// 
			this->trbTrap->Location = System::Drawing::Point(10, 130);
			this->trbTrap->Maximum = 238;
			this->trbTrap->Name = L"trbTrap";
			this->trbTrap->Size = System::Drawing::Size(260, 45);
			this->trbTrap->TabIndex = 11;
			this->trbTrap->Value = 119;
			this->trbTrap->Scroll += gcnew System::EventHandler(this, &UI::TrapWidthChanged);
			this->trbTrap->ValueChanged += gcnew System::EventHandler(this, &UI::TrapWidthChanged);
			// 
			// btnBack
			// 
			this->btnBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnBack->Location = System::Drawing::Point(10, 169);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(260, 60);
			this->btnBack->TabIndex = 18;
			this->btnBack->Text = L"Назад";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &UI::btnBack_Click);
			// 
			// uiGlobal
			// 
			this->uiGlobal->BackColor = System::Drawing::Color::SlateBlue;
			this->uiGlobal->Controls->Add(this->label1);
			this->uiGlobal->Controls->Add(this->lblC2);
			this->uiGlobal->Controls->Add(this->lblC1);
			this->uiGlobal->Controls->Add(this->label3);
			this->uiGlobal->Controls->Add(this->lblSpecWidth2);
			this->uiGlobal->Controls->Add(this->lblSpecWidth1);
			this->uiGlobal->Controls->Add(this->btnBack);
			this->uiGlobal->Location = System::Drawing::Point(606, 492);
			this->uiGlobal->Name = L"uiGlobal";
			this->uiGlobal->Size = System::Drawing::Size(280, 232);
			this->uiGlobal->TabIndex = 19;
			this->uiGlobal->Visible = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 37);
			this->label1->TabIndex = 26;
			this->label1->Text = L"С = ΔωΔt/2π";
			// 
			// lblC2
			// 
			this->lblC2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblC2->AutoSize = true;
			this->lblC2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblC2->ForeColor = System::Drawing::Color::Red;
			this->lblC2->Location = System::Drawing::Point(143, 44);
			this->lblC2->Name = L"lblC2";
			this->lblC2->Size = System::Drawing::Size(41, 39);
			this->lblC2->TabIndex = 25;
			this->lblC2->Text = L"--";
			// 
			// lblC1
			// 
			this->lblC1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblC1->AutoSize = true;
			this->lblC1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblC1->ForeColor = System::Drawing::Color::Green;
			this->lblC1->Location = System::Drawing::Point(9, 44);
			this->lblC1->Name = L"lblC1";
			this->lblC1->Size = System::Drawing::Size(41, 39);
			this->lblC1->TabIndex = 24;
			this->lblC1->Text = L"--";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(9, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(246, 37);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Ширина спектра";
			// 
			// lblSpecWidth2
			// 
			this->lblSpecWidth2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblSpecWidth2->AutoSize = true;
			this->lblSpecWidth2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblSpecWidth2->ForeColor = System::Drawing::Color::Red;
			this->lblSpecWidth2->Location = System::Drawing::Point(143, 130);
			this->lblSpecWidth2->Name = L"lblSpecWidth2";
			this->lblSpecWidth2->Size = System::Drawing::Size(41, 39);
			this->lblSpecWidth2->TabIndex = 20;
			this->lblSpecWidth2->Text = L"--";
			// 
			// lblSpecWidth1
			// 
			this->lblSpecWidth1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblSpecWidth1->AutoSize = true;
			this->lblSpecWidth1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblSpecWidth1->ForeColor = System::Drawing::Color::Green;
			this->lblSpecWidth1->Location = System::Drawing::Point(9, 130);
			this->lblSpecWidth1->Name = L"lblSpecWidth1";
			this->lblSpecWidth1->Size = System::Drawing::Size(41, 39);
			this->lblSpecWidth1->TabIndex = 19;
			this->lblSpecWidth1->Text = L"--";
			// 
			// uiHand
			// 
			this->uiHand->BackColor = System::Drawing::Color::GreenYellow;
			this->uiHand->Controls->Add(this->btnReset);
			this->uiHand->Controls->Add(this->lblHand);
			this->uiHand->Location = System::Drawing::Point(860, 215);
			this->uiHand->Name = L"uiHand";
			this->uiHand->Size = System::Drawing::Size(327, 430);
			this->uiHand->TabIndex = 20;
			this->uiHand->Visible = false;
			// 
			// btnReset
			// 
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnReset->Location = System::Drawing::Point(10, 90);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(260, 60);
			this->btnReset->TabIndex = 19;
			this->btnReset->Text = L"Сбросить";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &UI::btnReset_Click);
			// 
			// lblHand
			// 
			this->lblHand->AutoSize = true;
			this->lblHand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblHand->Location = System::Drawing::Point(13, 12);
			this->lblHand->Name = L"lblHand";
			this->lblHand->Size = System::Drawing::Size(316, 55);
			this->lblHand->TabIndex = 14;
			this->lblHand->Text = L"Ручной ввод";
			this->lblHand->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tmrMessage
			// 
			this->tmrMessage->Interval = 50;
			this->tmrMessage->Tick += gcnew System::EventHandler(this, &UI::tmrMessage_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 31);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Гаусс";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(174, 98);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(96, 31);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Прям.";
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->Location = System::Drawing::Point(3, 201);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(350, 60);
			this->btnExit->TabIndex = 4;
			this->btnExit->Text = L"Выход";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &UI::btnExit_Click);
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 733);
			this->Controls->Add(this->uiGlobal);
			this->Controls->Add(this->uiHand);
			this->Controls->Add(this->uiGfx);
			this->Controls->Add(this->uiTrap);
			this->Controls->Add(this->uiPreset);
			this->Controls->Add(this->uiMainMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"UI";
			this->Text = L"UI";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
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
			this->panPresetControl1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxSpec))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxImp))->EndInit();
			this->uiGfx->ResumeLayout(false);
			this->uiGfx->PerformLayout();
			this->uiTrap->ResumeLayout(false);
			this->uiTrap->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trbTrap))->EndInit();
			this->uiGlobal->ResumeLayout(false);
			this->uiGlobal->PerformLayout();
			this->uiHand->ResumeLayout(false);
			this->uiHand->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		array<Point>^ RawHand;
	private: 
		bool bDrawing; // В данный момент рисуем мышкой (кнопка мыши нажата)
		bool bDrawingMode; // Включён режим рисования
		Point def;
		Point last;
		float SpecMult;

		Point StartDef, FinishDef; // в реальных координатах
		PointF Start, Finish; // в экранных координатах
		float Radius; // в экранных координатах

		Pen ^RedPen, ^GreenPen, ^AxisPen, ^FramePen;
		Brush ^brush;
		System::Drawing::Font ^font;
		
		System::Void RefreshColorScheme()
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
		}

		System::Void AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e)
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
			
			RawHand = gcnew array<Point>(pbxImp->Width);
			ResetHand();

			InvalidateAll();
		}
		System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
			uiMainMenu->Visible = true;
			uiPreset->Visible = false;
			uiTrap->Visible = false;
			uiHand->Visible = false;
			uiGfx->Visible = false;
			uiGlobal->Visible = false;
			bDrawingMode = false;
		}
		System::Void btnPreset_Click(System::Object^  sender, System::EventArgs^  e)
		{
			PresetFuncChanged(sender, e);

			uiMainMenu->Visible = false;
			uiPreset->Visible = true;
			uiGfx->Visible = true;
			uiGlobal->Visible = true;
			uiGfx->BringToFront();
			uiGlobal->BringToFront();

			SpecMult = 1.1;
		}
		System::Void btnTrap_Click(System::Object^  sender, System::EventArgs^  e)
		{
			buf[1].generate_rect();
			TrapWidthChanged(sender, e);

			uiMainMenu->Visible = false;
			uiTrap->Visible = true;
			uiGfx->Visible = true;
			uiGlobal->Visible = true;
			uiGfx->BringToFront();
			uiGlobal->BringToFront();

			SpecMult = 1.3;
		}
		System::Void btnHand_Click(System::Object^  sender, System::EventArgs^  e) {
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

			SpecMult = 1;
		}
		System::Void InvalidateAll()
		{
			pbxImp->Invalidate();
			pbxSpec->Invalidate();
		}		
		System::Void onClick(System::Object^  sender, System::EventArgs^  e)
		{
//			InvalidateAll();
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
				          (float)((1 - (y / 8 / SpecMult + 0.125) * 0.8) * pbxSpec->Height));
		}
		PointF BackTransformImp(float x, float y, int index)
		{
			return PointF((float)((x / pbxImp->Width + (trackBar3->Value - 1)*.5) * buf[index].len / trackBar3->Value ),
				          (float)((1 - (y / pbxImp->Height)) / 0.8 - 0.125));
		}
//		PointF BackTransformSpec(float x, float y, int index)
//		{
//			return PointF((float)(x * buf[index].len / trackBar2->Value/ pbxSpec->Width),
//				          (float)(((1 - (y / pbxSpec->Height))/ 0.8 - 0.125) * 8 * SpecMult));
//		}

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
			p = TransformImp(buf[0].len / 2, 0, 0);
			e->Graphics->DrawLine(AxisPen, p.X - 2000, p.Y + 3, p.X + 2000, p.Y + 3);
			e->Graphics->DrawLine(AxisPen, p.X, p.Y - 2000, p.X, p.Y + 2000);
			
			if(!bDrawingMode)
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
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, pbxImp->Width - 40, p.Y - 30);

		}
		void DrawSpec(PaintEventArgs^ e)
		{
			PointF p;
			e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
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
			
			sprintf(textbuffer, "f, Гц");
			e->Graphics->DrawString(gcnew String(textbuffer), font, brush, pbxImp->Width - 55, p.Y - 30);


			float RealSpecWidth[2];
			RealSpecWidth[0] = buf[0].SpecWidth * PointsPerSecond / buf[0].len;
			RealSpecWidth[1] = buf[1].SpecWidth * PointsPerSecond / buf[1].len;

			sprintf(textbuffer, "%.2f Гц", RealSpecWidth[0]);
			lblSpecWidth1->Text = gcnew String(textbuffer);
			sprintf(textbuffer, "%.2f Гц", RealSpecWidth[1]);
			lblSpecWidth2->Text = gcnew String(textbuffer);


			float length;
			int i, b;
			for (i = 0; buf[0].imp[i] <= 0 && i < buf[0].len; ++i) b = i;
			for (; buf[0].imp[i] > 0 && i < buf[0].len; ++i) length = i;
			length = (length - b) / PointsPerSecond;

			std::cout << "len " << length;

			sprintf(textbuffer, "%.2f", RealSpecWidth[0] * length *.5 / pi);
			lblC1->Text = gcnew String(textbuffer);


			for (i = 0; buf[1].imp[i] <= 0 && i < buf[1].len; ++i) b = i;
			for (; buf[1].imp[i] > 0 && i < buf[1].len; ++i) length = i;
			length = (length - b) / PointsPerSecond;

			std::cout << ' ' << length << " c = " << RealSpecWidth[1] * length *.5 / pi << '\n';

			sprintf(textbuffer, "%.2f", RealSpecWidth[1] * length *.5 / pi);
			lblC2->Text = gcnew String(textbuffer);
		}


private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 E_0 = 15 * trackBar1->Value;
			 PresetFuncChanged(sender, e);
			 /*
			 buf[0].generate_gauss(100);
			 buf[1].generate_rect();
			 */
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
		System::Void TrapWidthChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (trbTrap->Value)
				 buf[0].generate_gauss(trbTrap->Value);
			 else
				 buf[0].generate_rect();
			 InvalidateAll();
		}


		System::Void EnableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			PointF t = BackTransformImp(e->X, e->Y, 0);
			std::cout << "Click " << t.X << ", " << t.Y << "\n";

			if (pow(e->X - Start.X, 2) + pow(e->Y - Start.Y, 2) > pow(Radius, 2))
				return;

			std::cout << "EnableDrawing " << bDrawingMode << "\n";
			bDrawing = true;
		}
		System::Void DisableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			std::cout << "DisableDrawing " << bDrawingMode << "\n";
			bDrawing = false;
			last = def;

//			for(int i = 2; i < RawHand->Length-2; ++i)
//			{
//				RawHand[i].Y = (RawHand[i].Y + 0.6*(RawHand[i-1].Y+RawHand[i+1].Y)+ 0.1*(RawHand[i-2].Y+RawHand[i+2].Y))/2.4;
//			}
		}
		System::Void HandDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			if(!bDrawingMode || !bDrawing)
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

			if(last == def)
				last = Mouse;

			int beg = Math::Min(last.X, Mouse.X);
			int end = Math::Max(last.X, Mouse.X);
			int bas = Math::Min(last.Y, Mouse.Y);

//			for(int i = beg; i <=end; ++i)
//			{
//				//RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-last.X+1)/(Mouse.X-last.X+1);
//				RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-beg+1)/(end-beg+1);
//			}
			
			for(int i = last.X; i <=Mouse.X; ++i)
			{
				//RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-last.X+1)/(Mouse.X-last.X+1);
				RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-beg+1)/(end-beg+1);
			}
			// Если влево рисовать нельзя, этот цикл не нужен
			for(int i = Mouse.X; i <=last.X; ++i)
			{
				//RawHand[i].Y = last.Y + ((float)Mouse.Y-last.Y)*(i-last.X+1)/(Mouse.X-last.X+1);
				RawHand[i].Y = Mouse.Y + ((float)last.Y-Mouse.Y)*(i-beg+1)/(end-beg+1);
			}

			last = Mouse;
			Start = Mouse;

			for (int i = Start.X + 1; i < Finish.X; ++i)
			{
				RawHand[i].Y = Start.Y + (Finish.Y - Start.Y)*(i - Start.X) / (Finish.X - Start.X);
			}

			// Если довели до конца
			if (pow(Start.X - Finish.X, 2) + pow(Start.Y - Finish.Y, 2) < pow(Radius, 2))
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

		System::Void ResetHand()
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
		System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e)
		{
			ResetHand();
			buf[0].generate_null();
			bDrawingMode = true;
			pbxImp->Invalidate();


			ShowMessage(gcnew String("Возьмите левый кружок и\nнарисуйте им график импульса.\nЗакончить график нужно\nв правом кружке."));
		}
		void FinalizeHand()
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
			te = E_0;
			E_0 = t; // Больше говнокода богу говнокода!
			buf[1].generate_rect();
			E_0 = te; // Зато работает

			buf[0].fourier();
			InvalidateAll();
		}

		int MsgTime;
		System::Void ShowMessage(String ^msg)
		{
			if (!tmrMessage->Enabled)
			{
				lblMessage->Text = msg;
				lblMessage->Visible = true;
				MsgTime = 0;
				tmrMessage->Enabled = true;
			}
		}

		System::Void tmrMessage_Tick(System::Object^  sender, System::EventArgs^  e)
		{ 
			MsgTime++;
			if (MsgTime > 60)
			{
				lblMessage->Visible = false;
				tmrMessage->Enabled = false;
			}
		}
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
};
}
