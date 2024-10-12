#pragma once

#include <raylib.h>

class StartDino {
private:
    const unsigned int app_count = 2; // Appearance count
    Texture2D texApp[2];
    float timer = 1.0f;
    int cur_app_count = 0; // Current Dino appearance count

public:
    StartDino();
    ~StartDino();

    void Draw(const int windowWidth, const int windowHeight);
};
