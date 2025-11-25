#pragma once

#ifndef FLX_SCENE_H
#define FLX_SCENE_H

class FLX_Scene {
public:
    FLX_Scene() = default;
    virtual ~FLX_Scene() = default;

    virtual void on_enter() = 0;
    virtual void on_exit() = 0;
    virtual void update(float deltaTime) = 0;

    void set_is_active(const bool val) { _is_active = val; }

    [[nodiscard]] bool is_active() const { return _is_active; }
private:
    bool _is_active = false;
};

#endif