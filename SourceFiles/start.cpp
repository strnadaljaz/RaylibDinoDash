#include "start.h"

Start::Start() {
    music = LoadMusicStream("res/sounds/background_start.mp3");
    PlayMusicStream(music);
}

Start::~Start() {
    UnloadMusicStream(music);
}

void Start::Draw(const int windowWidth, const int windowHeight) {
    // Draw the start text
    const int fontSize = 20;
    int textWidth = MeasureText(text, fontSize);
    int xPos = (windowWidth - textWidth) / 2;
    int yPos = (windowHeight - fontSize) / 2 + 70;
    DrawText(text, xPos, yPos, 20, GRAY);

    // Draw the Dino
    dino.Draw(windowWidth, windowHeight);
}

void Start::Update() {
    SetMusicVolume(music, musicVolume);
    UpdateMusicStream(music);
}
