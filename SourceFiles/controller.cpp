#include "controller.h"

Controller::Controller() : state(START) {}

void Controller::Draw(const int windowWidth, const int windowHeight) {
    switch (state) {
    case START:
        start.Draw(windowWidth, windowHeight);
        break;
    case GAME:
        game.Draw(windowWidth, windowHeight);
        break;
    case END:
        endScreen.Draw(windowWidth, windowHeight, game.score);
        break;
    }
}

void Controller::Update() {
    float deltaTime = GetFrameTime();

    switch (state) {
    case START:
        start.Update();
        if (IsKeyPressed(KEY_SPACE)) {
            state = GAME;
        }
        break;
    case GAME:
        game.Update(deltaTime);
        if (game.CheckCollision())
            state = END;
        break;
    case END:
        if (IsKeyPressed(KEY_SPACE)) {
            state = GAME;
            game.score = 0;
        }
        break;
    }
}
