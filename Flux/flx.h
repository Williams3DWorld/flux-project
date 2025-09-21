#pragma once

#ifndef FLX_H
#define FLX_H

#include"flx_instance.h"

inline FLX_Instance FLX_CreateInstance(const FLX_InstanceOptions &options) {
    return FLX_Instance(options);
}

namespace FLX {
    void init();
};

#endif