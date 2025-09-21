#include <iostream>
#include <flx.h>

int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Move this

	FLX_Instance instance = FLX_CreateInstance({});

	instance.run();

	return 0;
}