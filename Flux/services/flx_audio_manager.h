#pragma once

#ifndef FLX_AUDIO_MANAGER_H
#define FLX_AUDIO_MANAGER_H

#include <string>
#include <vector>
#include "../flx_service.h"
#include "SDL3_mixer/SDL_mixer.h"

struct FLX_AudioManagerConfig : FLX_ServiceConfig {};

class FLX_AudioManager final : public FLX_Service<FLX_AudioManagerConfig> {
public:
    explicit FLX_AudioManager(FLX_AudioManagerConfig&& config);
    ~FLX_AudioManager() override;

    void play_sound(const std::string& sound_id);
private:
};

#endif