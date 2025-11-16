#pragma once

#ifndef FLX_EVENT_H
#define FLX_EVENT_H

#include "flx_object.h"
#include "SDL3/SDL_events.h"

class FLX_Event final : public FLX_Object<FLX_ObjectConfig> {
public:
    explicit FLX_Event(FLX_ObjectConfig&& config);
    ~FLX_Event() override = default;

    [[nodiscard]] SDL_Event& event();

private:
    SDL_Event _event;
};

#endif