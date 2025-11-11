#include "services/flx_audio_manager.h"

FLX_AudioManager::FLX_AudioManager(FLX_AudioManagerConfig &&config) : FLX_Service(std::move(config)) {
    const SDL_AudioDeviceID dev = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
    if (!dev) {
        //std::cerr << "SDL_OpenAudioDevice failed: " << SDL_GetError() << "\n";
    }

    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = 48000;
    audio_spec.format = SDL_AUDIO_F32;
    audio_spec.channels = 2;

    MIX_Mixer* mixer = MIX_CreateMixerDevice(dev, &audio_spec);
    if (!mixer) {
        //std::cerr << "Error creating mixer: " << SDL_GetError() << "\n";
    }
}

void FLX_AudioManager::play_sound(const std::string& sound_id) {
    // TODO: maybe this should be in the asset_manager or a audio_loader ///////
    MIX_Track* track = get_free_track();
    _used_tracks_pool.emplace_back(track);
    // MIX_Audio* sound = asset_manager.get_sound(sound_id)
    //if (!MIX_SetTrackAudio(track, sound)) {
        //std::cerr << "MIX_SetTrackAudio failed: " << SDL_GetError() << "\n";
    //}
    ////////////////////////////////////////////////////////////////////////////

    if (!MIX_PlayTrack(track, 0)) {
        //std::cerr << "MIX_PlayTrack failed: " << SDL_GetError() << "\n";
    } else {
        //std::cout << "Playing sound...\n";
    }
}

void FLX_AudioManager::create_track_pool(int pool_size) {
    if (pool_size <= 0) {
        return;
    }

    for (int i = 0; i < pool_size; i++) {
        MIX_Track* track = MIX_CreateTrack(_audio_mixer);
        _track_pool.push_back(track);
    }
}

MIX_Track* FLX_AudioManager::get_free_track() {
    for (const auto track : _track_pool) {
        auto it = std::find(_used_tracks_pool.begin(), _used_tracks_pool.end(), track);
        if (it == _used_tracks_pool.end()) {
            return track;
        }
    }

    return nullptr;
}
