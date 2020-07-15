#include <iostream>
#include <stdexcept>

#include "Window.h"
#include "Renderer.h"

class Application {
public:
    void run() { //improve on this in future
        Window* window = new Window();
        Renderer* renderer = new Renderer(window->window);
        mainLoop(window, renderer);
    }

private:
    void mainLoop(Window* window, Renderer* renderer) {
        while (window->shouldWindowClose()) {
            window->pollWindowEvents();
            //this is probably where we want to call update on gameobjects etc or their related systems
            renderer->renderFrame();
        }

        renderer->~Renderer();
        window->~Window();
    }
};

int main() {
    Application app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

