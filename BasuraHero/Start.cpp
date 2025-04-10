#include "Start.h"
#include "User.h"
#include "Leaderboards.h"



using namespace BasuraHero;

[STAThreadAttribute]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool showApp = true;

    while (showApp) {
        Start^ startForm = gcnew Start();

        if (startForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

            if (startForm->switchToLeaderboard) {
                Leaderboards^ lbForm = gcnew Leaderboards();

                if (lbForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                    if (lbForm->switchToStart) {
                        showApp = true; // Return to Start
                    }
                    else {
                        showApp = false; // Close app if no return
                    }
                }
                else {
                    showApp = false;
                }
            }
            else {
                User^ userForm = gcnew User();
                if (userForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                    if (userForm->switchToStart) {
                        showApp = true; // Return to Start
                    }
                    else {
                        showApp = false;
                    }
                }
                else {
                    showApp = false;
                }
            }

        }
        else {
            showApp = false;
        }
    }

    return 0;
}
