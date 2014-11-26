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
			SpecYMult = 0.125;
			ImpXMult = trackBar3->Value;
			SpecXMult = trackBar2->Value;

			StartDef = Point(7800, 0);
			FinishDef = Point(8584, 0);
			Radius = 8;

			FirstPen = gcnew Pen(Color::Red, 3.0f);
			SecondPen = gcnew Pen(Color::Blue, 3.0f);

			_FirstPen  = (Pen^)FirstPen->Clone();
			_SecondPen = (Pen^)SecondPen->Clone();
			_FirstPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
			_SecondPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;

			AxisPen = gcnew Pen(Color::Black, 3.0f);
			FramePen = gcnew Pen(Color::Black, 1.0f);
			brush = gcnew SolidBrush(Color::Black);
			font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold);
			//	gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Bold,
			//	System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
			//
			YAxis = 40.0f;

			RefreshColorScheme();
			Back();
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
private: System::Windows::Forms::Label^  lblDeltaT;

	private: System::Windows::Forms::Label^  lblC2;
	private: System::Windows::Forms::Label^  lblC1;
	private: System::Windows::Forms::Timer^  tmrMessage;
	private: System::Windows::Forms::Label^  lblMessage;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnExit;
private: System::Windows::Forms::TrackBar^  trackBar4;
private: System::Windows::Forms::Label^  txtSpec;
private: System::Windows::Forms::Label^  txtImp;
private: System::Windows::Forms::Label^  txtSpecX;
private: System::Windows::Forms::Label^  txtSpecY;
private: System::Windows::Forms::Label^  txtImpX;
private: System::Windows::Forms::Label^  txtImpY;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Panel^  uiFaq;

private: System::Windows::Forms::PictureBox^  pbxFaq;
private: System::Windows::Forms::Panel^  uiAuthors;
private: System::Windows::Forms::Button^  btnAuthors;
private: System::Windows::Forms::Button^  btnFaq;
private: System::Windows::Forms::Label^  lblDeltaT2;
private: System::Windows::Forms::Label^  lblDeltaT1;

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
			this->btnAuthors = (gcnew System::Windows::Forms::Button());
			this->btnFaq = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
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
			this->txtSpecX = (gcnew System::Windows::Forms::Label());
			this->txtSpecY = (gcnew System::Windows::Forms::Label());
			this->txtImpX = (gcnew System::Windows::Forms::Label());
			this->txtImpY = (gcnew System::Windows::Forms::Label());
			this->txtSpec = (gcnew System::Windows::Forms::Label());
			this->txtImp = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->uiTrap = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTrap = (gcnew System::Windows::Forms::Label());
			this->trbTrap = (gcnew System::Windows::Forms::TrackBar());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->uiGlobal = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblDeltaT = (gcnew System::Windows::Forms::Label());
			this->lblC2 = (gcnew System::Windows::Forms::Label());
			this->lblC1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblSpecWidth2 = (gcnew System::Windows::Forms::Label());
			this->lblSpecWidth1 = (gcnew System::Windows::Forms::Label());
			this->uiHand = (gcnew System::Windows::Forms::Panel());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lblHand = (gcnew System::Windows::Forms::Label());
			this->tmrMessage = (gcnew System::Windows::Forms::Timer(this->components));
			this->uiFaq = (gcnew System::Windows::Forms::Panel());
			this->pbxFaq = (gcnew System::Windows::Forms::PictureBox());
			this->uiAuthors = (gcnew System::Windows::Forms::Panel());
			this->lblDeltaT1 = (gcnew System::Windows::Forms::Label());
			this->lblDeltaT2 = (gcnew System::Windows::Forms::Label());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->uiTrap->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trbTrap))->BeginInit();
			this->uiGlobal->SuspendLayout();
			this->uiHand->SuspendLayout();
			this->uiFaq->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxFaq))->BeginInit();
			this->SuspendLayout();
			// 
			// uiMainMenu
			// 
			this->uiMainMenu->BackColor = System::Drawing::SystemColors::ControlDark;
			this->uiMainMenu->Controls->Add(this->btnAuthors);
			this->uiMainMenu->Controls->Add(this->btnFaq);
			this->uiMainMenu->Controls->Add(this->btnExit);
			this->uiMainMenu->Controls->Add(this->btnHand);
			this->uiMainMenu->Controls->Add(this->btnTrap);
			this->uiMainMenu->Controls->Add(this->btnPreset);
			this->uiMainMenu->Location = System::Drawing::Point(19, 12);
			this->uiMainMenu->Name = L"uiMainMenu";
			this->uiMainMenu->Size = System::Drawing::Size(178, 93);
			this->uiMainMenu->TabIndex = 15;
			// 
			// btnAuthors
			// 
			this->btnAuthors->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAuthors->Location = System::Drawing::Point(4, 270);
			this->btnAuthors->Name = L"btnAuthors";
			this->btnAuthors->Size = System::Drawing::Size(350, 60);
			this->btnAuthors->TabIndex = 6;
			this->btnAuthors->Text = L"Авторы";
			this->btnAuthors->UseVisualStyleBackColor = true;
			this->btnAuthors->Click += gcnew System::EventHandler(this, &UI::btnAuthors_Click);
			// 
			// btnFaq
			// 
			this->btnFaq->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnFaq->Location = System::Drawing::Point(4, 6);
			this->btnFaq->Name = L"btnFaq";
			this->btnFaq->Size = System::Drawing::Size(450, 60);
			this->btnFaq->TabIndex = 5;
			this->btnFaq->Text = L"Принцип расчёта";
			this->btnFaq->UseVisualStyleBackColor = true;
			this->btnFaq->Click += gcnew System::EventHandler(this, &UI::btnFaq_Click);
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->Location = System::Drawing::Point(4, 336);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(350, 60);
			this->btnExit->TabIndex = 4;
			this->btnExit->Text = L"Выход";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &UI::btnExit_Click);
			// 
			// btnHand
			// 
			this->btnHand->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnHand->Location = System::Drawing::Point(4, 204);
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
			this->btnTrap->Location = System::Drawing::Point(4, 138);
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
			this->btnPreset->Location = System::Drawing::Point(4, 72);
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
			this->uiPreset->Location = System::Drawing::Point(212, 12);
			this->uiPreset->Name = L"uiPreset";
			this->uiPreset->Size = System::Drawing::Size(175, 93);
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
			this->panPresetControl2->Location = System::Drawing::Point(220, 0);
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
			this->panPresetControl1->Location = System::Drawing::Point(170, 0);
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
			this->trackBar2->Maximum = 200;
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
			this->pbxSpec->Location = System::Drawing::Point(333, 66);
			this->pbxSpec->Name = L"pbxSpec";
			this->pbxSpec->Size = System::Drawing::Size(326, 392);
			this->pbxSpec->TabIndex = 7;
			this->pbxSpec->TabStop = false;
			this->pbxSpec->Click += gcnew System::EventHandler(this, &UI::onClick);
			this->pbxSpec->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UI::onSpecPaint);
			// 
			// pbxImp
			// 
			this->pbxImp->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pbxImp->Location = System::Drawing::Point(19, 66);
			this->pbxImp->Name = L"pbxImp";
			this->pbxImp->Size = System::Drawing::Size(297, 365);
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
			this->uiGfx->Controls->Add(this->txtSpecX);
			this->uiGfx->Controls->Add(this->txtSpecY);
			this->uiGfx->Controls->Add(this->txtImpX);
			this->uiGfx->Controls->Add(this->txtImpY);
			this->uiGfx->Controls->Add(this->txtSpec);
			this->uiGfx->Controls->Add(this->txtImp);
			this->uiGfx->Controls->Add(this->trackBar4);
			this->uiGfx->Controls->Add(this->lblMessage);
			this->uiGfx->Controls->Add(this->trackBar3);
			this->uiGfx->Controls->Add(this->trackBar2);
			this->uiGfx->Controls->Add(this->pbxImp);
			this->uiGfx->Controls->Add(this->pbxSpec);
			this->uiGfx->Location = System::Drawing::Point(791, 12);
			this->uiGfx->Name = L"uiGfx";
			this->uiGfx->Size = System::Drawing::Size(176, 93);
			this->uiGfx->TabIndex = 17;
			this->uiGfx->Visible = false;
			// 
			// txtSpecX
			// 
			this->txtSpecX->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtSpecX->AutoSize = true;
			this->txtSpecX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSpecX->Location = System::Drawing::Point(127, -364);
			this->txtSpecX->Name = L"txtSpecX";
			this->txtSpecX->Size = System::Drawing::Size(91, 39);
			this->txtSpecX->TabIndex = 29;
			this->txtSpecX->Text = L"f, Гц";
			// 
			// txtSpecY
			// 
			this->txtSpecY->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtSpecY->AutoSize = true;
			this->txtSpecY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSpecY->Location = System::Drawing::Point(60, -368);
			this->txtSpecY->Name = L"txtSpecY";
			this->txtSpecY->Size = System::Drawing::Size(61, 39);
			this->txtSpecY->TabIndex = 28;
			this->txtSpecY->Text = L"|S|";
			// 
			// txtImpX
			// 
			this->txtImpX->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtImpX->AutoSize = true;
			this->txtImpX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtImpX->Location = System::Drawing::Point(-14, -364);
			this->txtImpX->Name = L"txtImpX";
			this->txtImpX->Size = System::Drawing::Size(68, 39);
			this->txtImpX->TabIndex = 27;
			this->txtImpX->Text = L"t, с";
			// 
			// txtImpY
			// 
			this->txtImpY->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtImpY->AutoSize = true;
			this->txtImpY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtImpY->Location = System::Drawing::Point(-61, -364);
			this->txtImpY->Name = L"txtImpY";
			this->txtImpY->Size = System::Drawing::Size(41, 39);
			this->txtImpY->TabIndex = 26;
			this->txtImpY->Text = L"A";
			// 
			// txtSpec
			// 
			this->txtSpec->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtSpec->AutoSize = true;
			this->txtSpec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSpec->Location = System::Drawing::Point(225, -368);
			this->txtSpec->Name = L"txtSpec";
			this->txtSpec->Size = System::Drawing::Size(139, 39);
			this->txtSpec->TabIndex = 25;
			this->txtSpec->Text = L"Спектр";
			// 
			// txtImp
			// 
			this->txtImp->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtImp->AutoSize = true;
			this->txtImp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtImp->Location = System::Drawing::Point(-234, -371);
			this->txtImp->Name = L"txtImp";
			this->txtImp->Size = System::Drawing::Size(167, 39);
			this->txtImp->TabIndex = 24;
			this->txtImp->Text = L"Импульс";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(258, 147);
			this->trackBar4->Maximum = 200;
			this->trackBar4->Minimum = 1;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(252, 45);
			this->trackBar4->TabIndex = 15;
			this->trackBar4->Value = 18;
			this->trackBar4->Visible = false;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &UI::trackBar4_ValueChanged);
			this->trackBar4->ValueChanged += gcnew System::EventHandler(this, &UI::trackBar4_ValueChanged);
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->BackColor = System::Drawing::Color::Transparent;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMessage->Location = System::Drawing::Point(23, 77);
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
			this->uiTrap->Location = System::Drawing::Point(398, 12);
			this->uiTrap->Name = L"uiTrap";
			this->uiTrap->Size = System::Drawing::Size(234, 93);
			this->uiTrap->TabIndex = 17;
			this->uiTrap->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->label8->Location = System::Drawing::Point(160, 85);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 39);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Гаусс";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->label2->Location = System::Drawing::Point(16, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 39);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Прям.";
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
			this->btnBack->Location = System::Drawing::Point(12, 123);
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
			this->uiGlobal->Controls->Add(this->lblDeltaT2);
			this->uiGlobal->Controls->Add(this->lblDeltaT1);
			this->uiGlobal->Controls->Add(this->label9);
			this->uiGlobal->Controls->Add(this->lblDeltaT);
			this->uiGlobal->Controls->Add(this->lblC2);
			this->uiGlobal->Controls->Add(this->lblC1);
			this->uiGlobal->Controls->Add(this->label3);
			this->uiGlobal->Controls->Add(this->lblSpecWidth2);
			this->uiGlobal->Controls->Add(this->lblSpecWidth1);
			this->uiGlobal->Location = System::Drawing::Point(945, 195);
			this->uiGlobal->Name = L"uiGlobal";
			this->uiGlobal->Size = System::Drawing::Size(280, 290);
			this->uiGlobal->TabIndex = 19;
			this->uiGlobal->Visible = false;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(9, 49);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(197, 37);
			this->label9->TabIndex = 27;
			this->label9->Text = L"С = ΔωΔt/2π";
			// 
			// lblDeltaT
			// 
			this->lblDeltaT->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblDeltaT->AutoSize = true;
			this->lblDeltaT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblDeltaT->Location = System::Drawing::Point(10, 7);
			this->lblDeltaT->Name = L"lblDeltaT";
			this->lblDeltaT->Size = System::Drawing::Size(118, 37);
			this->lblDeltaT->TabIndex = 26;
			this->lblDeltaT->Text = L"Δt = Δt";
			// 
			// lblC2
			// 
			this->lblC2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblC2->AutoSize = true;
			this->lblC2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F));
			this->lblC2->ForeColor = System::Drawing::Color::Red;
			this->lblC2->Location = System::Drawing::Point(143, 86);
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
			this->lblC1->ForeColor = System::Drawing::Color::Blue;
			this->lblC1->Location = System::Drawing::Point(9, 86);
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
			this->label3->Location = System::Drawing::Point(9, 135);
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
			this->lblSpecWidth2->Location = System::Drawing::Point(143, 172);
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
			this->lblSpecWidth1->ForeColor = System::Drawing::Color::Blue;
			this->lblSpecWidth1->Location = System::Drawing::Point(9, 172);
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
			this->uiHand->Location = System::Drawing::Point(638, 12);
			this->uiHand->Name = L"uiHand";
			this->uiHand->Size = System::Drawing::Size(140, 93);
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
			// uiFaq
			// 
			this->uiFaq->BackColor = System::Drawing::Color::Lime;
			this->uiFaq->Controls->Add(this->pbxFaq);
			this->uiFaq->Location = System::Drawing::Point(1001, 12);
			this->uiFaq->Name = L"uiFaq";
			this->uiFaq->Size = System::Drawing::Size(114, 67);
			this->uiFaq->TabIndex = 21;
			// 
			// pbxFaq
			// 
			this->pbxFaq->BackColor = System::Drawing::Color::White;
			this->pbxFaq->ImageLocation = L"zaglav.emf";
			this->pbxFaq->Location = System::Drawing::Point(3, 3);
			this->pbxFaq->Name = L"pbxFaq";
			this->pbxFaq->Size = System::Drawing::Size(100, 50);
			this->pbxFaq->TabIndex = 0;
			this->pbxFaq->TabStop = false;
			// 
			// uiAuthors
			// 
			this->uiAuthors->BackColor = System::Drawing::Color::Teal;
			this->uiAuthors->Location = System::Drawing::Point(1005, 89);
			this->uiAuthors->Name = L"uiAuthors";
			this->uiAuthors->Size = System::Drawing::Size(200, 100);
			this->uiAuthors->TabIndex = 22;
			// 
			// lblDeltaT1
			// 
			this->lblDeltaT1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblDeltaT1->AutoSize = true;
			this->lblDeltaT1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblDeltaT1->ForeColor = System::Drawing::Color::Blue;
			this->lblDeltaT1->Location = System::Drawing::Point(9, 7);
			this->lblDeltaT1->Name = L"lblDeltaT1";
			this->lblDeltaT1->Size = System::Drawing::Size(49, 37);
			this->lblDeltaT1->TabIndex = 28;
			this->lblDeltaT1->Text = L"Δt";
			// 
			// lblDeltaT2
			// 
			this->lblDeltaT2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->lblDeltaT2->AutoSize = true;
			this->lblDeltaT2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblDeltaT2->ForeColor = System::Drawing::Color::Red;
			this->lblDeltaT2->Location = System::Drawing::Point(79, 7);
			this->lblDeltaT2->Name = L"lblDeltaT2";
			this->lblDeltaT2->Size = System::Drawing::Size(49, 37);
			this->lblDeltaT2->TabIndex = 29;
			this->lblDeltaT2->Text = L"Δt";
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1249, 733);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->uiMainMenu);
			this->Controls->Add(this->uiAuthors);
			this->Controls->Add(this->uiFaq);
			this->Controls->Add(this->uiTrap);
			this->Controls->Add(this->uiGlobal);
			this->Controls->Add(this->uiHand);
			this->Controls->Add(this->uiGfx);
			this->Controls->Add(this->uiPreset);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->uiTrap->ResumeLayout(false);
			this->uiTrap->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trbTrap))->EndInit();
			this->uiGlobal->ResumeLayout(false);
			this->uiGlobal->PerformLayout();
			this->uiHand->ResumeLayout(false);
			this->uiHand->PerformLayout();
			this->uiFaq->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbxFaq))->EndInit();
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
		float SpecYMult;

		Point StartDef, FinishDef; // в реальных координатах
		PointF Start, Finish; // в экранных координатах
		float Radius; // в экранных координатах

		Pen ^FirstPen, ^SecondPen, ^_FirstPen, ^_SecondPen, ^AxisPen, ^FramePen;
		Brush ^brush;
		System::Drawing::Font ^font;

		int MsgTime;

		float ImpXMult, SpecXMult;

		float YAxis;

		System::Void RefreshColorScheme();

		System::Void AdaptToWindowSize(System::Object^  sender, System::EventArgs^  e);
		System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void Back();
		System::Void btnFaq_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnPreset_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnTrap_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnHand_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnAuthors_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void InvalidateAll();
		System::Void onClick(System::Object^  sender, System::EventArgs^  e);
		System::Void onImpPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
		System::Void onSpecPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
		PointF TransformImp(double x, double y, int index);
		PointF TransformSpec(double x, double y, int index);
		PointF BackTransformImp(float x, float y, int index);
		array<PointF>^ TransformPointsImp(int index, PaintEventArgs^ e);
		array<PointF>^ TransformPointsSpec(int index, PaintEventArgs^ e);
		
		void DrawImp(PaintEventArgs^ e);
		void DrawSpec(PaintEventArgs^ e);

		System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void trackBar2_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void trackBar4_ValueChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void PresetFuncChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void TrapWidthChanged(System::Object^  sender, System::EventArgs^  e);


		System::Void EnableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void DisableDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		System::Void HandDrawing(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

		System::Void ResetHand();
		System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e);
		void FinalizeHand();

		System::Void ShowMessage(String ^msg, bool);

		System::Void tmrMessage_Tick(System::Object^  sender, System::EventArgs^  e);
};
}
