//
// Created by David Richter on 7/1/25.
//

#pragma once


#include <raylib.h>

class Scene {
public:
    Scene();
    ~Scene();

    void update();
    void draw();

    static constexpr int mScreenWidth = 1280;
    static constexpr int mScreenHeight = 720;

    Camera3D mCamera = {};
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    float mAngle = 0.f;
};
