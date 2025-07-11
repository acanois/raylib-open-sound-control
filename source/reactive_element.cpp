//
// Created by David Richter on 7/11/25.
//

#include "reactive_element.h"

ReactiveElement::ReactiveElement(const Vector3 position, const Vector3 size, const Color color)
    : mPosition(position),
      mSize(size),
      mColor(color) {
}

void ReactiveElement::setDimensions(const float x, const float y, const float z) {
    mSize.x = x;
    mSize.y = y;
    mSize.z = z;
}


void ReactiveElement::update() {
}


void ReactiveElement::draw() {
    DrawCube(mPosition, mSize.x, mSize.y, mSize.z, mColor);
}
