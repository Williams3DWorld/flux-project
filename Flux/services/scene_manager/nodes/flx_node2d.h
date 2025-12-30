#pragma once

#ifndef FLX_SCENE_NODE_H
#define FLX_SCENE_NODE_H

#include "flx_node.h"

class FLX_Node2D : public FLX_Node {
public:
    FLX_Node2D() = default; // constructor
    ~FLX_Node2D() override = default; // destructor

    virtual void render() = 0;
};

#endif