#include <raylib.h>
#include "controller.h" // Include the controller header

int main() {
    const int windowWidth = 1000;
    const int windowHeight = 500;
    const int FPS = 60;

    InitWindow(windowWidth, windowHeight, "Dino game");
    InitAudioDevice();
    SetTargetFPS(FPS);

    Controller controller; // Create a controller object

    while (!WindowShouldClose()) {
        controller.Update(); // Update the game state
        BeginDrawing();
        ClearBackground(RAYWHITE);
        controller.Draw(windowWidth, windowHeight); // Draw the current game state
        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();

    return 0;
}
