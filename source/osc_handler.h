//
// Created by David Richter on 7/3/25.

#pragma once

#include <iostream>
#include <lo/lo.h>
#include <lo/lo_cpp.h>

class OscHandler {
public:
    OscHandler(const int port) : m_st(port) {
        m_st.set_callbacks(
            []() {
                std::cout << "OscHandler started" << std::endl;
            },
            []() {
                std::cout << "Thread cleanup" << std::endl;
            }
        );

        m_st.add_method(
            "/midi_note",
            "i",
            [](lo_arg **argv, int) {
                std::cout << argv << std::endl;
            }
        );
    }

private:
    lo::ServerThread m_st;

    std::atomic<int> m_midi_note;
};
