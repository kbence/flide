#include <stdio.h>
#include <SDL.h>
#include "sdl/EventDispatcher.h"
#include "sdl/Window.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL_Init failed!");
        return 1;
    }

    try {
        bool running = true;
        sdl::EventDispatcher dispatcher;
        sdl::Window *window = new sdl::Window();

        dispatcher.addWindowEventListener([&running] (SDL_WindowEvent *event) {
            if (event->event == SDL_WINDOWEVENT_CLOSE)
                running = false;
        });

        while (running) {
            dispatcher.dispatchEvents();
        }

        delete window;
    } catch (const char* error) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    SDL_Quit();

    return 0;
}
