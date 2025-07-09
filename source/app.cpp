//
// Created by David Richter on 7/1/25.
//

// #include <cmath>
#include <iostream>

#include "app.h"


App::App()
    : mCamera({
          Vector3 {0.0f, 10.0f, 10.0f},
          Vector3 {0.0f, 0.0f, 0.0f},
          Vector3 {0.0f, 1.0f, 0.0f},
          45.f,
          CAMERA_PERSPECTIVE
      }),
      mOscHandler(std::make_unique<OscHandler>(9000)) {
    InitWindow(screenDimensions.x, screenDimensions.y, "Raylib - OSC");
    SetTargetFPS(60);
}

App::~App() {
    std::cout << "~Scene()" << std::endl;
    CloseWindow();
}

void App::update() {
    mAngle -= 0.1;

    mCamera.position.x = cos(mAngle * DEG2RAD) * 10.f;
    mCamera.position.y = 10.f;
    mCamera.position.z = sin(mAngle * DEG2RAD) * 10.f;
}

void App::draw() {
    while (!WindowShouldClose()) {
        update();

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(mCamera);
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                DrawGrid(10, 1.0f);
            EndMode3D();
            DrawFPS(10, 10);
        EndDrawing();
    }
}
