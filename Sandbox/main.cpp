#include <iostream>
#include <flx.h>

int main(int argc, char** argv) {
	FLX_Init();
	FLX_Instance instance = FLX_CreateInstance({});

	instance.run();

	return 0;
}