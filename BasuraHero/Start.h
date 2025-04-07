#pragma once

#include <Windows.h>
#include <mmsystem.h>  // For PlaySound function
#include "User.h"  // Make sure User.h is correctly included
#include "Leaderboards.h"




#include <iostream>

#pragma comment(lib, "winmm.lib")  // Link the winmm.lib library for PlaySound

namespace BasuraHero {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace BasuraHero;


// Then you can simply do this



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

	

	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblLB;
	private: System::Windows::Forms::Label^ lblStart;
	private: System::Windows::Forms::PictureBox^ picQuote;
	private: System::Windows::Forms::PictureBox^ picHover;
	private: System::Windows::Forms::PictureBox^ picCreated;
	private: System::Windows::Forms::PictureBox^ picHover2;

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Start::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblLB = (gcnew System::Windows::Forms::Label());
			this->lblStart = (gcnew System::Windows::Forms::Label());
			this->picQuote = (gcnew System::Windows::Forms::PictureBox());
			this->picHover = (gcnew System::Windows::Forms::PictureBox());
			this->picCreated = (gcnew System::Windows::Forms::PictureBox());
			this->picHover2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picQuote))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHover))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCreated))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHover2))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label2->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(595, 645);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 38);
			this->label2->TabIndex = 1;
			this->label2->Text = L"QUIT";
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
			this->lblLB->Location = System::Drawing::Point(546, 555);
			this->lblLB->Name = L"lblLB";
			this->lblLB->Size = System::Drawing::Size(202, 32);
			this->lblLB->TabIndex = 2;
			this->lblLB->Text = L"LEADERBOARD";
			this->lblLB->Click += gcnew System::EventHandler(this, &Start::lblLB_Click);
			// 
			// lblStart
			// 
			this->lblStart->AutoSize = true;
			this->lblStart->BackColor = System::Drawing::Color::Transparent;
			this->lblStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblStart->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStart->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblStart->Location = System::Drawing::Point(581, 456);
			this->lblStart->Name = L"lblStart";
			this->lblStart->Size = System::Drawing::Size(113, 38);
			this->lblStart->TabIndex = 3;
			this->lblStart->Text = L"START";
			this->lblStart->Click += gcnew System::EventHandler(this, &Start::lblStart_Click);
			// 
			// picQuote
			// 
			this->picQuote->BackColor = System::Drawing::Color::Transparent;
			this->picQuote->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picQuote.BackgroundImage")));
			this->picQuote->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picQuote->Location = System::Drawing::Point(163, 127);
			this->picQuote->Name = L"picQuote";
			this->picQuote->Size = System::Drawing::Size(154, 132);
			this->picQuote->TabIndex = 4;
			this->picQuote->TabStop = false;
			this->picQuote->Visible = false;
			this->picQuote->Click += gcnew System::EventHandler(this, &Start::picQuote_Click);
			// 
			// picHover
			// 
			this->picHover->BackColor = System::Drawing::Color::Transparent;
			this->picHover->Cursor = System::Windows::Forms::Cursors::Hand;
			this->picHover->Location = System::Drawing::Point(55, 234);
			this->picHover->Name = L"picHover";
			this->picHover->Size = System::Drawing::Size(163, 311);
			this->picHover->TabIndex = 5;
			this->picHover->TabStop = false;
			this->picHover->Click += gcnew System::EventHandler(this, &Start::picHover_Click);
			this->picHover->MouseEnter += gcnew System::EventHandler(this, &Start::picHover_MouseEnter);
			this->picHover->MouseLeave += gcnew System::EventHandler(this, &Start::picHover_MouseLeave);
			// 
			// picCreated
			// 
			this->picCreated->BackColor = System::Drawing::Color::Transparent;
			this->picCreated->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCreated.BackgroundImage")));
			this->picCreated->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCreated->Location = System::Drawing::Point(971, 522);
			this->picCreated->Name = L"picCreated";
			this->picCreated->Size = System::Drawing::Size(325, 124);
			this->picCreated->TabIndex = 6;
			this->picCreated->TabStop = false;
			this->picCreated->Visible = false;
			this->picCreated->Click += gcnew System::EventHandler(this, &Start::picCreated_Click);
			// 
			// picHover2
			// 
			this->picHover2->BackColor = System::Drawing::Color::Transparent;
			this->picHover2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->picHover2->Location = System::Drawing::Point(1073, 205);
			this->picHover2->Name = L"picHover2";
			this->picHover2->Size = System::Drawing::Size(163, 311);
			this->picHover2->TabIndex = 7;
			this->picHover2->TabStop = false;
			this->picHover2->Click += gcnew System::EventHandler(this, &Start::picHover2_Click);
			this->picHover2->MouseEnter += gcnew System::EventHandler(this, &Start::picHover2_MouseEnter);
			this->picHover2->MouseLeave += gcnew System::EventHandler(this, &Start::picHover2_MouseLeave);
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1280, 760);
			this->Controls->Add(this->picHover2);
			this->Controls->Add(this->picCreated);
			this->Controls->Add(this->picQuote);
			this->Controls->Add(this->picHover);
			this->Controls->Add(this->lblStart);
			this->Controls->Add(this->lblLB);
			this->Controls->Add(this->label2);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimizeBox = false;
			this->Name = L"Start";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BASURA HERO";
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picQuote))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHover))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCreated))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHover2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Start_Load(System::Object^ sender, System::EventArgs^ e) {
		// Loop the background music infinitely when the form loads
		PlaySound(TEXT("ResourcesUsed\\journeybg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show confirmation message box
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to quit?",
			"Confirm Exit",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		// If user clicks Yes, play quit sound and exit
		if (result == System::Windows::Forms::DialogResult::Yes) {
			PlaySound(TEXT("ResourcesUsed\\quitbg.wav"), NULL, SND_FILENAME | SND_SYNC);
			Application::Exit();
		}
	}


private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	

}







private: System::Void lblStart_Click(System::Object^ sender, System::EventArgs^ e) {
	PlaySound(NULL, NULL, SND_PURGE);

	// Close the Start form with an OK result so main() knows to open User form
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}






private: System::Void picQuote_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void picHover_Click(System::Object^ sender, System::EventArgs^ e) {
}

	   private: System::Void picHover_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		   // Show picQuote when the mouse hovers over picHover
		   picQuote->Visible = true;
	   }

private: System::Void picHover_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	// Hide picQuote when the mouse leaves picHover
	picQuote->Visible = false;
}



private: System::Void picHover2_Click(System::Object^ sender, System::EventArgs^ e) {
	   }
	   private: System::Void picHover2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		   // Show picCreated when the mouse hovers over picHover2
		   picCreated->Visible = true;
	   }

private: System::Void picHover2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	// Hide picCreated when the mouse leaves picHover2
	picCreated->Visible = false;
}



private: System::Void picCreated_Click(System::Object^ sender, System::EventArgs^ e) {
}

public: bool switchToLeaderboard = false;

private: System::Void lblLB_Click(System::Object^ sender, System::EventArgs^ e) {
	PlaySound(NULL, NULL, SND_PURGE);
	this->switchToLeaderboard = true;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

};
}
