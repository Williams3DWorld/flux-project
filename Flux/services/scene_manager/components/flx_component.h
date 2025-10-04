#pragma once

#ifndef FLX_COMPONENT_H
#define FLX_COMPONENT_H

template<typename T>
class FLX_Component {
public:
    explicit FLX_Component(T data);
    ~FLX_Component() = default;

    [[nodiscard]] T value() const noexcept;

    void value(T data);

protected:
    T _value;
};

#endif