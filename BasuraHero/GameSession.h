#pragma once

#include <string>

struct SpawnRuleResult {
    std::string imageName;
    std::string itemTag;
};

class GameSession {
public:
    GameSession();

    void Reset(int initialTimeSeconds, int initialLives, int baseFallSpeed);

    int TickCountdown();
    int TimeRemaining() const;

    int Score() const;
    int Lives() const;
    int ScoreMultiplier() const;
    int BaseFallSpeed() const;
    int CurrentFallSpeed() const;

    bool HasScoreMultiplier() const;
    bool HasSlowdown() const;

    void ActivateScoreMultiplier();
    void ResetScoreMultiplier();

    void ActivateSlowdown();
    void ResetSlowdown();

    void AddCorrectSortPoints();
    void ApplyWrongSortPenalty();

    bool LoseLife();

    SpawnRuleResult ResolveSpawnRule(int randomIndex) const;

private:
    int timeRemaining_;
    int score_;
    int lives_;
    int scoreMultiplier_;
    int baseFallSpeed_;
    int currentFallSpeed_;
};
