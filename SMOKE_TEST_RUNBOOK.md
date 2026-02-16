# BasuraHero Smoke Test Runbook

Use this quick checklist for manual reliability checks after any gameplay/navigation changes.

## Preconditions
- Build the solution in Visual Studio (`Debug|Win32` recommended for local validation).
- Ensure LocalDB contains `BasuraHeroDB` with `UserData` table.
- Ensure audio and icon assets exist under `BasuraHero/ResourcesUsed`.

## Smoke checks
1. **Start screen quit confirmation**
   - Click quit.
   - Press **No** and verify app stays open.
   - Click quit again, press **Yes**, verify app exits.

2. **Leaderboard flow + quit confirmation**
   - Open Leaderboards from Start.
   - Click back-to-menu button and verify return to Start.
   - Click Leaderboards quit button, press **No** and verify it stays open.

3. **User registration flow**
   - Enter username + gender and confirm.
   - Verify duplicate username prompts the existing-user error.
   - Verify new username saves and game starts.

4. **Gameplay session basics**
   - Verify countdown starts at 60 and reaches game-over at 0.
   - Verify correct bin match increments score.
   - Verify wrong bin and missed non-bomb item reduce lives.
   - Verify bomb click/miss behavior matches design (click loses life, miss does not).

5. **Powerups**
   - Spawn/click multiplier and verify score text turns yellow and reverts after timeout.
   - Spawn/click slowdown and verify falling speed decreases then resets after timeout.

6. **Route recovery**
   - Reach game-over screen and choose Menu.
   - Verify app returns to Start cleanly and can launch another run.

## Troubleshooting notes
- If DB save fails, check LocalDB instance and `UserData` schema first.
- If audio does not play, confirm wav files in `ResourcesUsed` and working directory is project root.
- If cursor icons fail to load, verify icon file paths under `ResourcesUsed/GarbageIcons`.
