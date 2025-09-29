#include <flx.h>

int main(int argc, char** argv) {
	const FLX_Instance instance = FLX_CreateInstance({
		.window_options = FLX_WindowOptions({
			.title = "Sandbox"
		})
	});

	instance.run();

	return 0;
}
