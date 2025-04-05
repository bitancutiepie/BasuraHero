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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::PictureBox^ lblMenu;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->lblMenu = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lblMenu))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Lime;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(133, 265);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(145, 29);
			this->textBox1->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->comboBox1->Location = System::Drawing::Point(147, 449);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &User::comboBox1_SelectedIndexChanged);
			// 
			// lblMenu
			// 
			this->lblMenu->BackColor = System::Drawing::Color::Transparent;
			this->lblMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblMenu.BackgroundImage")));
			this->lblMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->lblMenu->Location = System::Drawing::Point(294, 522);
			this->lblMenu->Name = L"lblMenu";
			this->lblMenu->Size = System::Drawing::Size(115, 55);
			this->lblMenu->TabIndex = 2;
			this->lblMenu->TabStop = false;
			this->lblMenu->Click += gcnew System::EventHandler(this, &User::lblMenu_Click);
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(400, 600);
			this->Controls->Add(this->lblMenu);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->DoubleBuffered = true;
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


private: System::Void lblMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	
}



















};
}
