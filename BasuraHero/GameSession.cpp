#include "GameSession.h"

GameSession::GameSession()
    : timeRemaining_(60),
      score_(0),
      lives_(3),
      scoreMultiplier_(1),
      baseFallSpeed_(10),
      currentFallSpeed_(10) {
}

void GameSession::Reset(int initialTimeSeconds, int initialLives, int baseFallSpeed) {
    timeRemaining_ = initialTimeSeconds;
    score_ = 0;
    lives_ = initialLives;
    scoreMultiplier_ = 1;
    baseFallSpeed_ = baseFallSpeed;
    currentFallSpeed_ = baseFallSpeed_;
}

int GameSession::TickCountdown() {
    if (timeRemaining_ > 0) {
        --timeRemaining_;
    }

    return timeRemaining_;
}

int GameSession::TimeRemaining() const { return timeRemaining_; }
int GameSession::Score() const { return score_; }
int GameSession::Lives() const { return lives_; }
int GameSession::ScoreMultiplier() const { return scoreMultiplier_; }
int GameSession::BaseFallSpeed() const { return baseFallSpeed_; }
int GameSession::CurrentFallSpeed() const { return currentFallSpeed_; }

bool GameSession::HasScoreMultiplier() const { return scoreMultiplier_ > 1; }
bool GameSession::HasSlowdown() const { return currentFallSpeed_ < baseFallSpeed_; }

void GameSession::ActivateScoreMultiplier() { scoreMultiplier_ = 2; }
void GameSession::ResetScoreMultiplier() { scoreMultiplier_ = 1; }

void GameSession::ActivateSlowdown() { currentFallSpeed_ = baseFallSpeed_ / 2; }
void GameSession::ResetSlowdown() { currentFallSpeed_ = baseFallSpeed_; }

void GameSession::AddCorrectSortPoints() {
    score_ += (10 * scoreMultiplier_);
}

void GameSession::ApplyWrongSortPenalty() {
    score_ -= 5;
    if (score_ < 0) {
        score_ = 0;
    }
}

bool GameSession::LoseLife() {
    if (lives_ > 0) {
        --lives_;
    }

    return lives_ <= 0;
}

SpawnRuleResult GameSession::ResolveSpawnRule(int randomIndex) const {
    if (randomIndex == 10) {
        return {"up1.png", "special:multiplier"};
    }

    if (randomIndex == 11) {
        return {"up2.png", "special:slowdown"};
    }

    if (randomIndex == 12) {
        return {"bomb1.png", "special:bomb"};
    }

    return {std::to_string(randomIndex) + ".png", "falling:" + std::to_string(randomIndex)};
}
