#include <flx.h>

int main(int argc, char** argv) {
	FLX_Init();

	const FLX_Instance instance = FLX_CreateInstance({});

	instance.run();

	return 0;
}