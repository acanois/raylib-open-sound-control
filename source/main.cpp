#include <iostream>
#include "raylib.h"

int main() {
    InitWindow(800, 450, "Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(SKYBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
