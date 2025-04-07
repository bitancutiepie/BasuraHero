#pragma once

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
	private: System::Windows::Forms::Label^ lblMenu;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->lblMenu = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblMenu
			// 
			this->lblMenu->AutoSize = true;
			this->lblMenu->BackColor = System::Drawing::Color::Transparent;
			this->lblMenu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblMenu->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMenu->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblMenu->Location = System::Drawing::Point(235, 749);
			this->lblMenu->Name = L"lblMenu";
			this->lblMenu->Size = System::Drawing::Size(151, 25);
			this->lblMenu->TabIndex = 0;
			this->lblMenu->Text = L"MAIN MENU";
			this->lblMenu->Click += gcnew System::EventHandler(this, &Leaderboards::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(460, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(128, 50);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Leaderboards::pictureBox1_Click);
			// 
			// Leaderboards
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(600, 800);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblMenu);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Leaderboards";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Leaderboards";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
	public: bool switchToStart = false;

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->switchToStart = true;
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

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
