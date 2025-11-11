#pragma once

#ifndef FLX_AUDIO_LOADER_H
#define FLX_AUDIO_LOADER_H

#include <vector>
#include <string_view>
#include "SDL3_mixer/SDL_mixer.h"
#include "utils/flx_loader.h"

using FLX_AudioLoaderConfig = FLX_LoaderConfig;

class FLX_AudioLoader final : public FLX_Loader<FLX_AudioLoaderConfig, MIX_Audio*> {
public:
    explicit FLX_AudioLoader(FLX_AudioLoaderConfig&& config);
    ~FLX_AudioLoader() override = default;

    void create_track_pool(int pool_size);
    MIX_Track* get_free_track();
    MIX_Audio* load(std::string_view path) override;
private:
    SDL_AudioDeviceID _audio_device_id;
    MIX_Mixer* _audio_mixer;
    std::vector<MIX_Track*> _used_tracks_pool;
    std::vector<MIX_Track*> _track_pool;
};

#endif