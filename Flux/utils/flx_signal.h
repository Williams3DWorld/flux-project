#pragma once

#ifndef FLX_SIGNAL_H
#define FLX_SIGNAL_H

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
    uint8_t add(std::function<void(Args...)> callback, const bool is_once = false) {
        _is_once = is_once;

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
                [existing_identifier](const FLX_SignalCallback<Args...>& cb) {
                    return cb.identifier == existing_identifier;
                }
            ),
            _signal_callbacks.end()
        );
    }

    void emit(Args... args) {
        for (const auto& signal_callback : _signal_callbacks) {
            signal_callback.callback(args...);
            if (_is_once) {
                remove(signal_callback.identifier);
            }
        }
    }
private:
    bool _is_once = false;
    uint8_t _next_identifier = 0;
    std::vector<FLX_SignalCallback<Args...>> _signal_callbacks;
};

#endif