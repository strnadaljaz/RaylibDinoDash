#include "end.h"

void EndScreen::Draw(const int windowWidth, const int windowHeight, float score) {
    DrawText("Game Over", windowWidth / 2 - 100, windowHeight / 2 - 60, 40, RED);
    DrawText("Press SPACE to restart", windowWidth / 2 - 130, windowHeight / 2 + 20, 20, GRAY);
    DrawText(("Your score was: " + std::to_string((int)score)).c_str(), windowWidth / 2 - 90, windowHeight / 2 + 60, 20, GRAY);
}
