#pragma once

#include <raylib.h>
#include <string>

class EndScreen {
public:
    EndScreen() = default;

    void Draw(const int windowWidth, const int windowHeight, float score);
};
