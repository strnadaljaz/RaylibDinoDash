#include "game.h"
#include "texture_manager.h"
#include <cmath> // For sqrt and pow functions

// Constructor
Game::Game() {
    for (int i = 0; i < meteorCountLimit; i++) {
        Vector2 newPosition = { (float)(GetRandomValue(1050, 1500)), 330 };
        meteors.push_back(Meteor(newPosition));
    }
}

// Function to check if a new position is valid
bool Game::IsPositionValid(const Vector2& position, const std::vector<Meteor>& meteors, float minDistance) const {
    for (const Meteor& meteor : meteors) {
        Rectangle existingBox = meteor.GetBoundingBox();

        float existingCenterX = existingBox.x + existingBox.width / 2;
        float newCenterX = position.x + existingBox.width / 2;
        float distance = std::abs(newCenterX - existingCenterX);

        if (distance < minDistance) {
            return false;
        }
    }
    return true;
}

bool Game::CheckCollision() {
    dinoBox = dino.GetBoundingBox();
    for (Meteor& meteor : meteors) {
        meteorBox = meteor.GetBoundingBox();

        if (CheckCollisionRecs(dinoBox, meteorBox)) {
            dino.ResetPos();
            meteors.clear(); 
            meteors.resize(1); 
            meteors[0].ResetPos();
            spawnInterval = 5.0f;
            meteorSpeed = 5.0f;
            return true;
        }
    }

    score += 0.5f;
    return false;
}

void Game::Draw(const int windowWidth, const int windowHeight) {
    dino.Draw(windowWidth, windowHeight);
    for (const Meteor& meteor : meteors) {
        meteor.Draw(windowWidth, windowHeight);
    }
    DrawText(("SCORE: " + std::to_string((int)score)).c_str(), 800, 50, 20, GRAY);
}

void Game::Update(float deltaTime) {
    dino.Update();
    elapsedTime += deltaTime;

    if (elapsedTime >= spawnInterval) {
        if (meteors.size() < meteorCountLimit) {
            bool canSpawn = false;
            int attemptCount = 0;

            while (!canSpawn && attemptCount < 100) {
                // Generate a random position for a new meteor
                Vector2 newPosition = { GetRandomValue(1050, 1500), 330 };
                canSpawn = IsPositionValid(newPosition, meteors, minDistance);

                if (canSpawn) {
                    meteors.push_back(Meteor(newPosition)); // Add a new meteor
                }

                attemptCount++;
            }
        }

        elapsedTime = 0.0f;

        if (meteors.size() == meteorCountLimit) {
            meteorSpeed = std::min(meteorSpeed + 0.5f, maxMeteorSpeed);
        }

        if (spawnInterval > 1.0f) { // Decrease spawn interval slowly
            spawnInterval -= 0.1f;
        }
    }

    for (Meteor& meteor : meteors) {
        meteor.Update(meteorSpeed); // Update meteor position with speed
    }
}
