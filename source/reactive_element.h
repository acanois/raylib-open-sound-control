//
// Created by David Richter on 7/11/25.
//

#pragma once
#include "raylib.h"

class ReactiveElement {
public:
    ReactiveElement(Vector3 position, Vector3 size, Color color);

    void setDimensions(float x, float y, float z);

    void update();

    void draw();

private:
    Vector3 mPosition{0.f, 0.f, 0.f};
    Vector3 mSize{1.f, 1.f, 1.f};
    Color mColor{255, 255, 255, 255};
};
