#pragma once

#include <raylib.h>

// GameDino class declaration
class GameDino {
private:
    const int app_count = 1;
    Texture2D texture[1];
    Vector2 position;
    float speed = 5.0f;
    bool isJumping;
    float scaleFactor = 0.8f;
    float jumpSpeed = 10.0f;
    float gravity = 0.5f;
    float dinoWidth;
    float dinoHeight;

public:
    GameDino();
    ~GameDino();

    void Draw(const int windowWidth, const int windowHeight);
    void Update();
    Rectangle GetBoundingBox() const;
    void ResetPos();
};

// Meteor class declaration
class Meteor {
private:
    Texture2D texture;
    Vector2 position;
    float scaleFactor = 0.3f;
    float speed = 5.0f;
    float meteorWidth;
    float meteorHeight;

public:
    Meteor();
    Meteor(const Vector2& startPosition);
    ~Meteor();

    void Draw(const int windowWidth, const int windowHeight) const;
    void Update(float speed);
    Rectangle GetBoundingBox() const;
    float GetWidth() const;
    float GetHeight() const;
    void ResetPos();
};