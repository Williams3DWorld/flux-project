#pragma once

#ifndef FLX_AUDIO_LOADER_H
#define FLX_AUDIO_LOADER_H

#include <memory>
#include <vector>
#include <deque>
#include <string_view>
#include <string>
#include "SDL3_mixer/SDL_mixer.h"
#include "utils/flx_loader.h"

using FLX_AudioLoaderConfig = FLX_LoaderConfig;

constexpr int MAX_NUM_TRACKS = 10;

struct FLX_AudioSource {
    std::string identifier;
    std::unique_ptr<MIX_Audio, decltype(&MIX_DestroyAudio)> audio;
    MIX_Track* track;
};

using MixerUniquePtr = std::unique_ptr<MIX_Mixer, decltype(&MIX_DestroyMixer)>;
using TrackUniquePtr = std::unique_ptr<MIX_Track, decltype(&MIX_DestroyTrack)>;
using AudioUniquePtr = std::unique_ptr<MIX_Audio, decltype(&MIX_DestroyAudio)>;

class FLX_AudioLoader final : public FLX_Loader<FLX_AudioLoaderConfig, MIX_Track*> {
public:
    explicit FLX_AudioLoader(FLX_AudioLoaderConfig&& config);
    ~FLX_AudioLoader() override = default;

    void create_track_pool(int pool_size);
    MixerUniquePtr create_mixer();

    MIX_Track* get_track();
    MIX_Track* load(const std::string_view path) override;
private:
    SDL_AudioDeviceID _device_id;
    MixerUniquePtr _mixer;
    std::vector<FLX_AudioSource> _sources;
    std::deque<TrackUniquePtr> _track_pool;
};

#endif