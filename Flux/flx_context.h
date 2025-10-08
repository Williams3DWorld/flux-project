#pragma once

#ifndef FLX_CONTEXT_H
#define FLX_CONTEXT_H

class FLX_AssetManager;
class FLX_RenderManager;

struct FLX_Context {
    FLX_AssetManager* asset_manager = nullptr;
    FLX_RenderManager* render_manager = nullptr;
};

#endif