#include <iostream>
#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include "app.h"

int main() {
    // constexpr auto port = 9000;
    // lo::ServerThread st(port);
    //
    // if (!st.is_valid()) {
    //     throw std::runtime_error("Failed to initialize OSC server");
    // }
    //
    // st.set_callbacks(
    //     [&st](){printf("Thread init: %p.\n", &st);},
    //     [](){printf("Thread cleanup.\n");}
    // );
    //
    // std::atomic<int> received(0);
    //
    // st.add_method(
    //     "/midi_note",
    //     "i",
    //     [] (lo_arg **argv, int num_args) {
    //         for (auto i = 0; i < num_args; ++i) {
    //             std::cout << argv[i] << std::endl;
    //         }
    //     }
    // );
    //
    // st.start();

    const auto app = std::make_unique<App>();

    app->draw();

    return 0;
}
