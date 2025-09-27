#include "flx_cache.h"
#include "types/flx_memory.h"

template<typename K, typename V>
[[nodiscard]] flx_weak<V> FLX_Cache<K, V>::get(const K& identifier) const {
    auto it = _data.find(identifier);
    if (it == _data.end()) return {};
    return it->second;
}

template<typename K, typename V>
template<typename... Args>
void FLX_Cache<K, V>::set(K identifier, Args&&... args) {
    _data[identifier] = flx_make_shared<V>(flx_forward<Args>(args)...);
}
