#include "RawVertext.h"

#include <vector>
#pragma once

class Square {
public:
    Square();
    ~Square();
    void Render();
    void Update();

private:
    std::string vertShader;
    std::string fragShader;
    //float vertices[24];
    //uint16_t indices[6];

    //for now hard code this here - refarctor to read in from file to emulate model loading later
    // vec3 position, vec3 color
    float vertices[24] =
                {-0.5f, -0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  //red
                  0.5f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  //blue
                  0.5f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  //red
                 -0.5f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f}; //blue

    uint16_t indices[6] = { 0, 1, 2, 2, 3, 0 };
};
