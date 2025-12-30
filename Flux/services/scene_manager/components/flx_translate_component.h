#pragma once

#ifndef FLX_TRANSFORM_COMPONENT_H
#define FLX_TRANSFORM_COMPONENT_H

#include "flx_component.h"

struct FLX_TranslateConfig {
    //vec3 position;
};

class FLX_TranslateComponent final :
    public FLX_Component<FLX_TranslateConfig> {
public:
    explicit FLX_TranslateComponent(FLX_ComponentConfig<FLX_TranslateConfig> config); // constructor
    ~FLX_TranslateComponent() override = default; // destructor
};

#endif