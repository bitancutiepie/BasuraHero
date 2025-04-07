#pragma once

#include <Windows.h>
#include <mmsystem.h>  
#pragma comment(lib, "winmm.lib") 


namespace BasuraHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	


	/// <summary>
	/// Summary for Leaderboards
	/// </summary>
	public ref class Leaderboards : public System::Windows::Forms::Form
	{
	public:
		Leaderboards(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Leaderboards()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ exitbtn;
	private: System::Media::SoundPlayer^ lbSound;


	



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Leaderboards::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->exitbtn = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exitbtn))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(33, 705);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(175, 50);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Leaderboards::pictureBox2_Click);
			// 
			// exitbtn
			// 
			this->exitbtn->BackColor = System::Drawing::Color::Transparent;
			this->exitbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exitbtn->Location = System::Drawing::Point(412, 705);
			this->exitbtn->Name = L"exitbtn";
			this->exitbtn->Size = System::Drawing::Size(163, 50);
			this->exitbtn->TabIndex = 3;
			this->exitbtn->TabStop = false;
			this->exitbtn->Click += gcnew System::EventHandler(this, &Leaderboards::exitbtn_Click);
			// 
			// Leaderboards
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(600, 800);
			this->Controls->Add(this->exitbtn);
			this->Controls->Add(this->pictureBox2);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Leaderboards";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Leaderboards";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exitbtn))->EndInit();
			this->ResumeLayout(false);
			this->Load += gcnew System::EventHandler(this, &Leaderboards::Leaderboards_Load);


		}
#pragma endregion

	private: System::Void Leaderboards_Load(System::Object^ sender, System::EventArgs^ e) {
		lbSound = gcnew System::Media::SoundPlayer("ResourcesUsed\\lbSound.wav");

		try {
			lbSound->Load();
			lbSound->Play(); // Use PlayLooping() if you want it to play continuously
		}
		catch (Exception^ ex) {
			MessageBox::Show("Sound failed to play: " + ex->Message);
		}
	}

	
	
	public: bool switchToStart = false;

	
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to quit?",
			"Confirm Exit",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		Application::Exit();
	}
private: System::Void btnMenu_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToStart = true;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();

}
private: System::Void exitbtn_Click(System::Object^ sender, System::EventArgs^ e) {

	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Are you sure you want to quit?",
		"Confirm Exit",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	Application::Exit();
}
};
}
