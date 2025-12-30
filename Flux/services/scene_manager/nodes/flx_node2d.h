#pragma once

#ifndef FLX_NODE_2D_H
#define FLX_NODE_2D_H

#include "../components/flx_translate_component.h"
#include "flx_node.h"

class FLX_Node2D : public FLX_Node {
public:
    FLX_Node2D() = default; // constructor
    ~FLX_Node2D() override = default; // destructor

    virtual void render() = 0;
private:
    FLX_TranslateComponent translate_component;
};

#endif