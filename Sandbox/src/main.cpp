#include <flx.h>

int main(int argc, char** argv) {
	FLX_Instance instance = FLX_CreateInstance({
		.window = FLX_WindowConfig({
			.title = "Sandbox"
		}),
		.input_options = FLX_InputOptions({
			.action_bindings = {
				{"interact", {KEYBOARD, SDL_SCANCODE_E}}
			}
		})
	});

	instance.run();

	return 0;
}
