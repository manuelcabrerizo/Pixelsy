#ifndef ENEMY_H
#define ENEMY_H
#include "./TextureManager.h"
#include <iostream>
#include "../SDL2/SDL.h"
#include "./glm/glm.hpp"

#include "./ColiderComponent.h"

class Player;

class Enemy {
private:
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 CameraOffset;
    int width;
    int height;
    int scale;
    int currentFrame;
    int currentRow;
    int numberFrame;
    bool isDrawable = true;
    TextureManager textureManager;
    int life;
    ColiderComponent dangerZoneIzq;
    ColiderComponent dangerZoneDer;
    ColiderComponent dangerZoneUp;
    ColiderComponent dangerZoneDown;
    ColiderComponent dangerZoneUpIzq;
    ColiderComponent dangerZoneUpDer;
    ColiderComponent dangerZoneDownIzq;
    ColiderComponent dangerZoneDownDer;

public:
    Enemy(int posX, int posY, int velX, int velY, int width, int height,int scale, int life);
    void Draw(const char* filePath);
    void Update(float deltaTime, Player* player);
    void Render();
    ColiderComponent colider;
    void EnemyGetsShoot();
    int GetLife();
    void SetDangerZone();
    void SetVelocity(int velX, int velY);
    ColiderComponent* GetDangerZoneIzq();
    ColiderComponent* GetDangerZoneDer();
    ColiderComponent* GetDangerZoneUp();
    ColiderComponent* GetDangerZoneDown();
    ColiderComponent* GetDangerZoneUpIzq();
    ColiderComponent* GetDangerZoneUpDer();
    ColiderComponent* GetDangerZoneDownIzq();
    ColiderComponent* GetDangerZoneDownDer();

};

#endif