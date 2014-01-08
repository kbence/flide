#include "EventDispatcher.h"

namespace sdl {

void EventDispatcher::addWindowEventListener(WindowEventListener listener)
{
	windowEventListeners.push_back(listener);
}

void EventDispatcher::dispatchEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT:
				dispatchWindowEvent(&event.window);
				break;
		}
	}
}

void EventDispatcher::dispatchWindowEvent(SDL_WindowEvent* event)
{
	auto begin = windowEventListeners.begin();
	auto end = windowEventListeners.end();

	for (auto it = begin; it != end; it++) {
		(*it)(event);
	}
}

}
