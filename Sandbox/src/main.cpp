#include <flx.h>

int main(int argc, char** argv) {
	FLX_Instance instance = FLX_CreateInstance({
		.window = FLX_WindowConfig({
			.title = "Sandbox"
		}),
		.scene_manager = FLX_SceneManagerConfig({
	        //{"test_scene_01", std::make_shared<FLX_TestScene01>()},
			//{"test_scene_02", std::make_shared<FLX_TestScene02>()},
		})
	});

	instance.run();

	return 0;
}
