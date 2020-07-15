#include "Window.h"


Window::Window() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(windowWidth, windowHeight, "VulkanRenderer", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

}
Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::pollWindowEvents() {
    glfwPollEvents();
}

bool Window::shouldWindowClose() {
    return !glfwWindowShouldClose(window);
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    int newWidth = 0, newHeight = 0;
    glfwGetFramebufferSize(window, &newWidth, &newHeight);
    while (newWidth == 0 || newHeight == 0) {
        glfwGetFramebufferSize(window, &newWidth, &newHeight);
        glfwWaitEvents();
    }
}
