#include <flx.h>

int main(int argc, char** argv) {
	const FLX_Instance instance = FLX_CreateInstance({
		.window_options = FLX_WindowOptions({
			.title = "Sandbox"
		}),
		.input_options = FLX_InputOptions({
			.action_bindings = {
				{"interact", {FLX_DeviceType::KEYBOARD, SDL_SCANCODE_E}}
			}
		})
	});

	instance.run();

	return 0;
}
