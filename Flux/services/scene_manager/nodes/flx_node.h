#pragma once

#ifndef FLX_NODE_H
#define FLX_NODE_H

#include <vector>
#include <memory>

class FLX_Node {
public:
    FLX_Node() = default;
    ~FLX_Node() = default;

    void addChild(std::unique_ptr<FLX_Node> child);
    void removeChild(const std::unique_ptr<FLX_Node>& child);

    [[nodiscard]] FLX_Node* getParent() const { return parent; }
    [[nodiscard]] std::vector<std::unique_ptr<FLX_Node>> getChildren() const { return _children; }

    void update(float deltaTime) const;
    void render() const {}
private:
    std::vector<std::unique_ptr<FLX_Node>> _children;
    FLX_Node* parent = nullptr;
};

#endif