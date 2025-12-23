#pragma once

#ifndef FLX_NODE_H
#define FLX_NODE_H

#include <vector>
#include <memory>

class FLX_Node {
public:
    FLX_Node() = default;
    virtual ~FLX_Node() = default;

    void setEnabled(bool value);
    void setParent(FLX_Node* parent_node);
    void addChild(std::unique_ptr<FLX_Node> child);
    void removeChild(FLX_Node* child);
    void removeAllChildren();

    [[nodiscard]] FLX_Node* getParent() const { return _parent; }
    [[nodiscard]] const std::vector<std::unique_ptr<FLX_Node>>& getChildren() const { return _children; }

    void update(float deltaTime) const;
    void render() const {}
private:
    bool _enabled = true;
    std::vector<std::unique_ptr<FLX_Node>> _children;
    FLX_Node* _parent = nullptr;
};

#endif