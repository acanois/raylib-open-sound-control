#include <iostream>
#include <atomic>
#include <stdexcept>

#include <unistd.h>

#include <raylib.h>

#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include "osc_handler.h"


Camera3D camera = {};
Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

constexpr int screenWidth = 1280;
constexpr int screenHeight = 720;

float angle = 0.f;

float angleToRads(const float angle) {
    return angle * static_cast<float>(M_PI) / 180.f;
}

void init() {
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");
    SetTargetFPS(60);

    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void update() {
    angle -= 0.1;
    camera.position = Vector3 {
        cos(angleToRads(angle)) * 10.f,
        10.f,
        sin(angleToRads(angle)) * 10.f
    };
}

void draw() {
    while (!WindowShouldClose()) {
        update();
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        DrawGrid(10, 1.0f);
        EndMode3D();
        DrawFPS(10, 10);
        EndDrawing();
    }
}

int main() {
    OscHandler::initOsc();

    init();
    draw();
    CloseWindow();

    return 0;
}
