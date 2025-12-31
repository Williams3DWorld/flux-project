#pragma once

#ifndef FLX_NODE_H
#define FLX_NODE_H

#include "flx_object.h"
#include <vector>
#include <memory>

class FLX_Node : public FLX_Object<FLX_ObjectConfig> {
public:
    explicit FLX_Node(FLX_ObjectConfig&& config) : FLX_Object(std::move(config)) {}
    ~FLX_Node() override = default;

    // scene node specific functions
    void setEnabled(bool value); // enable the node
    void setParent(FLX_Node* parent_node); // set the nodes parent
    void addChild(std::unique_ptr<FLX_Node> child); // add a child to the node
    void removeChild(FLX_Node* child); // remove a child from the node
    void removeAllChildren(); // from all the children from this node(if any)

    // getters
    [[nodiscard]] const bool& isEnabled() const { return _enabled; }
    [[nodiscard]] FLX_Node* getParent() const { return _parent; }
    [[nodiscard]] const std::vector<std::unique_ptr<FLX_Node>>& getChildren() const { return _children; }

    virtual void update(float deltaTime) = 0;
protected:
    // local vars
    bool _enabled = true; // enables node on/off
    std::vector<std::unique_ptr<FLX_Node>> _children; // children of this node
    FLX_Node* _parent = nullptr; // non-owning pointer to the parent node
};

#endif