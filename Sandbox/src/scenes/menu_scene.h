#pragma once

#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <iostream>
#include <services/scene_manager/scenes/flx_scene.h>

class MenuScene final : public FLX_Scene {
public:
    MenuScene() = default;
    ~MenuScene() override = default;

    void on_enter() override {
        std::cout << "ENTERING: Menu Scene" << std::endl;
    }
    void on_exit() override {
        std::cout << "EXITING: Menu Scene" << std::endl;
    }
    void update(float deltaTime) override {

    }
private:
};

#endif