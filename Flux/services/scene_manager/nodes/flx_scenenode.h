#pragma once

#ifndef FLX_NODE_H
#define FLX_NODE_H

#include <vector>
#include <memory>

class FLX_SceneNode {
public:
    FLX_SceneNode() = default;
    virtual ~FLX_SceneNode() = default;

    void setEnabled(bool value);
    void setParent(FLX_SceneNode* parent_node);
    void addChild(std::unique_ptr<FLX_SceneNode> child);
    void removeChild(FLX_SceneNode* child);
    void removeAllChildren();

    [[nodiscard]] const bool& isEnabled() const { return _enabled; }
    [[nodiscard]] FLX_SceneNode* getParent() const { return _parent; }
    [[nodiscard]] const std::vector<std::unique_ptr<FLX_SceneNode>>& getChildren() const { return _children; }

    virtual void update(float deltaTime) const;
    virtual void render() const;
protected:
    virtual void renderSelf() const = 0;
private:
    bool _enabled = true;
    std::vector<std::unique_ptr<FLX_SceneNode>> _children;
    FLX_SceneNode* _parent = nullptr;
};

#endif