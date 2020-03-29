#ifndef COLIDERCOMPONENT_H
#define COLIDERCOMPONENT_H

#include "./glm/glm.hpp"
#include "../SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"
#include <iostream>

class ColiderComponent{
private:
    SDL_Rect colider;
    glm::vec2 velocity;
    bool isTrigger;
public:
 
    void Initialize(int posX,int posY,int width,int height);
    void IsColiding(ColiderComponent* colider);
    bool GetisTrigger();
    SDL_Rect GetColider();
    void SetPosition(int x, int y)
    {
        colider.x = x;
        colider.y = y;
    }
    void SetVelocity(int velX, int velY);
    void Update(float deltaTime);
    void SetIsTrigger(bool istrigger);
};

#endif