#include <iostream>
#include <stdexcept>

#include "Window.h"
#include "Renderer.h"
#include "Square.h"

class Application {
public:
    void run() {

        if (!Window::getWindow())
        {
            const char* message = "GLFW wasn't initialised!";
            throw std::exception(message);
        }
        if (!Renderer::getGfxDevice())
        {
            const char* message = "Graphics device wasn't created succesfully!";
            throw std::exception(message);
        }

        Window::getWindow()->init();
        Renderer::getGfxDevice()->firstInit();

        mainLoop();
    }

private:
    void mainLoop() {
        Square* square = new Square();
        Renderer::getGfxDevice()->secondInit(); //TODO: We shouldn't be initialising game objects 
                                                //then the renderer to accomodate the gfx pipeline 

        while (Window::getWindow()->shouldWindowClose()) {

            Window::getWindow()->pollWindowEvents();
            square->Update(); //first game object - obviously needs abstracting 
            square->Render();
            Renderer::getGfxDevice()->renderFrame(); //how shall I handle rendering every frame?
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

