#include "flx.h"

FLX_Instance FLX_CreateInstance(FLX_InstanceConfig&& config) {
    return FLX_Instance(std::move(config));
}