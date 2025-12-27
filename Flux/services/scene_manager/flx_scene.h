#ifndef FLX_SCENE_H
#define FLX_SCENE_H

#include <vector>
#include "nodes/flx_node.h"

class FLX_Scene final {
public:
    FLX_Scene() = default;
    ~FLX_Scene() = default;

    void update(float deltaTime) const;
    void render() const {}
private:
    std::vector<std::unique_ptr<FLX_Node>> _children;
};

#endif