#pragma once

#include <raylib.h>
#include "start.h"
#include "game.h"
#include "end.h"

class Controller {
private:
    Start start;
    Game game;
    EndScreen endScreen;
    enum State { START, GAME, END } state;

public:
    Controller();
    void Update();
    void Draw(const int windowWidth, const int windowHeight);
};
