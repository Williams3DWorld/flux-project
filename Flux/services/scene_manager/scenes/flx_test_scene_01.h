#pragma once

#ifndef FLX_TEST_SCENE_01_H
#define FLX_TEST_SCENE_01_H

#include <iostream>

#include "flx_scene.h"

class FLX_TestScene01 : public FLX_Scene {
public:
    FLX_TestScene01() = default;

    void update(float deltaTime) override {}

    void on_enter() override {
        std::cout << "enter scene 'TestScene01'" << std::endl;
    }

    void on_exit() override {
        std::cout << "exit scene 'TestScene01'" << std::endl;
    }
};

#endif