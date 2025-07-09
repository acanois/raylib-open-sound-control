//
// Created by David Richter on 7/1/25.
//

// #include <cmath>
#include <iostream>

#include "app.h"


App::App()
    : mCamera({
          Vector3{0.0f, 10.0f, 10.0f},
          Vector3{0.0f, 0.0f, 0.0f},
          Vector3{0.0f, 1.0f, 0.0f},
          45.f,
          CAMERA_PERSPECTIVE
      }),
      mOscHandler(std::make_unique<OscHandler>()) {
    InitWindow(screenDimensions.x, screenDimensions.y, "Raylib - OSC");
    SetTargetFPS(60);

    auto inputFunc = []() { std::cout << "OscHandler started" << std::endl; };
    auto cleanupFunc = []() { std::cout << "OscHandler stopped" << std::endl; };
    mOscHandler->setCallbacks(inputFunc, cleanupFunc);

    const auto pathName = "/midi_note";
    const auto messageType = "i";
    auto intHandler = [](lo_arg **argv, int) { std::cout << argv[0]->i << std::endl; };
    mOscHandler->addMethod(pathName, messageType, intHandler);

    mOscHandler->startThread();
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
