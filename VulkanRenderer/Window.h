#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#pragma once

class Window {
public:
    ~Window();

    static Window* getWindow();

    void init();

    void pollWindowEvents();
    bool shouldWindowClose();
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

private:
    static Window* window; //there can only be one!

    GLFWwindow* m_window;

    Window();

    const uint32_t windowWidth = 800;
    const uint32_t windowHeight = 800;

};
