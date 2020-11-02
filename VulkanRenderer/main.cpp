#include <iostream>
#include <stdexcept>

#include "Window.h"
#include "Renderer.h"
#include "Square.h"

class Application {
public:
    void run() {
        Window::getWindow()->init();

        if (!Renderer::getGfxDevice())
        {
            const char* message = "Graphics device wasn't created succesfully!";
            throw std::exception(message);
        }

        mainLoop();
    }

private:
    void mainLoop() {
        Square* square = new Square();

        while (Window::getWindow()->shouldWindowClose()) {

            Window::getWindow()->pollWindowEvents();
            square->Update(); //first game object - obviously needs abstracting 
            square->Render();
            //renderer->renderFrame(); //how shall I handle rendering every frame?
        }

        Renderer::getGfxDevice()->~Renderer();
        Window::getWindow()->~Window();
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

