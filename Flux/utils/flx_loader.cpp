#include "flx_loader.h"

template<typename T>
FLX_Loader<T>::FLX_Loader(const flx_string_view path) :
    _path(path) {}