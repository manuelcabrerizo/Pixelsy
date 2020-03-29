#include "ColiderComponent.h"

void ColiderComponent::Initialize(int posX,int posY,int width,int height){
    this->colider.x = posX;
    this->colider.y = posY;
    this->colider.w = width;
    this->colider.h = height;
}

void ColiderComponent::IsColiding(ColiderComponent* colider){
    if(
        this->colider.x + this->colider.w > colider->colider.x &&
        this->colider.x < colider->colider.x + colider->colider.w &&
        this->colider.y + this->colider.h > colider->colider.y &&
        this->colider.y < colider->colider.y + colider->colider.h
    ){
        this->isTrigger = true;
    }else{
        this->isTrigger = false;
    }
}

bool ColiderComponent::GetisTrigger(){
    return this->isTrigger;
}

SDL_Rect ColiderComponent::GetColider(){
    return this->colider;
}

void ColiderComponent::SetVelocity(int velX, int velY){
    this->velocity.x = velX;
    this->velocity.y = velY;
}

void ColiderComponent::Update(float deltaTime){
    this->colider.x = this->colider.x + this->velocity.x * deltaTime;
    this->colider.y = this->colider.y + this->velocity.y * deltaTime;
}

void ColiderComponent::SetIsTrigger(bool istrigger){
    this->isTrigger = istrigger;
}
