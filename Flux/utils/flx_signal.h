#pragma once

#ifndef FLX_SIGNAL_H
#define FLX_SIGNAL_H

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

template<typename... Args>
struct FLX_SignalCallback {
    uint8_t identifier;
    std::function<void(Args...)> callback;
};

template<typename... Args>
class FLX_Signal {
public:
    uint8_t add(std::function<void(Args...)> callback) {
        _next_identifier += 1;
        _signal_callbacks.push_back({
            .identifier = _next_identifier,
            .callback = std::move(callback)
        });
        return _next_identifier;
    }

    void remove(uint8_t existing_identifier) {
        _signal_callbacks.erase(
            std::remove_if(
                _signal_callbacks.begin(),
                _signal_callbacks.end(),
                [existing_identifier](const uint8_t& identifier) { return identifier == existing_identifier; }
            ),
            _signal_callbacks.end()
        );
    }

    void emit(Args... args) {
        for (const auto& signal_callback : _signal_callbacks) {
            signal_callback.callback(args...);
        }
    }
private:
    uint8_t _next_identifier = 0;
    std::vector<FLX_SignalCallback<Args...>> _signal_callbacks;
};

#endif