#pragma once

#include <raylib.h>
#include "start_dino.h"

class Start {
private:
    Music music;
    const char* text = "Press SPACE to Start";
    StartDino dino;
    float musicVolume = 0.15f;

public:
    Start();
    ~Start();

    void Draw(const int windowWidth, const int windowHeight);
    void Update();
};
