#pragma once

#ifndef FLX_AUDIO_MANAGER_H
#define FLX_AUDIO_MANAGER_H

#include <string>
#include <vector>
#include "../flx_service.h"
#include "SDL3_mixer/SDL_mixer.h"

struct FLX_AudioManagerConfig : FLX_ServiceConfig {
    int freq;
    int channels;
    SDL_AudioFormat audio_format;
};

class FLX_AudioManager final : public FLX_Service<FLX_AudioManagerConfig> {
public:
    explicit FLX_AudioManager(FLX_AudioManagerConfig&& config);
    ~FLX_AudioManager() override;

    MIX_Track* get_free_track();
    void create_track_pool(int pool_size);
    void play_sound(const std::string& sound_id);
private:
    SDL_AudioDeviceID _audio_device_id;
    MIX_Mixer* _audio_mixer;
    std::vector<MIX_Track*> _used_tracks_pool;
    std::vector<MIX_Track*> _track_pool;
};

#endif