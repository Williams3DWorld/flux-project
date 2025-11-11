#include "services/flx_audio_manager.h"

FLX_AudioManager::FLX_AudioManager(FLX_AudioManagerConfig &&config) :
    FLX_Service(std::move(config)) {
}

void FLX_AudioManager::play_sound(const std::string& sound_id) {
    
}
