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
    clear();
    
    if (rootContainer)
        rootContainer->render();

    SDL_GL_SwapWindow(window);
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

void Window::clear()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

}
