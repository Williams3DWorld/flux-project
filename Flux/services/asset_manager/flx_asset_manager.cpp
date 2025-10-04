#include "flx_asset_manager.h"

[[nodiscard]] flx_weak<FLX_TextureSource> FLX_AssetManager::texture_source(const flx_string& identifier) const {
    return _texture_sources.get(identifier);
}