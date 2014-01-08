#include "Window.h"

namespace sdl
{

Window::Window():
	window(nullptr),
	context(nullptr),
	rootContainer(nullptr)
{
	createWindow();
	createContext();
}

Window::~Window()
{
	destroy();
}

void Window::setRoot(display::Container *container)
{
	rootContainer = container;
}

void Window::render()
{
	if (rootContainer)
		rootContainer->render();
}

void Window::createWindow()
{
	if (!(window = SDL_CreateWindow("Flide", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		throw "Failed to create SDL window";
}

void Window::createContext()
{
	if (window) {
		if (!(context = SDL_GL_CreateContext(window)))
			throw "Failed to create SDL GL context!";
		
		if (SDL_GL_MakeCurrent(window, context) < 0)
			throw "Unable to use context!";
	}
}

void Window::deleteContext()
{
	SDL_GL_DeleteContext(context);
}

void Window::destroyWindow()
{
	SDL_DestroyWindow(window);
}

void Window::destroy()
{
	if (context)
		deleteContext();

	if (window)
		destroyWindow();
}

}
