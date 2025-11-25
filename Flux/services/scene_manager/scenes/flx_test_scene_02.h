#pragma once

#ifndef FLX_TEST_SCENE_02_H
#define FLX_TEST_SCENE_02_H

#include <iostream>

#include "flx_scene.h"

class FLX_TestScene02 : public FLX_Scene {
public:
    FLX_TestScene02() = default;
    ~FLX_TestScene02() override = default;

    void update(float deltaTime) override {}

    void on_enter() override {
        std::cout << "enter scene 'TestScene02'" << std::endl;
    }

    void on_exit() override {
        std::cout << "exit scene 'TestScene02'" << std::endl;
    }
};

#endif