# BasuraHero Codebase Examination

## Snapshot
- **Platform:** C++/CLI Windows Forms game project (`BasuraHero.sln`, `BasuraHero.vcxproj`).
- **Primary runtime model:** modal form navigation with a loop in `main()`.
- **Core gameplay:** timed drag/click-style trash sorting with selectable bins, score/lives, and powerups.

## High-level architecture

### Application flow
1. `main()` starts in `Start` form.
2. `Start` can route to:
   - `Leaderboards` (then back to Start), or
   - `User` (player profile/registration), then `FGame`.
3. `FGame` can open `GameOver` when timer/lives end.
4. `GameOver` can route back to Start via `switchToStart`.

This flow is controlled by `ShowDialog()` plus boolean handoff flags (`switchToLeaderboard`, `switchToStart`).

### Main components
- **`Start`**
  - Plays looping menu audio (`journeybg.wav`) and handles navigation.
  - Uses `PlaySound` from WinMM.
- **`User`**
  - Captures username + gender.
  - Writes player data to LocalDB (`BasuraHeroDB.UserData`) and starts game.
- **`FGame`**
  - Owns game loop with multiple timers: countdown, fall movement, spawning, and temporary powerups.
  - Tracks bins, score, multiplier, fall speed, and lives.
- **`Leaderboards`**
  - Mostly UI shell + sound playback (`lbSound.wav`).
- **`GameOver`**
  - End-state form with return-to-menu behavior.

## Strengths
- Clear and understandable form-by-form decomposition.
- Timer-driven gameplay logic is straightforward to follow.
- Uses SQL parameters (`AddWithValue`) for user insert/check, which avoids direct string concatenation SQL injection risks.
- Audio and visual assets are already organized under `ResourcesUsed`.

## Key risks and issues

1. **Exit confirmation dialogs ignore user selection in multiple places**
   - In `Start` and `Leaderboards`, confirmation dialogs are shown, but `Application::Exit()` is called regardless of whether user clicked Yes or No.
   - Impact: user cannot cancel an exit once the prompt appears.

2. **Game/runtime logic is heavily embedded in form headers**
   - Significant logic in `.h` files (especially `FGame.h`, `User.h`, `Start.h`) increases compile coupling and makes testing harder.

3. **Hard-coded LocalDB connection string in UI handler**
   - Connection config is embedded in click event logic (`User` form), making environment portability and secret/config management harder.

4. **Limited separation between presentation and domain logic**
   - Scoring, lives, and spawn decisions are tightly coupled to controls/Tags; this makes balancing and regression testing difficult.

5. **Potential UX and maintainability gaps**
   - Some handlers are empty placeholders.
   - Mixed naming/comment style and repeated navigation patterns add noise and maintenance overhead.

## Recommended improvements (ordered)

1. **Fix exit confirmation behavior first**
   - Gate `Application::Exit()` on `DialogResult::Yes` only.

2. **Extract game domain logic from `FGame` UI class**
   - Move score/lives/powerup/spawn rules into plain C++ classes.
   - Keep form focused on rendering/input wiring.

3. **Introduce central configuration**
   - Move DB connection string to config (or at least a single constant/provider).

4. **Normalize navigation handling**
   - Create a small app-state coordinator (or helper methods) to reduce repeated `ShowDialog()` + flag checks.

5. **Improve reliability checks**
   - Add at least basic smoke checks/documented runbook since automated UI tests are currently absent.

## Practical next step shortlist
- [ ] Patch confirmation prompts in `Start` + `Leaderboards`.
- [ ] Add a `GameSession` class that owns score/life/timer state transitions.
- [ ] Move DB string to one shared constant or config source.
- [ ] Remove/implement empty event handlers to reduce dead code.

