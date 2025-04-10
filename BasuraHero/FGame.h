#pragma once

#include "GameOver.h"

namespace BasuraHero {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for FGame
    /// </summary>
    public ref class FGame : public System::Windows::Forms::Form
    {
    public:
        FGame(void)
        {
            InitializeComponent();
            gameTime = 5;  // Set initial time
            countdownTimer = gcnew System::Windows::Forms::Timer();
            countdownTimer->Interval = 1000;  // Timer interval set to 1 second
            countdownTimer->Tick += gcnew System::EventHandler(this, &FGame::countdownTimer_Tick);
        }

    protected:
        ~FGame()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ lblTime;
        System::Windows::Forms::Timer^ countdownTimer;
        int gameTime;  // Variable to hold the time left

        // Game Over form to display when time runs out
        void ShowGameOver()
        {
            // Show a message box with Game Over
            MessageBox::Show("Game Over! Time's up!");

            // Now, open the GameOver form
            GameOver^ gameOverForm = gcnew GameOver();
            gameOverForm->ShowDialog();  // Display the GameOver form as a modal dialog
            this->Close();  // Close the current form (FGame)
        }

    protected:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FGame::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->lblTime = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(1154, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(0, 36);
            this->label1->TabIndex = 0;
            // 
            // lblTime
            // 
            this->lblTime->AutoSize = true;
            this->lblTime->BackColor = System::Drawing::Color::Transparent;
            this->lblTime->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTime->ForeColor = System::Drawing::Color::White;
            this->lblTime->Location = System::Drawing::Point(1160, 4);
            this->lblTime->Name = L"lblTime";
            this->lblTime->Size = System::Drawing::Size(64, 41);
            this->lblTime->TabIndex = 1;
            this->lblTime->Text = L"60";  // Display the initial time
            // 
            // FGame
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1280, 720);
            this->Controls->Add(this->lblTime);
            this->Controls->Add(this->label1);
            this->DoubleBuffered = true;
            this->Name = L"FGame";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"FGame";
            this->Load += gcnew System::EventHandler(this, &FGame::FGame_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void FGame_Load(System::Object^ sender, System::EventArgs^ e)
    {
        countdownTimer->Start();  // Start the timer when the form loads
    }

    private: System::Void countdownTimer_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        gameTime--;  // Decrease time by 1 second
        lblTime->Text = gameTime.ToString();  // Update the label with the remaining time

        // If time reaches 0, stop the timer and show Game Over
        if (gameTime <= 0)
        {
            countdownTimer->Stop();
            ShowGameOver();  // Show game over message or switch to Game Over screen
        }
    }

    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Add logic for clicking on pictureBox if needed
    }
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Add any additional logic for label click if needed
    }

    };
}
