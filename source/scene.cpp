//
// Created by David Richter on 7/1/25.
//

// #include <cmath>
#include <iostream>

#include "scene.h"


Scene::Scene() {
    InitWindow(mScreenWidth, mScreenHeight, "Raylib - OSC");
    SetTargetFPS(60);

    mCamera.position = (Vector3) { 0.0f, 10.0f, 10.0f };
    mCamera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
    mCamera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
    mCamera.fovy = 45.0f;
    mCamera.projection = CAMERA_PERSPECTIVE;
}

Scene::~Scene() {
    std::cout << "~Scene()" << std::endl;
    CloseWindow();
}

void Scene::update() {
    mAngle -= 0.1;
    mCamera.position = Vector3 {
        cos(mAngle * DEG2RAD) * 10.f,
        10.f,
        sin(mAngle * DEG2RAD) * 10.f
    };
}

void Scene::draw() {
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
