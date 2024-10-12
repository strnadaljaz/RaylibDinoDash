#include "start_dino.h"

StartDino::StartDino() {
    // Load figure textures
    texApp[0] = LoadTexture("res/images/dino0.png");
    texApp[1] = LoadTexture("res/images/dino1.png");
}

StartDino::~StartDino() {
    for (unsigned int i = 0; i < app_count; i++) {
        UnloadTexture(texApp[i]);
    }
}

void StartDino::Draw(const int windowWidth, const int windowHeight) {
    timer -= GetFrameTime();

    if (timer <= 0) {
        cur_app_count = (cur_app_count < app_count - 1) ? ++cur_app_count : 0;
        timer = 1.0f;
    }

    int xPos = (windowWidth - texApp[0].width) / 2;
    int yPos = (windowHeight - texApp[0].height) / 2;
    DrawTexture(texApp[cur_app_count], xPos, yPos, WHITE);
}
