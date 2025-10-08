#pragma once

#ifndef FLX_CONTEXT_H
#define FLX_CONTEXT_H

class FLX_AssetManager;

struct FLX_Context {
    FLX_AssetManager* asset_manager = nullptr;
};

#endif