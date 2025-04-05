#include "Start.h"
#include "User.h"  // Include User form header

using namespace BasuraHero;

[STAThreadAttribute]  // Required for Windows Forms
int main() {
    // Create and show Start form
    Start^ startForm = gcnew Start();

    // Show Start form as a modal dialog and wait for the result
    if (startForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // If Start form closes with OK, show User form
        User^ userForm = gcnew User();
        userForm->ShowDialog();  // Show User form and wait for it to be closed
    }

    


    return 0;
}
