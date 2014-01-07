#include <stdio.h>
#include <SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL_Init failed!");
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Flide", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!window) {
		fprintf(stderr, "SDL_CreateWindow failed!");
		return 1;
	}

	SDL_GLContext context = SDL_GL_CreateContext(window);

	if (!context) {
		fprintf(stderr, "SDL_GL_CreateContext failed!");
		return 1;
	}

	SDL_GL_MakeCurrent(window, context);

	bool running = true;

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

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
