#pragma once

#ifndef FLX_SERVICE_H
#define FLX_SERVICE_H

#include "flx_context.h"
#include "flx_object.h"

struct FLX_Context;

using FLX_ServiceConfig = FLX_ObjectConfig;

template<typename T>
concept FLX_ServiceConfigDerived = flx_is_base_of<FLX_ServiceConfig, T>;

template<typename FLX_ServiceConfigDerived>
class FLX_Service : public FLX_Object<FLX_ServiceConfigDerived> {
public:
    explicit  FLX_Service(FLX_ServiceConfigDerived&& config);
    ~FLX_Service() override = default;

    void inject(FLX_Context* context) noexcept;

protected:
    FLX_Context* _ctx;
};

template<typename FLX_ServiceConfigDerived>
FLX_Service<FLX_ServiceConfigDerived>::FLX_Service(FLX_ServiceConfigDerived&& config) :
    FLX_Object<FLX_ServiceConfigDerived>(std::forward<FLX_ServiceConfigDerived>(config)),
    _ctx(nullptr) {}

template<typename FLX_ServiceConfigDerived>
void FLX_Service<FLX_ServiceConfigDerived>::inject(FLX_Context *context) noexcept {
    _ctx = context;
}

#endif