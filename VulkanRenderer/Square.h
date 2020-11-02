#include "RawVertext.h"

#include <vector>
#pragma once

class Square {
public:
    Square();
    ~Square();
    void Render();
    void Update();

    //so these parts that I made private are public for the time being while I figure out how to share them with the renderer
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;

    std::string vertShader;
    std::string fragShader;
private:
};
