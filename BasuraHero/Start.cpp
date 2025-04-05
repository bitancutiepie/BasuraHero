#include "Start.h"
#include "User.h"

using namespace BasuraHero;

[STAThreadAttribute]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool goToUser = true;

    while (goToUser) {
        // Show Start form first
        Start^ startForm = gcnew Start();

        // If Start returns OK, show User form
        if (startForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            User^ userForm = gcnew User();
            if (userForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                // If User wants to switch back to Start
                if (userForm->switchToStart) {
                    goToUser = true;  // Go back to Start
                }
                else {
                    goToUser = false; // Exit the loop
                }
            }
            else {
                goToUser = false; // User canceled or closed, exit
            }
        }
        else {
            goToUser = false; // Start was canceled or closed, exit
        }
    }

    return 0;
}
