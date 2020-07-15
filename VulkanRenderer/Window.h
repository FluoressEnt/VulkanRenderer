#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#pragma once

class Window {
public:
GLFWwindow* window; //is a better way of doing this?

Window();
~Window();

void pollWindowEvents();
bool shouldWindowClose();
static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

private:

const uint32_t windowWidth = 800;
const uint32_t windowHeight = 800;

};
