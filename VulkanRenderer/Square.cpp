#include "Square.h"
#include "Renderer.h"

Square::Square() {
    //set everything that we want to pass through to the renderer

    //position, colour
    vertices = {{{-0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}},
                {{0.5f, -0.5f}, {0.0f, 1.0f, 1.0f}},
                {{0.5f, 0.5f}, {1.0f, 0.0f, 1.0f}},
                {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}};

    indices = { 0, 1, 2, 2, 3, 0 };

    vertShader = "S:/Code/VulkanRenderer/shaders/vert.spv"; //TODO: make this read from the shader folder instead of hardcoding
    fragShader = "S:/Code/VulkanRenderer/shaders/frag.spv";

    Renderer::getGfxDevice()->setShaderProgram(vertShader, Renderer::ShaderStage::Vertex);
    Renderer::getGfxDevice()->setShaderProgram(fragShader, Renderer::ShaderStage::Fragment);
}

Square::~Square() {

}

//Keep render and update seperate for now. Evaluate once we've fleshed things out more
void Square::Render() {

}

void Square::Update() {

}