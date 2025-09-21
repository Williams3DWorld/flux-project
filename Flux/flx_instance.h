#pragma once

#ifndef FLX_INSTANCE_H
#define FLX_INSTANCE_H

#include "flx_window.h"

struct FLX_InstanceOptions {

};

class FLX_Instance {
public:
    FLX_Instance(const FLX_InstanceOptions& options);
    void run() const;

private:
    void _cleanup() const;

    FLX_Window _window;
};

#endif