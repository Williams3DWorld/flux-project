#include <iostream>
#include <flx.h>

int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	FLX_Instance instance = FLX_CreateInstance({});

	return 0;
}