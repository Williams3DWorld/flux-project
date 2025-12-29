#pragma once

#ifndef FLX_SCENE_NODE_H
#define FLX_SCENE_NODE_H

#include "flx_node.h"

class FLX_SceneNode : public FLX_Node {
public:
    FLX_SceneNode() = default; // constructor
    ~FLX_SceneNode() override = default; // destructor

    virtual void render() = 0;
};

#endif