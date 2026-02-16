#include "Start.h"
#include "User.h"
#include "Leaderboards.h"
#include "GameOver.h"

using namespace BasuraHero;

namespace {
    enum class AppRoute {
        Exit,
        ReturnToStart,
        GoToLeaderboards,
        GoToUser,
        ShowGameOver
    };

    AppRoute ShowStartScreen() {
        Start^ startForm = gcnew Start();
        if (startForm->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
            return AppRoute::Exit;
        }

        return startForm->switchToLeaderboard ? AppRoute::GoToLeaderboards : AppRoute::GoToUser;
    }

    AppRoute ShowLeaderboardsScreen() {
        Leaderboards^ lbForm = gcnew Leaderboards();
        if (lbForm->ShowDialog() == System::Windows::Forms::DialogResult::OK && lbForm->switchToStart) {
            return AppRoute::ReturnToStart;
        }

        return AppRoute::Exit;
    }

    AppRoute ShowUserScreen() {
        User^ userForm = gcnew User();
        if (userForm->ShowDialog() == System::Windows::Forms::DialogResult::OK && userForm->switchToStart) {
            return AppRoute::ReturnToStart;
        }

        return AppRoute::ShowGameOver;
    }

    AppRoute ShowGameOverScreen() {
        GameOver^ gameOverForm = gcnew GameOver();
        if (gameOverForm->ShowDialog() == System::Windows::Forms::DialogResult::OK && gameOverForm->switchToStart) {
            return AppRoute::ReturnToStart;
        }

        return AppRoute::Exit;
    }
}

[STAThreadAttribute]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    bool showApp = true;

    while (showApp) {
        AppRoute route = ShowStartScreen();

        if (route == AppRoute::GoToLeaderboards) {
            route = ShowLeaderboardsScreen();
        }
        else if (route == AppRoute::GoToUser) {
            route = ShowUserScreen();
            if (route == AppRoute::ShowGameOver) {
                route = ShowGameOverScreen();
            }
        }

        showApp = (route == AppRoute::ReturnToStart);
    }

    return 0;
}
