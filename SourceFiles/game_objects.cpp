#include "game_objects.h"
#include "texture_manager.h"

// --------------------------------------------------- Dino Object -----------------------------------------------------
GameDino::GameDino() {
    texture[0] = TextureManager::LoadTexture("res/images/dino1.png");
    position = { 100, 300 }; // Start position
    isJumping = false;

    dinoWidth = (texture[0].width * scaleFactor * 0.8f);
    dinoHeight = (texture[0].height * scaleFactor);
}

GameDino::~GameDino() {
    // No need to unload textures here; managed by TextureManager
}

void GameDino::Draw(const int windowWidth, const int windowHeight) {
    DrawTextureEx(texture[0], position, 0.0f, scaleFactor, WHITE);
}

void GameDino::Update() {
    if (isJumping) {
        position.y -= jumpSpeed;
        jumpSpeed -= gravity;

        if (position.y >= 300.0f) {
            position.y = 300.0f;
            isJumping = false;
            jumpSpeed = 10.0f;
        }
    }
    else {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
            isJumping = true;
    }
}

Rectangle GameDino::GetBoundingBox() const {
    return { position.x, position.y, dinoWidth, dinoHeight };
}

void GameDino::ResetPos() {
    position = { 100, 300 };
}


// --------------------------------------------------- Meteor Object -----------------------------------------------------

Meteor::Meteor() {
    texture = TextureManager::LoadTexture("res/images/meteor.png");
    position = { 1050, 330 };

    meteorWidth = (texture.width * scaleFactor);
    meteorHeight = (texture.height * scaleFactor);
}

Meteor::Meteor(const Vector2& startPosition) {
    texture = TextureManager::LoadTexture("res/images/meteor.png");
    position = startPosition;

    meteorWidth = (texture.width * scaleFactor);
    meteorHeight = (texture.height * scaleFactor);
}

Meteor::~Meteor() {
    // No need to unload textures here; managed by TextureManager
}

void Meteor::Draw(const int windowWidth, const int windowHeight) const {
    DrawTextureEx(texture, position, 0.0f, scaleFactor, WHITE);
}


void Meteor::Update(float speed) {
    if (position.x < -100)
        position.x = 1050;
    else
        position.x -= speed;
}

Rectangle Meteor::GetBoundingBox() const {
    return { position.x, position.y, meteorWidth, meteorHeight };
}

float Meteor::GetWidth() const {
    return meteorWidth;
}

float Meteor::GetHeight() const {
    return meteorHeight;
}

void Meteor::ResetPos() {
    position = { (float)(GetRandomValue(1050, 1500)), 330 };
}
