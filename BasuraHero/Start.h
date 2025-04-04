#pragma once

#include <Windows.h>
#include <mmsystem.h>  // For PlaySound function
#include <iostream>

#pragma comment(lib, "winmm.lib")  // Link the winmm.lib library for PlaySound

namespace BasuraHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(void)
		{
			InitializeComponent();
			// Add the constructor code here
		}

	protected:
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblLB;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Start::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblLB = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(542, 512);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Start Game";
			this->label1->Click += gcnew System::EventHandler(this, &Start::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label2->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(595, 659);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 38);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Quit";
			this->label2->Click += gcnew System::EventHandler(this, &Start::label2_Click);
			// 
			// lblLB
			// 
			this->lblLB->AutoSize = true;
			this->lblLB->BackColor = System::Drawing::Color::Transparent;
			this->lblLB->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblLB->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLB->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblLB->Location = System::Drawing::Point(543, 593);
			this->lblLB->Name = L"lblLB";
			this->lblLB->Size = System::Drawing::Size(175, 32);
			this->lblLB->TabIndex = 2;
			this->lblLB->Text = L"Leaderboard";
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1280, 760);
			this->Controls->Add(this->lblLB);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Start";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Start";
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Start_Load(System::Object^ sender, System::EventArgs^ e) {
		// Loop the background music infinitely when the form loads
		PlaySound(TEXT("D:\\Programs\\repos\\BasuraHero\\BasuraHero\\ResourcesUsed\\gamebg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Play quit sound
		PlaySound(TEXT("D:\\Programs\\repos\\BasuraHero\\BasuraHero\\ResourcesUsed\\quitbg.wav"), NULL, SND_FILENAME | SND_SYNC);

		// Exit the application after the sound finishes
		Application::Exit();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
