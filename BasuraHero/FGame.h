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
            gameTime = 60;
            countdownTimer = gcnew System::Windows::Forms::Timer();
            countdownTimer->Interval = 1000;
            countdownTimer->Tick += gcnew System::EventHandler(this, &FGame::countdownTimer_Tick);

            fallTimer = gcnew System::Windows::Forms::Timer();
            fallTimer->Interval = 45;
            fallTimer->Tick += gcnew System::EventHandler(this, &FGame::fallTimer_Tick);

            spawnTimer = gcnew System::Windows::Forms::Timer();
            spawnTimer->Interval = 1500;
            spawnTimer->Tick += gcnew System::EventHandler(this, &FGame::spawnTimer_Tick);

            // Setup powerup timers
            scoreMultiplierTimer = gcnew System::Windows::Forms::Timer();
            scoreMultiplierTimer->Interval = 5000; // 5 seconds
            scoreMultiplierTimer->Tick += gcnew System::EventHandler(this, &FGame::scoreMultiplierTimer_Tick);

            slowDownTimer = gcnew System::Windows::Forms::Timer();
            slowDownTimer->Interval = 5000; // 5 seconds
            slowDownTimer->Tick += gcnew System::EventHandler(this, &FGame::slowDownTimer_Tick);

            // Initialize cursor-related variables
            activeBin = BinType::None;

            // Initialize score
            playerScore = 0;
            scoreMultiplier = 1;

            // Initialize lives
            playerLives = 3;

            // Save original fall speed
            originalFallSpeed = 5;
            currentFallSpeed = originalFallSpeed;
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
        System::Windows::Forms::Timer^ scoreMultiplierTimer;
        System::Windows::Forms::Timer^ slowDownTimer;
    private: System::Windows::Forms::PictureBox^ bio;
    private: System::Windows::Forms::PictureBox^ nonbio;
    private: System::Windows::Forms::PictureBox^ recyclable;
    private: System::Windows::Forms::Label^ scorelbl;
    private: System::Windows::Forms::PictureBox^ heart1;
    private: System::Windows::Forms::PictureBox^ heart2;
    private: System::Windows::Forms::PictureBox^ heart3;

           // Enum to track which bin is selected
           enum class BinType {
               None,
               Bio,
               NonBio,
               Recyclable
           };

           // Enum to track special items
           enum class SpecialItemType {
               None,
               ScoreMultiplier,
               SlowDown,
               Bomb
           };

           BinType activeBin;
           int gameTime;
           int playerScore; // Player's score
           int playerLives; // Player's lives
           int scoreMultiplier; // Score multiplier for powerup
           int originalFallSpeed; // Original fall speed
    private: System::Windows::Forms::Label^ binTxt;
    private: System::Windows::Forms::Label^ powerTxt;
           int currentFallSpeed; // Current fall speed

           void UpdateBinText()
           {
               switch (activeBin)
               {
               case BinType::Bio:
                   binTxt->Text = "BIO";
                   binTxt->ForeColor = System::Drawing::Color::LightGreen;
                   break;
               case BinType::NonBio:
                   binTxt->Text = "NONBIO";
                   binTxt->ForeColor = System::Drawing::Color::LightBlue;
                   break;
               case BinType::Recyclable:
                   binTxt->Text = "RECYCLABLE";
                   binTxt->ForeColor = System::Drawing::Color::Yellow;
                   break;
               default:
                   binTxt->Text = "NONE";
                   binTxt->ForeColor = System::Drawing::Color::White;
                   break;
               }
           }

           // Function to update powerTxt based on active powerups
           void UpdatePowerupText()
           {
               bool hasPowerup = false;

               // Check for active score multiplier
               if (scoreMultiplier > 1)
               {
                   powerTxt->Text = "X2 SCORE";
                   powerTxt->ForeColor = System::Drawing::Color::Yellow;
                   hasPowerup = true;
               }

               // Check for active slow down
               if (currentFallSpeed < originalFallSpeed)
               {
                   powerTxt->Text = "SLOWED";
                   powerTxt->ForeColor = System::Drawing::Color::Cyan;
                   hasPowerup = true;
               }

               // If no powerups are active
               if (!hasPowerup)
               {
                   powerTxt->Text = "NONE";
                   powerTxt->ForeColor = System::Drawing::Color::White;
               }
           }

           void ShowGameOver()
           {
               this->Hide();
               GameOver^ gameOverForm = gcnew GameOver();
               gameOverForm->ShowDialog();
           }

           // Function to handle losing a life
           void LoseLife()
           {
               playerLives--;

               // Update heart visibility based on remaining lives
               UpdateHeartDisplay();

               // Check if game over
               if (playerLives <= 0) {
                   countdownTimer->Stop();
                   fallTimer->Stop();
                   spawnTimer->Stop();
                   ShowGameOver();
               }
           }

           // Function to update heart display based on remaining lives
           void UpdateHeartDisplay()
           {
               // Hide hearts based on remaining lives
               heart1->Visible = (playerLives >= 1);
               heart2->Visible = (playerLives >= 2);
               heart3->Visible = (playerLives >= 3);
           }

           // Helper function to set custom cursor based on bin type
           void SetCustomCursor(BinType binType)
           {
               try {
                   String^ cursorPath = "D:\\Programs\\repos\\BasuraHero\\BasuraHero\\ResourcesUsed\\GarbageIcons\\";

                   // Set the correct cursor file based on bin type
                   switch (binType) {
                   case BinType::Bio:
                       cursorPath += "bioCur.png";
                       break;
                   case BinType::NonBio:
                       cursorPath += "nonbioCur.png";
                       break;
                   case BinType::Recyclable:
                       cursorPath += "recyCur.png";
                       break;
                   default:
                       // Reset to default cursor if None
                       this->Cursor = System::Windows::Forms::Cursors::Default;
                       return;
                   }

                   // Load image from file
                   Bitmap^ originalBmp = gcnew Bitmap(cursorPath);

                   // Resize the bitmap to larger cursor size (64x64)
                   Bitmap^ cursorBmp = gcnew Bitmap(originalBmp, 64, 64);

                   // Define hotspot (center of the image)
                   System::Drawing::Point hotspot(32, 32);

                   // Create cursor from bitmap
                   IntPtr hIcon = cursorBmp->GetHicon();
                   System::Windows::Forms::Cursor^ customCursor = gcnew System::Windows::Forms::Cursor(hIcon);

                   // Set the form's cursor
                   this->Cursor = customCursor;

                   // Clean up
                   DestroyIcon(hIcon);
                   delete originalBmp;
                   delete cursorBmp;
               }
               catch (Exception^ ex) {
                   MessageBox::Show("Error creating custom cursor: " + ex->Message);
               }
           }

           // Function to update the score display
           void UpdateScoreDisplay()
           {
               // Format the score with leading zeros
               scorelbl->Text = playerScore.ToString("00000");

               // If score multiplier is active, change the color to yellow
               if (scoreMultiplier > 1) {
                   scorelbl->ForeColor = System::Drawing::Color::Yellow;
               }
               else {
                   scorelbl->ForeColor = System::Drawing::SystemColors::ControlLightLight;
               }
           }

           // Handle score multiplier timer tick (ends the multiplier effect)
           void scoreMultiplierTimer_Tick(System::Object^ sender, System::EventArgs^ e)
           {
               scoreMultiplierTimer->Stop();
               scoreMultiplier = 1; // Reset multiplier
               UpdateScoreDisplay(); // Reset color
               UpdatePowerupText(); // Update powerup text
           }

           // Handle slow down timer tick (ends the slow down effect)
           void slowDownTimer_Tick(System::Object^ sender, System::EventArgs^ e)
           {
               slowDownTimer->Stop();
               currentFallSpeed = originalFallSpeed; // Reset fall speed
               UpdatePowerupText(); // Update powerup text
           }

           // Helper function to determine special item type from tag
           SpecialItemType GetSpecialItemType(String^ tag)
           {
               if (tag->Contains("multiplier"))
                   return SpecialItemType::ScoreMultiplier;
               else if (tag->Contains("slowdown"))
                   return SpecialItemType::SlowDown;
               else if (tag->Contains("bomb"))
                   return SpecialItemType::Bomb;

               return SpecialItemType::None;
           }

           // Method to handle powerup effects
           void ApplyPowerUp(SpecialItemType powerupType)
           {
               switch (powerupType)
               {
               case SpecialItemType::ScoreMultiplier:
                   // Double score multiplier
                   scoreMultiplier = 2;
                   // Update score display for visual feedback
                   UpdateScoreDisplay();
                   // Reset any active multiplier timer
                   scoreMultiplierTimer->Stop();
                   // Start the multiplier countdown
                   scoreMultiplierTimer->Start();
                   UpdatePowerupText(); // Update powerup text
                   break;

               case SpecialItemType::SlowDown:
                   // Slow down falling objects
                   currentFallSpeed = originalFallSpeed / 2;
                   // Reset any active slow down timer
                   slowDownTimer->Stop();
                   // Start the slow down countdown
                   slowDownTimer->Start();
                   UpdatePowerupText(); // Update powerup text
                   break;

               case SpecialItemType::Bomb:
                   // Bomb reduces player's lives
                   LoseLife();
                   break;
               }
           }

           // Helper function to determine garbage type from file index
           BinType GetGarbageType(int fileIndex)
           {
               if (fileIndex >= 1 && fileIndex <= 3)
                   return BinType::Bio;
               else if (fileIndex >= 4 && fileIndex <= 6)
                   return BinType::NonBio;
               else if (fileIndex >= 7 && fileIndex <= 9)
                   return BinType::Recyclable;

               return BinType::None; // Default
           }

           // P/Invoke for proper icon cleanup
           [System::Runtime::InteropServices::DllImport("user32.dll", CharSet = System::Runtime::InteropServices::CharSet::Auto)]
               static bool DestroyIcon(IntPtr handle);

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FGame::typeid));
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->lblTime = (gcnew System::Windows::Forms::Label());
               this->bio = (gcnew System::Windows::Forms::PictureBox());
               this->nonbio = (gcnew System::Windows::Forms::PictureBox());
               this->recyclable = (gcnew System::Windows::Forms::PictureBox());
               this->scorelbl = (gcnew System::Windows::Forms::Label());
               this->heart1 = (gcnew System::Windows::Forms::PictureBox());
               this->heart2 = (gcnew System::Windows::Forms::PictureBox());
               this->heart3 = (gcnew System::Windows::Forms::PictureBox());
               this->binTxt = (gcnew System::Windows::Forms::Label());
               this->powerTxt = (gcnew System::Windows::Forms::Label());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bio))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nonbio))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recyclable))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart1))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart2))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart3))->BeginInit();
               this->SuspendLayout();
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->BackColor = System::Drawing::Color::Transparent;
               this->label1->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 24));
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
               this->lblTime->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 27.75F));
               this->lblTime->ForeColor = System::Drawing::Color::White;
               this->lblTime->Location = System::Drawing::Point(1160, 4);
               this->lblTime->Name = L"lblTime";
               this->lblTime->Size = System::Drawing::Size(0, 41);
               this->lblTime->TabIndex = 1;
               // 
               // bio
               // 
               this->bio->BackColor = System::Drawing::Color::Transparent;
               this->bio->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bio.BackgroundImage")));
               this->bio->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->bio->Location = System::Drawing::Point(448, 549);
               this->bio->Name = L"bio";
               this->bio->Size = System::Drawing::Size(139, 170);
               this->bio->TabIndex = 2;
               this->bio->TabStop = false;
               this->bio->Click += gcnew System::EventHandler(this, &FGame::bio_Click);
               // 
               // nonbio
               // 
               this->nonbio->BackColor = System::Drawing::Color::Transparent;
               this->nonbio->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nonbio.BackgroundImage")));
               this->nonbio->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->nonbio->Location = System::Drawing::Point(593, 553);
               this->nonbio->Name = L"nonbio";
               this->nonbio->Size = System::Drawing::Size(136, 166);
               this->nonbio->TabIndex = 3;
               this->nonbio->TabStop = false;
               this->nonbio->Click += gcnew System::EventHandler(this, &FGame::nonbio_Click);
               // 
               // recyclable
               // 
               this->recyclable->BackColor = System::Drawing::Color::Transparent;
               this->recyclable->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"recyclable.BackgroundImage")));
               this->recyclable->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->recyclable->Location = System::Drawing::Point(735, 553);
               this->recyclable->Name = L"recyclable";
               this->recyclable->Size = System::Drawing::Size(121, 166);
               this->recyclable->TabIndex = 4;
               this->recyclable->TabStop = false;
               this->recyclable->Click += gcnew System::EventHandler(this, &FGame::recyclable_Click);
               // 
               // scorelbl
               // 
               this->scorelbl->AutoSize = true;
               this->scorelbl->BackColor = System::Drawing::Color::Transparent;
               this->scorelbl->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->scorelbl->ForeColor = System::Drawing::SystemColors::ControlLightLight;
               this->scorelbl->Location = System::Drawing::Point(212, 13);
               this->scorelbl->Name = L"scorelbl";
               this->scorelbl->Size = System::Drawing::Size(108, 30);
               this->scorelbl->TabIndex = 5;
               this->scorelbl->Text = L"00000";
               // 
               // heart1
               // 
               this->heart1->BackColor = System::Drawing::Color::Transparent;
               this->heart1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heart1.BackgroundImage")));
               this->heart1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->heart1->Location = System::Drawing::Point(1097, 98);
               this->heart1->Name = L"heart1";
               this->heart1->Size = System::Drawing::Size(40, 40);
               this->heart1->TabIndex = 6;
               this->heart1->TabStop = false;
               // 
               // heart2
               // 
               this->heart2->BackColor = System::Drawing::Color::Transparent;
               this->heart2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heart2.BackgroundImage")));
               this->heart2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->heart2->Location = System::Drawing::Point(1142, 98);
               this->heart2->Name = L"heart2";
               this->heart2->Size = System::Drawing::Size(40, 40);
               this->heart2->TabIndex = 7;
               this->heart2->TabStop = false;
               // 
               // heart3
               // 
               this->heart3->BackColor = System::Drawing::Color::Transparent;
               this->heart3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"heart3.BackgroundImage")));
               this->heart3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->heart3->Location = System::Drawing::Point(1188, 98);
               this->heart3->Name = L"heart3";
               this->heart3->Size = System::Drawing::Size(40, 40);
               this->heart3->TabIndex = 8;
               this->heart3->TabStop = false;
               // 
               // binTxt
               // 
               this->binTxt->AutoSize = true;
               this->binTxt->BackColor = System::Drawing::Color::Transparent;
               this->binTxt->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->binTxt->ForeColor = System::Drawing::Color::White;
               this->binTxt->Location = System::Drawing::Point(144, 95);
               this->binTxt->Name = L"binTxt";
               this->binTxt->Size = System::Drawing::Size(86, 37);
               this->binTxt->TabIndex = 9;
               this->binTxt->Text = L"NONE";
               this->binTxt->Click += gcnew System::EventHandler(this, &FGame::binTxt_Click);
               // 
               // powerTxt
               // 
               this->powerTxt->AutoSize = true;
               this->powerTxt->BackColor = System::Drawing::Color::Transparent;
               this->powerTxt->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->powerTxt->ForeColor = System::Drawing::Color::White;
               this->powerTxt->Location = System::Drawing::Point(663, 95);
               this->powerTxt->Name = L"powerTxt";
               this->powerTxt->Size = System::Drawing::Size(86, 37);
               this->powerTxt->TabIndex = 10;
               this->powerTxt->Text = L"NONE";
               // 
               // FGame
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
               this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->ClientSize = System::Drawing::Size(1280, 720);
               this->Controls->Add(this->powerTxt);
               this->Controls->Add(this->binTxt);
               this->Controls->Add(this->heart3);
               this->Controls->Add(this->heart2);
               this->Controls->Add(this->heart1);
               this->Controls->Add(this->scorelbl);
               this->Controls->Add(this->recyclable);
               this->Controls->Add(this->nonbio);
               this->Controls->Add(this->bio);
               this->Controls->Add(this->lblTime);
               this->Controls->Add(this->label1);
               this->DoubleBuffered = true;
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
               this->KeyPreview = true;
               this->Name = L"FGame";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"FGame";
               this->Load += gcnew System::EventHandler(this, &FGame::FGame_Load);
               this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FGame::FGame_KeyDown);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bio))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nonbio))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recyclable))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart1))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart2))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->heart3))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void FGame_Load(System::Object^ sender, System::EventArgs^ e)
    {
        // Start timers
        countdownTimer->Start();
        fallTimer->Start();
        spawnTimer->Start();

        // Initialize timer display
        lblTime->Text = gameTime.ToString();

        // Initialize score display
        UpdateScoreDisplay();

        // Initialize hearts display
        UpdateHeartDisplay();

        // Initialize bin and powerup text displays
        UpdateBinText();
        UpdatePowerupText();
    }

   private: System::Void FGame_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
   {
       switch (e->KeyCode)
       {
       case Keys::D1:  // Number 1 key
       case Keys::NumPad1:  // Numpad 1 key
           // Select Bio bin
           SetCustomCursor(BinType::Bio);
           activeBin = BinType::Bio;
           UpdateBinText(); // Update bin text label
           break;

       case Keys::D2:  // Number 2 key
       case Keys::NumPad2:  // Numpad 2 key
           // Select NonBio bin
           SetCustomCursor(BinType::NonBio);
           activeBin = BinType::NonBio;
           UpdateBinText(); // Update bin text label
           break;

       case Keys::D3:  // Number 3 key
       case Keys::NumPad3:  // Numpad 3 key
           // Select Recyclable bin
           SetCustomCursor(BinType::Recyclable);
           activeBin = BinType::Recyclable;
           UpdateBinText(); // Update bin text label
           break;

       case Keys::Escape:  // Escape key
           // Reset cursor to default
           this->Cursor = System::Windows::Forms::Cursors::Default;
           activeBin = BinType::None;
           UpdateBinText(); // Update bin text label
           break;
       }
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
        for each(Control ^ ctrl in this->Controls)
        {
            // FIXED: Check for both falling garbage AND special items
            if (ctrl->Tag != nullptr && (ctrl->Tag->ToString()->StartsWith("falling") || ctrl->Tag->ToString()->StartsWith("special")))
            {
                PictureBox^ garbageItem = dynamic_cast<PictureBox^>(ctrl);

                if (garbageItem != nullptr) {
                    // Move the garbage item down using the current fall speed
                    garbageItem->Top += currentFallSpeed;

                    // Check if garbage is out of bounds
                    if (garbageItem->Top > this->Height)
                    {
                        // Check if the item is a bomb
                        if (ctrl->Tag->ToString()->Contains("bomb")) {
                            // For bombs, just remove them without deducting lives
                            this->Controls->Remove(garbageItem);
                            delete garbageItem;
                        }
                        else {
                            // For regular items, lose a life when they fall out of bounds
                            LoseLife();

                            this->Controls->Remove(garbageItem);
                            delete garbageItem;
                        }
                        break;
                    }
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
               int randomIndex = rand->Next(1, 13); // 1-9 for regular garbage, 10 for multiplier, 11 for slowdown, 12 for bomb
               String^ folderPath = "ResourcesUsed\\GarbageIcons\\";
               String^ imagePath;
               String^ itemTag;

               if (randomIndex == 10) {
                   // Score multiplier powerup
                   imagePath = folderPath + "up1.png";
                   itemTag = "special:multiplier";
               }
               else if (randomIndex == 11) {
                   // Slow down powerup
                   imagePath = folderPath + "up2.png";
                   itemTag = "special:slowdown";
               }
               else if (randomIndex == 12) {
                   // Bomb
                   imagePath = folderPath + "bomb1.png";
                   itemTag = "special:bomb";
               }
               else {
                   // Regular garbage
                   imagePath = folderPath + randomIndex.ToString() + ".png";
                   itemTag = "falling:" + randomIndex.ToString();
               }

               PictureBox^ garbage = gcnew PictureBox();
               garbage->Size = System::Drawing::Size(75, 75);
               garbage->SizeMode = PictureBoxSizeMode::StretchImage;
               garbage->BackColor = Color::Transparent;

               try {
                   garbage->Image = Image::FromFile(imagePath); // Attempt to load the image
               }
               catch (...) {
                   MessageBox::Show("Image not found: " + imagePath); // Show error message if image is not found
                   return; // Exit function if image loading fails
               }

               garbage->Location = Point(rand->Next(0, this->Width - 50), 0);
               garbage->Tag = itemTag; // Include the item type in the tag

               // Add click event handler to the garbage item
               garbage->Click += gcnew System::EventHandler(this, &FGame::garbage_Click);

               this->Controls->Add(garbage);
               garbage->BringToFront();
           }

           // Event handler for garbage item clicks
           void garbage_Click(System::Object^ sender, System::EventArgs^ e)
           {
               PictureBox^ garbageItem = dynamic_cast<PictureBox^>(sender);
               if (garbageItem != nullptr && garbageItem->Tag != nullptr)
               {
                   String^ tag = garbageItem->Tag->ToString();

                   // Handle special items (power-ups and bomb)
                   if (tag->StartsWith("special")) {
                       SpecialItemType specialType = GetSpecialItemType(tag);
                       ApplyPowerUp(specialType);
                   }
                   // Handle regular garbage
                   else if (tag->StartsWith("falling")) {
                       // Check if a bin is selected
                       if (activeBin == BinType::None)
                           return;

                       // Extract the garbage type index from the tag
                       if (tag->Contains(":")) {
                           int garbageIndex = Int32::Parse(tag->Split(':')[1]);
                           BinType garbageType = GetGarbageType(garbageIndex);

                           // Check if correct bin is selected
                           if (activeBin == garbageType) {
                               // Correct bin - award points (with multiplier if active)
                               playerScore += 10 * scoreMultiplier;
                               UpdateScoreDisplay();
                           }
                           else {
                               // Wrong bin - lose a life
                               LoseLife();

                               // Wrong bin - subtract points
                               playerScore = Math::Max(0, playerScore - 5); // Ensure score doesn't go below 0
                               UpdateScoreDisplay();
                           }
                       }
                   }

                   // Remove the item
                   this->Controls->Remove(garbageItem);
                   delete garbageItem;
               }
           }

    private: System::Void bio_Click(System::Object^ sender, System::EventArgs^ e) {
        // Toggle bio bin selection
        if (activeBin == BinType::Bio) {
            // If already selected, reset cursor
            this->Cursor = System::Windows::Forms::Cursors::Default;
            activeBin = BinType::None;
        }
        else {
            // Set bio cursor
            SetCustomCursor(BinType::Bio);
            activeBin = BinType::Bio;
        }
        UpdateBinText(); // Update bin text label
    }

private: System::Void nonbio_Click(System::Object^ sender, System::EventArgs^ e) {
    // Toggle nonbio bin selection
    if (activeBin == BinType::NonBio) {
        // If already selected, reset cursor
        this->Cursor = System::Windows::Forms::Cursors::Default;
        activeBin = BinType::None;
    }
    else {
        // Set nonbio cursor
        SetCustomCursor(BinType::NonBio);
        activeBin = BinType::NonBio;
    }
    UpdateBinText(); // Update bin text label
}

private: System::Void recyclable_Click(System::Object^ sender, System::EventArgs^ e) {
    // Toggle recyclable bin selection
    if (activeBin == BinType::Recyclable) {
        // If already selected, reset cursor
        this->Cursor = System::Windows::Forms::Cursors::Default;
        activeBin = BinType::None;
    }
    else {
        // Set recyclable cursor
        SetCustomCursor(BinType::Recyclable);
        activeBin = BinType::Recyclable;
    }
    UpdateBinText(); // Update bin text label
}
    private: System::Void binTxt_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}