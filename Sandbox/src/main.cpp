#include <flx.h>

int main(int argc, char** argv) {
	FLX_Instance instance = FLX_CreateInstance({
		.window = FLX_WindowConfig({
			.title = "Sandbox"
		})
	});

	instance.run();

	return 0;
}
