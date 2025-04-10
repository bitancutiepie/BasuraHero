#pragma once






// This includes the User form class
#include "User.h"
#include "Start.h" 
namespace BasuraHero {

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for User
	/// </summary>
	public ref class User : public System::Windows::Forms::Form

	{

	
	
	public:
		User(void)
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
		~User()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtUser;
	private: System::Windows::Forms::ComboBox^ comboGender;
	protected:



	private: System::Windows::Forms::Label^ btnMenu;
	private: System::Windows::Forms::PictureBox^ picF;
	private: System::Windows::Forms::PictureBox^ picM;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(User::typeid));
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->comboGender = (gcnew System::Windows::Forms::ComboBox());
			this->btnMenu = (gcnew System::Windows::Forms::Label());
			this->picF = (gcnew System::Windows::Forms::PictureBox());
			this->picM = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picF))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picM))->BeginInit();
			this->SuspendLayout();
			// 
			// txtUser
			// 
			this->txtUser->BackColor = System::Drawing::Color::White;
			this->txtUser->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUser->Location = System::Drawing::Point(210, 326);
			this->txtUser->Name = L"txtUser";
			this->txtUser->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtUser->Size = System::Drawing::Size(193, 28);
			this->txtUser->TabIndex = 0;
			this->txtUser->TextChanged += gcnew System::EventHandler(this, &User::textBox1_TextChanged);
			// 
			// comboGender
			// 
			this->comboGender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboGender->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboGender->FormattingEnabled = true;
			this->comboGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->comboGender->Location = System::Drawing::Point(243, 558);
			this->comboGender->Name = L"comboGender";
			this->comboGender->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->comboGender->Size = System::Drawing::Size(121, 38);
			this->comboGender->TabIndex = 1;
			this->comboGender->SelectedIndexChanged += gcnew System::EventHandler(this, &User::comboBox1_SelectedIndexChanged);
			// 
			// btnMenu
			// 
			this->btnMenu->AutoSize = true;
			this->btnMenu->BackColor = System::Drawing::Color::Transparent;
			this->btnMenu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMenu->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMenu->ForeColor = System::Drawing::Color::White;
			this->btnMenu->Location = System::Drawing::Point(270, 713);
			this->btnMenu->Name = L"btnMenu";
			this->btnMenu->Size = System::Drawing::Size(94, 36);
			this->btnMenu->TabIndex = 3;
			this->btnMenu->Text = L"MENU";
			this->btnMenu->Click += gcnew System::EventHandler(this, &User::btnMenu_Click);
			// 
			// picF
			// 
			this->picF->BackColor = System::Drawing::Color::Transparent;
			this->picF->Cursor = System::Windows::Forms::Cursors::Hand;
			this->picF->Location = System::Drawing::Point(220, 476);
			this->picF->Name = L"picF";
			this->picF->Size = System::Drawing::Size(62, 62);
			this->picF->TabIndex = 4;
			this->picF->TabStop = false;
			this->picF->Click += gcnew System::EventHandler(this, &User::picF_Click);
			// 
			// picM
			// 
			this->picM->BackColor = System::Drawing::Color::Transparent;
			this->picM->Cursor = System::Windows::Forms::Cursors::Hand;
			this->picM->Location = System::Drawing::Point(326, 476);
			this->picM->Name = L"picM";
			this->picM->Size = System::Drawing::Size(62, 62);
			this->picM->TabIndex = 5;
			this->picM->TabStop = false;
			this->picM->Click += gcnew System::EventHandler(this, &User::picM_Click);
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(600, 800);
			this->Controls->Add(this->picM);
			this->Controls->Add(this->picF);
			this->Controls->Add(this->btnMenu);
			this->Controls->Add(this->comboGender);
			this->Controls->Add(this->txtUser);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"User";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"User";
			this->Load += gcnew System::EventHandler(this, &User::User_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picF))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picM))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void User_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}



private: System::Void lblMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToStart = true;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}





















private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	   public: bool switchToStart = false;

private: System::Void btnMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToStart = true;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
private: System::Void picF_Click(System::Object^ sender, System::EventArgs^ e) {
	this->comboGender->SelectedIndex = 1; // Selects the first item (Female)
}
private: System::Void picM_Click(System::Object^ sender, System::EventArgs^ e) {
	this->comboGender->SelectedIndex = 0; // male
}
};
}
