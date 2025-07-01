//
// Created by David Richter on 7/1/25.
//

#pragma once

#include <iostream>
#include <lo/lo.h>
#include <lo/lo_cpp.h>

struct OscHandler {
    static void initOsc() {
        lo::ServerThread st(9000);
        if (!st.is_valid()) {
            throw std::runtime_error("Failed to initialize OSC server");
        }

        st.set_callbacks([&st](){printf("Thread init: %p.\n", &st);},
                     [](){printf("Thread cleanup.\n");});

        std::cout << "URL: " << st.url() << std::endl;

        std::atomic<int> received(0);

        st.add_method(
            "/midi_note",
            "i",
            [&received](lo_arg **argv, int) {
                std::cout << "midi_note (" << (++received) << "): " << argv[0]->i << std::endl;
            }
        );

        st.start();

        /*
         * Send some messages to the server we just created on localhost.
         */
        lo::Address a("localhost", "9000");
    }
};
