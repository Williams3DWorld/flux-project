#include <flx.h>

int main(int argc, char** argv) {
	FLX_Init({
		.window_options = FLX_WindowOptions({
			.resizable = true
		})
	})
	.run();

	return 0;
}