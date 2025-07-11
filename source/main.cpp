#include <iostream>

#include "app.h"

int main() {
    const auto app = std::make_unique<App>();

    app->draw();

    return 0;
}
