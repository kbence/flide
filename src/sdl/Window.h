#include <SDL.h>

#ifndef _FLIDE_SDL_WINDOW_H
#define _FLIDE_SDL_WINDOW_H

namespace sdl {

class Window
{
	SDL_Window *window;
	SDL_GLContext context;

public:
	Window();
	~Window();

private:
	void createWindow();
	void createContext();
	void destroyWindow();
	void deleteContext();
	void destroy();
};

}

#endif // _FLIDE_SDL_WINDOW_H
