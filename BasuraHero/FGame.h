#pragma once
#include "GameOver.h"

namespace BasuraHero {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class FGame : public System::Windows::Forms::Form
    {
    public:
        FGame(void)
        {
            InitializeComponent();

            // Setup timers
            gameTime = 5;
            countdownTimer = gcnew System::Windows::Forms::Timer();
            countdownTimer->Interval = 1000;
            countdownTimer->Tick += gcnew System::EventHandler(this, &FGame::countdownTimer_Tick);

            fallTimer = gcnew System::Windows::Forms::Timer();
            fallTimer->Interval = 30;
            fallTimer->Tick += gcnew System::EventHandler(this, &FGame::fallTimer_Tick);

            spawnTimer = gcnew System::Windows::Forms::Timer();
            spawnTimer->Interval = 1500;
            spawnTimer->Tick += gcnew System::EventHandler(this, &FGame::spawnTimer_Tick);
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
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ lblTime;
        System::Windows::Forms::Timer^ countdownTimer;
        System::Windows::Forms::Timer^ fallTimer;
        System::Windows::Forms::Timer^ spawnTimer;
        System::Windows::Forms::PictureBox^ pictureBox1;
        int gameTime;

        void ShowGameOver()
        {
            MessageBox::Show("Game Over! Time's up!");
            GameOver^ gameOverForm = gcnew GameOver();
            gameOverForm->ShowDialog();
            this->Close();
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FGame::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->lblTime = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();

            // label1
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 24));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(1154, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(0, 36);
            this->label1->TabIndex = 0;

            // lblTime
            this->lblTime->AutoSize = true;
            this->lblTime->BackColor = System::Drawing::Color::Transparent;
            this->lblTime->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 27.75F));
            this->lblTime->ForeColor = System::Drawing::Color::White;
            this->lblTime->Location = System::Drawing::Point(1160, 4);
            this->lblTime->Name = L"lblTime";
            this->lblTime->Size = System::Drawing::Size(0, 41);
            this->lblTime->TabIndex = 1;

            // pictureBox1
            this->pictureBox1->Location = System::Drawing::Point(292, 180);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(100, 50);
            this->pictureBox1->TabIndex = 2;
            this->pictureBox1->TabStop = false;

            // FGame
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1280, 720);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->lblTime);
            this->Controls->Add(this->label1);
            this->DoubleBuffered = true;
            this->Name = L"FGame";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"FGame";
            this->Load += gcnew System::EventHandler(this, &FGame::FGame_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void FGame_Load(System::Object^ sender, System::EventArgs^ e)
    {
        countdownTimer->Start();
        fallTimer->Start();
        spawnTimer->Start();
    }

    private: System::Void countdownTimer_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        gameTime--;
        lblTime->Text = gameTime.ToString();

        if (gameTime <= 0)
        {
            countdownTimer->Stop();
            fallTimer->Stop();
            spawnTimer->Stop();
            ShowGameOver();
        }
    }

    private: System::Void fallTimer_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        for each (Control ^ ctrl in this->Controls)
        {
            if (ctrl->Tag != nullptr && ctrl->Tag->ToString() == "falling")
            {
                ctrl->Top += 5;
                if (ctrl->Top > this->Height)
                {
                    this->Controls->Remove(ctrl);
                    delete ctrl;
                    break;
                }
            }
        }
    }

    private: System::Void spawnTimer_Tick(System::Object^ sender, System::EventArgs^ e)
    {
        SpawnGarbage();
    }

           void SpawnGarbage()
           {
               Random^ rand = gcnew Random();
               int randomIndex = rand->Next(1, 10);
               String^ folderPath = "ResourcesUsed\\GarbageIcons\\";
               String^ imagePath = folderPath + randomIndex.ToString() + ".png";

               PictureBox^ garbage = gcnew PictureBox();
               garbage->Size = System::Drawing::Size(50, 50);
               garbage->SizeMode = PictureBoxSizeMode::StretchImage;
               garbage->BackColor = Color::Transparent;

               try {
                   garbage->Image = Image::FromFile(imagePath);
               }
               catch (...) {
                   MessageBox::Show("Image not found: " + imagePath);
                   return;
               }

               garbage->Location = Point(rand->Next(0, this->Width - 50), 0);
               garbage->Tag = "falling";
               this->Controls->Add(garbage);
               garbage->BringToFront();
           }

    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}

    };
}
