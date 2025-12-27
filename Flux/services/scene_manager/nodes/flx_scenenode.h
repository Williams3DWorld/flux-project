#pragma once

#ifndef FLX_NODE_H
#define FLX_NODE_H

#include <vector>
#include <memory>

class FLX_SceneNode {
public:
    FLX_SceneNode() = default; // constructor
    virtual ~FLX_SceneNode() = default; // destructor

    // scene node specific functions
    void setEnabled(bool value); // enable the node
    void setParent(FLX_SceneNode* parent_node); // set the nodes parent
    void addChild(std::unique_ptr<FLX_SceneNode> child); // add a child to the node
    void removeChild(FLX_SceneNode* child); // remove a child from the node
    void removeAllChildren(); // from all the children from this node(if any)

    // getters
    [[nodiscard]] const bool& isEnabled() const { return _enabled; }
    [[nodiscard]] FLX_SceneNode* getParent() const { return _parent; }
    [[nodiscard]] const std::vector<std::unique_ptr<FLX_SceneNode>>& getChildren() const { return _children; }

    // node update and render functions
    void update(float deltaTime) const;
    void render() const;
protected:
    // update and render self functions for custom logic
    virtual void updateSelf() const = 0;
    virtual void renderSelf() const = 0;
private:
    // local vars
    bool _enabled = true; // enables node on/off
    std::vector<std::unique_ptr<FLX_SceneNode>> _children; // children of this node
    FLX_SceneNode* _parent = nullptr; // non-owning pointer to the parent node
};

#endif