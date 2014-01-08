#include <SDL.h>
#include "../display/Container.h"

#ifndef _FLIDE_SDL_WINDOW_H
#define _FLIDE_SDL_WINDOW_H

namespace sdl {

class Window
{
	SDL_Window *window;
	SDL_GLContext context;
	display::Container *rootContainer;

public:
	Window();
	~Window();

	void setRoot(display::Container* container);
	void render();

private:
	void createWindow();
	void createContext();
	void destroyWindow();
	void deleteContext();
	void destroy();
};

}

#endif // _FLIDE_SDL_WINDOW_H
