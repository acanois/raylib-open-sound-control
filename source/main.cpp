#include <iostream>
#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include "scene.h"

int main() {
    constexpr auto port = 9000;
    lo::ServerThread st(port);

    if (!st.is_valid()) {
        throw std::runtime_error("Failed to initialize OSC server");
    }

    st.set_callbacks(
        [&st](){printf("Thread init: %p.\n", &st);},
        [](){printf("Thread cleanup.\n");}
    );

    std::atomic<int> received(0);

    st.add_method(
        "/midi_note",
        "i",
        [&received] (lo_arg **argv, int) {
            std::cout << "midi_note (" << (++received) << "): " << argv[0]->i << std::endl;
        }
    );

    st.start();

    const auto scene = std::make_unique<Scene>();

    scene->draw();

    return 0;
}
