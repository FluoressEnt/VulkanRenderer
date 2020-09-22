#pragma once

class Square {
public:
    Square();
    ~Square();
    void Render();
    void Update();
private:
    bool Init();
    int sizeX;
    int sizeY;
};
