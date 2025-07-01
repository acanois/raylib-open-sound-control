#include "osc_handler.h"
#include "scene.h"


int main() {
    const auto scene = std::make_unique<Scene>();
    OscHandler::initOsc();

    scene->update();
    scene->draw();

    return 0;
}
