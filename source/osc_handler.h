//
// Created by David Richter on 7/3/25.

#pragma once

#include <iostream>
#include <lo/lo.h>
#include <lo/lo_cpp.h>

class OscHandler {
public:
    OscHandler() : mSt(9000) {
    }

    void setCallbacks(
        const std::function<void()> &input,
        const std::function<void()> &cleanup) {
        // Wrapper for set_callbacks()
        mSt.set_callbacks(input, cleanup);
    }

    void addMethod(
        const std::string &name,
        const std::string &type,
        const std::function<void(lo_arg **argv, int)> &func) {
        // Wrapper for add_method()
        mSt.add_method(name, type, func);
    }

    void startThread() {
        // Wrapper for start()
        mSt.start();
    }

private:
    lo::ServerThread mSt;

    std::atomic<int> mMidiNote;
};
