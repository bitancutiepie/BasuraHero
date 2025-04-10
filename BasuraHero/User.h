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


	private: System::Windows::Forms::PictureBox^ lblMenu;
	private: System::Windows::Forms::Label^ label1;
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
			this->lblMenu = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lblMenu))->BeginInit();
			this->SuspendLayout();
			// 
			// txtUser
			// 
			this->txtUser->BackColor = System::Drawing::Color::Lime;
			this->txtUser->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUser->Location = System::Drawing::Point(206, 326);
			this->txtUser->Name = L"txtUser";
			this->txtUser->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtUser->Size = System::Drawing::Size(205, 28);
			this->txtUser->TabIndex = 0;
			this->txtUser->TextChanged += gcnew System::EventHandler(this, &User::textBox1_TextChanged);
			// 
			// comboGender
			// 
			this->comboGender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboGender->FormattingEnabled = true;
			this->comboGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->comboGender->Location = System::Drawing::Point(243, 554);
			this->comboGender->Name = L"comboGender";
			this->comboGender->Size = System::Drawing::Size(121, 33);
			this->comboGender->TabIndex = 1;
			this->comboGender->SelectedIndexChanged += gcnew System::EventHandler(this, &User::comboBox1_SelectedIndexChanged);
			// 
			// lblMenu
			// 
			this->lblMenu->BackColor = System::Drawing::Color::Transparent;
			this->lblMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblMenu.BackgroundImage")));
			this->lblMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->lblMenu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblMenu->Location = System::Drawing::Point(440, 690);
			this->lblMenu->Name = L"lblMenu";
			this->lblMenu->Size = System::Drawing::Size(165, 84);
			this->lblMenu->TabIndex = 2;
			this->lblMenu->TabStop = false;
			this->lblMenu->Click += gcnew System::EventHandler(this, &User::lblMenu_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(265, 714);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(600, 800);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMenu);
			this->Controls->Add(this->comboGender);
			this->Controls->Add(this->txtUser);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"User";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"User";
			this->Load += gcnew System::EventHandler(this, &User::User_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lblMenu))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void User_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

public: bool switchToStart = false;

private: System::Void lblMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToStart = true;
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}





















private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
