#ifndef HECHIZO_H   
#define HECHIZO_H

#include "./glm/glm.hpp"
#include "./TextureManager.h"
#include "./ColiderComponent.h"
#include <iostream>

class Hechizo {
private:

    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 CameraOffset;
    TextureManager textureManager;
    int width;
    int height;
    int scale;
    int currentFrame;
    int currentRow;
    int numberFrame = 6;
    float distanceTraveledX = 0;
    float distanceTraveledY = 0;
    
public:

    void Initialize(int posX, int posY, int width, int height,int scale);
    void Draw(const char* filePath);
    void Update(float deltaTime, glm::vec2 position);
    void Render();
    void SetVelocity(int velX, int velY);
    void SetPosition(int posX, int posY);
    int GetPositionX();
    int GetPositionY();
    void SetCurrentRow(int row);
    ColiderComponent colider;

};

#endif