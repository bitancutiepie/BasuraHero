<div align="center">
  <img src="BasuraHero/ResourcesUsed/BASURA%20HERO%20(2).png" width="120" alt="BasuraHero logo">

  # BasuraHero

  *A gamified waste-segregation game for teaching proper trash disposal*

  [![.NET Framework](https://img.shields.io/badge/.NET%20Framework-4.7.2-512bd4?style=flat-square)](https://dotnet.microsoft.com/)
  [![Platform](https://img.shields.io/badge/platform-Windows-0078d4?style=flat-square)](https://www.microsoft.com/windows)
  [![Language](https://img.shields.io/badge/language-C%2B%2B%2FCLI-00599c?style=flat-square)](https://docs.microsoft.com/cpp/dotnet/)

</div>

BasuraHero is a Windows desktop game that teaches proper waste segregation through fast-paced gameplay. Players sort falling garbage into the correct bin — Biodegradable, Non-Biodegradable, or Recyclable — before it hits the ground, while power-ups and bombs keep the action engaging. Player profiles and scores are stored in a local SQL Server database, with a leaderboard tracking top performers.

## Features

- Falling garbage items across three waste categories: Bio, Non-Bio, and Recyclable.
- Three bin targets selected with the keyboard (`1` / `2` / `3`), each with a custom cursor.
- Score system with a 2x multiplier power-up and a slow-down power-up.
- Bombs that cost a life on contact and hazards that cost a life when missed.
- Three lives and a 60-second countdown timer per round.
- Player registration (username + gender) persisted to `BasuraHeroDB` on SQL Server LocalDB.
- Leaderboard screen with background music.
- Main menu with looping background music.

## Prerequisites

- Windows 10/11
- [Visual Studio 2022](https://visualstudio.microsoft.com/) with the **Desktop development with C++** workload (and C++/CLI support)
- [.NET Framework 4.7.2 targeting pack](https://dotnet.microsoft.com/download/dotnet-framework/net472)
- SQL Server LocalDB (ships with Visual Studio) and a database named `BasuraHeroDB`

> [!NOTE]
> The game reads its images and audio from a `ResourcesUsed` folder located next to (or above) the built executable. Keep that folder intact when running the game.

## Building

1. Clone the repository:

   ```bash
   git clone https://github.com/bitancutiepie/BasuraHero.git
   ```

2. Open `BasuraHero.sln` in Visual Studio 2022.

3. Restore the `BasuraHeroDB` database and ensure the connection string in `BasuraHero/User.h` matches your LocalDB instance:

   ```cpp
   Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=BasuraHeroDB;Integrated Security=True
   ```

4. Build and run the `BasuraHero` project (`Debug` or `Release`, x64).

## Gameplay

1. From the **Start** menu, enter your profile on the **User** screen (username + gender) and press **PLAY**.
2. In **FGame**, falling items appear at the top of the screen. Press `1`, `2`, or `3` to select the Bio, Non-Bio, or Recyclable bin (the cursor changes to match). Click the falling item to sort it.
   - Correct sort: **+10 points** (doubled while the multiplier is active).
   - Wrong sort or a missed item: **lose a life**.
3. Special items: score multiplier (`up1.png`), slow-down (`up2.png`), and bombs (`bomb1.png`).
4. The round ends when the timer reaches 0 or all three lives are lost, showing the **Game Over** screen.
5. View top players on the **Leaderboards** screen.

### Controls

| Key | Action |
| --- | --- |
| `1` / Numpad `1` | Select Bio bin |
| `2` / Numpad `2` | Select Non-Bio bin |
| `3` / Numpad `3` | Select Recyclable bin |
| `Esc` | Reset cursor / deselect bin |
| `Enter` / `Esc` (Game Over) | Return to menu |

## Project Structure

```
BasuraHero/
├── BasuraHero.sln
└── BasuraHero/
    ├── Start.h/.cpp        # Main menu
    ├── User.h/.cpp         # Player registration (SQL Server)
    ├── FGame.h/.cpp        # Core gameplay
    ├── GameOver.h/.cpp     # Game over screen
    ├── Leaderboards.h/.cpp  # Leaderboard screen
    └── ResourcesUsed/      # Images, icons, and audio assets
```

## Tech Stack

- **Language:** C++/CLI
- **UI:** Windows Forms (.NET Framework 4.7.2)
- **Database:** SQL Server LocalDB (`BasuraHeroDB`)
- **IDE:** Visual Studio 2022

## Database Notes

The `UserData` table stores `Username` and `Gender`. The accompanying `BasuraHero_Database_Activity.txt` describes proposed optimizations (precomputed score columns, indexing) and a star-schema data warehouse design for analytics.

> [!TIP]
> If the executable cannot find `ResourcesUsed`, the code walks up from `Application::StartupPath` until the folder is located, so the game can run from the `Debug`/`Release` output directory as long as `ResourcesUsed` is reachable up the tree.