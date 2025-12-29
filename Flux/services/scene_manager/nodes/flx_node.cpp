#include "flx_node.h"

void FLX_Node::setEnabled(bool value) {
    this->_enabled = value;
}

void FLX_Node::setParent(FLX_Node* parent_node) {
    this->_parent = parent_node;
}

void FLX_Node::addChild(std::unique_ptr<FLX_Node> child) {
    _children.push_back(std::move(child));
}

void FLX_Node::removeChild(FLX_Node* child) {
    const auto it = std::remove_if(
      _children.begin(),
      _children.end(),
      [&](const std::unique_ptr<FLX_Node>& ptr) {
        return ptr.get() == child;
      }
    );
    if (it != _children.end()) {
        child->setParent(nullptr);
        _children.erase(it, _children.end());
    }
}

void FLX_Node::removeAllChildren() {
    _children.clear();
}

