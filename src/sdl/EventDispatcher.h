#include <functional>
#include <vector>
#include <SDL.h>

#ifndef _FLIDE_SDL_EVENTDISPATCHER
#define _FLIDE_SDL_EVENTDISPATCHER

namespace sdl
{

class EventDispatcher
{
public:
    typedef std::function<void (SDL_WindowEvent*)> WindowEventListener;

private:
    std::vector<WindowEventListener> windowEventListeners;

public:
    void addWindowEventListener(WindowEventListener listener);
    void dispatchEvents();

private:
    void dispatchWindowEvent(SDL_WindowEvent* event);
};

}

#endif // _FLIDE_SDL_EVENTDISPATCHER
