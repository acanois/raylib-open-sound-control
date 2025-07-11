//
// Created by David Richter on 7/1/25.
//

#pragma once

#include "osc_handler.h"
#include "reactive_element.h"

#include <raylib.h>

class App {
public:
    App();

    ~App();

    void update();

    void draw();

private:
    static constexpr Vector2 screenDimensions{1280, 720};

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
    float mAngle = 0.f;

    std::unique_ptr<ReactiveElement> mReactiveElement{nullptr};

    Camera3D mCamera;

    std::unique_ptr<OscHandler> mOscHandler{nullptr};
    std::atomic<int> midiNote{0};
};
