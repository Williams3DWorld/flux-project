#pragma once

#ifndef FLX_CONTEXT_H
#define FLX_CONTEXT_H

class FLX_InputManager;
class FLX_AssetManager;
class FLX_RenderManager;
class FLX_SceneManager;

struct FLX_Context {
    FLX_InputManager* input_manager = nullptr;
    FLX_AssetManager* asset_manager = nullptr;
    FLX_RenderManager* render_manager = nullptr;
    FLX_SceneManager* scene_manager = nullptr;
};

#endif