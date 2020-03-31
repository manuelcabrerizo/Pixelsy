#ifndef PLAYER_H
#define PLAYER_H
#include "./TextureManager.h"
#include <iostream>
#include "../SDL2/SDL.h"
#include "./glm/glm.hpp"
#include "./ColiderComponent.h"
#include "Hechizo.h"


class Player{
    private:
        glm::vec2 position;
        glm::vec2 velocity;
        int width;
        int height;
        int scale;
        int currentFrame;
        int currentRow;
        int numberFrame;
        bool isDrawable = true;
        const Uint8* keystate;
        TextureManager textureManager;
        bool rWasPress;
        bool lWasPress;
        bool uWasPress;
        bool dWasPress;   
        bool canFire = true;  
        Hechizo fireBall;


    public:
        Player(int posX, int posY, int velX, int velY, int width, int height,int scale);
        void Draw(const char* filePath);
        void InputManager();
        void Update(float deltaTime);
        void Render();
        bool KeyIsDown(SDL_Scancode key);
        Hechizo& GetFireBall();
        ColiderComponent colider; 
        glm::vec2 GetPlayerPosition();
};

#endif