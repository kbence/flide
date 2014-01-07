#include <stdio.h>
#include <SDL.h>
#include "sdl/Window.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL_Init failed!");
		return 1;
	}

	try {
		bool running = true;
		sdl::Window *window = new sdl::Window();

		while (running) {
			SDL_Event event;

			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					case SDL_WINDOWEVENT:
						switch (event.window.event) {
							case SDL_WINDOWEVENT_CLOSE:
								running = false;
								break;
						}
						break;
				}
			}
		}

		delete window;
	} catch (const char* error) {
		fprintf(stderr, "%s\n", error);
		return 1;
	}

	SDL_Quit();

	return 0;
}
