#include <flx.h>

#include "scenes/menu_scene.h"
#include "scenes/game_scene.h"

int main(int argc, char** argv) {
	FLX_Instance instance = FLX_CreateInstance({
		.window = FLX_WindowConfig({
			.title = "Sandbox"
		}),
		.scene_manager = FLX_SceneManagerConfig({
			.scenes = {
				{"menu_scene", std::make_shared<MenuScene>()},
				{"game_scene", std::make_shared<GameScene>()}
			}
		})
	});

	instance.run();

	return 0;
}
