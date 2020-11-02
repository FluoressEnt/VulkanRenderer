#include "Renderer.h"
#include "Window.h"


Window::Window() {

}

Window::~Window() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

Window* Window::getWindow() {
    if (window == 0)
        window = new Window();
    return window;
}

void Window::init() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_window = glfwCreateWindow(windowWidth, windowHeight, "VulkanRenderer", nullptr, nullptr);
    glfwSetWindowUserPointer(m_window, this);
    glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);

    Renderer* gfxDevice = Renderer::getGfxDevice();
    gfxDevice->setWindow(m_window);
}

void Window::pollWindowEvents() {
    glfwPollEvents();
}

bool Window::shouldWindowClose() {
    return !glfwWindowShouldClose(m_window);
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    int newWidth = 0, newHeight = 0;
    glfwGetFramebufferSize(window, &newWidth, &newHeight);
    while (newWidth == 0 || newHeight == 0) {
        glfwGetFramebufferSize(window, &newWidth, &newHeight);
        glfwWaitEvents();
    }
}
