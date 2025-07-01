#include "osc_handler.h"
#include "scene.h"


int main() {
    auto scene = std::make_shared<Scene>();
    OscHandler::initOsc();

    scene->update();
    scene->draw();

    return 0;
}
