#pragma once
namespace BasuraHero {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for GameOver
	/// </summary>
	public ref class GameOver : public System::Windows::Forms::Form
	{
	public:
		GameOver(void)
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
		~GameOver()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ GO_menubtn;
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameOver::typeid));
			this->GO_menubtn = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// GO_menubtn
			// 
			this->GO_menubtn->AutoSize = true;
			this->GO_menubtn->BackColor = System::Drawing::Color::Transparent;
			this->GO_menubtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GO_menubtn->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GO_menubtn->ForeColor = System::Drawing::Color::Transparent;
			this->GO_menubtn->Location = System::Drawing::Point(652, 483);
			this->GO_menubtn->Name = L"GO_menubtn";
			this->GO_menubtn->Size = System::Drawing::Size(105, 41);
			this->GO_menubtn->TabIndex = 0;
			this->GO_menubtn->Text = L"Menu";
			this->GO_menubtn->Click += gcnew System::EventHandler(this, &GameOver::GO_menubtn_Click);
			// 
			// GameOver
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->GO_menubtn);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GameOver";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GameOver";
			this->Load += gcnew System::EventHandler(this, &GameOver::GameOver_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameOver::GameOver_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GameOver_Load(System::Object^ sender, System::EventArgs^ e) {
		this->switchToStart = false;
		this->KeyPreview = true; // Important for KeyDown events
		this->Focus();
	}

	public: bool switchToStart = false;  // Public so it can be accessed in main

	private: System::Void GO_menubtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MenuButtonAction();
	}

		   // Added function to handle the menu action
	private: void MenuButtonAction() {
		

		this->switchToStart = true; // Set the flag
		this->DialogResult = System::Windows::Forms::DialogResult::OK; // Signal the main loop
		this->Close(); // Close the form
		Console::WriteLine("MenuButtonAction triggered");
		Console::WriteLine("GameOver form closed with switchToStart = " + this->switchToStart);
	}


		   // Added keyboard handler for accessibility
	private: System::Void GameOver_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Allow pressing Enter or Escape to go to menu
		if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Escape) {
			MenuButtonAction();
		}
	}
	};
}