#include "Start.h"
#include "User.h"
#include "Leaderboards.h"
#include "GameOver.h"

using namespace BasuraHero;

[STAThreadAttribute]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool showApp = true;

    while (showApp) {
        // Show Start form
        Start^ startForm = gcnew Start();
        if (startForm->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
            break; // Exit if Start form is closed
        }

        if (startForm->switchToLeaderboard) {
            // Show Leaderboards form
            Leaderboards^ lbForm = gcnew Leaderboards();
            if (lbForm->ShowDialog() != System::Windows::Forms::DialogResult::OK || !lbForm->switchToStart) {
                break; // Exit if Leaderboards form is closed or doesn't loop back
            }
            continue; // Loop back to Start form
        }

        // Show User form (gameplay)
        User^ userForm = gcnew User();
        if (userForm->ShowDialog() != System::Windows::Forms::DialogResult::OK || !userForm->switchToStart) {
            // Show GameOver form if User form doesn't loop back
            GameOver^ gameOverForm = gcnew GameOver();
            if (gameOverForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                Console::WriteLine("GameOver form closed with switchToStart = " + gameOverForm->switchToStart);
                if (gameOverForm->switchToStart) {
                    continue; // Directly loop back to Start form
                }
            }
            break; // Exit if GameOver form is closed or doesn't loop back
        }
    }

    return 0;
}
