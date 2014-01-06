#include <stdio.h>
#include <SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL_Init failed!");
		return 1;
	}

	SDL_Quit();
	return 0;
}
