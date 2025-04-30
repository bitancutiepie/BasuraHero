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
        Start^ startForm = gcnew Start();
        Application::DoEvents(); // Process any pending messages

        if (startForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            if (startForm->switchToLeaderboard) {
                // Show Leaderboards
                Leaderboards^ lbForm = gcnew Leaderboards();
                Application::DoEvents();

                if (lbForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                    if (lbForm->switchToStart) {
                        // Loop back to Start form
                        continue;
                    }
                    else {
                        showApp = false;
                    }
                }
                else {
                    showApp = false;
                }
            }
            else {
                // Show User form (gameplay)
                User^ userForm = gcnew User();
                Application::DoEvents();

                if (userForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                    if (userForm->switchToStart) {
                        // Loop back to Start form
                        continue;
                    }
                    else {
                        // Show GameOver form
                        GameOver^ gameOverForm = gcnew GameOver();
                        Application::DoEvents();

                        // Debugging: Show message before displaying GameOver
                        MessageBox::Show("Showing GameOver form");

                        if (gameOverForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                            // Debugging: Show what happened after GameOver
                            MessageBox::Show("GameOver form returned OK, switchToStart = " +
                                gameOverForm->switchToStart.ToString());

                            if (gameOverForm->switchToStart) {
                                // Loop back to Start form
                                continue;
                            }
                            else {
                                showApp = false;
                            }
                        }
                        else {
                            // Debugging: Show what happened if not OK
                            MessageBox::Show("GameOver form returned not OK");
                            showApp = false;
                        }
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