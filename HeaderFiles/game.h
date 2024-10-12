#pragma once

#include <vector>
#include <raylib.h>
#include <string>
#include "game_objects.h"

class Game {
private:
    Rectangle dinoBox;
    Rectangle meteorBox;
    float elapsedTime = 0.0f;
    float spawnInterval = 5.0f;
    float meteorSpeed = 5.0f;
    float maxMeteorSpeed = 10.0f;
    int meteorCountLimit = 3;
    const float minDistance = 380.0f; // Minimum distance between meteors

    bool IsPositionValid(const Vector2& position, const std::vector<Meteor>& meteors, float minDistance) const;

public:
    GameDino dino;
    std::vector<Meteor> meteors;
    float score = 0;

    Game();
    bool CheckCollision();
    void Draw(const int windowWidth, const int windowHeight);
    void Update(float deltaTime);
};
