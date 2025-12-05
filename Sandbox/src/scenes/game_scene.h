#pragma once

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <services/scene_manager/scenes/flx_scene.h>

class GameScene final : public FLX_Scene {
public:
    GameScene() = default;
    ~GameScene() override = default;

    void on_enter() override {
        std::cout << "ENTERING: Game Scene" << std::endl;
    }
    void on_exit() override {
        std::cout << "EXITING: Game Scene" << std::endl;
    }
    void update(float deltaTime) override {}
private:
};

#endif