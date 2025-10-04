#pragma once

#ifndef FLX_INSTANCE_H
#define FLX_INSTANCE_H

#include "flx_window.h"
#include "input/flx_input_map.h"

struct FLX_InstanceOptions {
    FLX_WindowOptions window_options;
    FLX_InputOptions input_options;
};

class FLX_Instance {
public:
    explicit FLX_Instance(const FLX_InstanceOptions& options);

    void run() const;
private:
    FLX_InstanceOptions _options;
};

#endif