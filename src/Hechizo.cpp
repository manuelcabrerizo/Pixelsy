#include "Hechizo.h"
#include "Game.h"

void Hechizo::Initialize(int posX, int posY, int width, int height,int scale){
    this->position.x = posX;
    this->position.y = posY;
    this->width = width;
    this->height = height;
    this->scale = scale;

    this->colider.Initialize(posX, posY, width, height);
}

void Hechizo::Draw(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    textureManager.texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 
}

void Hechizo::Update(float deltaTime, glm::vec2 position){

    CameraOffset.x = WINDOW_WIDTH/2 - position.x;
    CameraOffset.y = WINDOW_HEIGHT/2 - position.y;

    this->position.x = this->position.x + this->velocity.x * deltaTime;
    this->position.y = this->position.y + this->velocity.y * deltaTime;

    this->currentFrame = 8 * int(((SDL_GetTicks() / 100) % this->numberFrame));

    textureManager.sourceRectangle.x = this->currentFrame;
    textureManager.sourceRectangle.y = this->currentRow;
    textureManager.sourceRectangle.w = this->width; 
    textureManager.sourceRectangle.h = this->height;

    textureManager.destinationRectangle.x = this->position.x + CameraOffset.x;
    textureManager.destinationRectangle.y = this->position.y + CameraOffset.y;
    textureManager.destinationRectangle.w = this->width * this->scale;
    textureManager.destinationRectangle.h = this->height * this->scale;

    this->colider.Update(deltaTime);
}

void Hechizo::Render(){
    SDL_RenderCopy(Game::renderer, textureManager.texture,
    &textureManager.sourceRectangle, &textureManager.destinationRectangle);
}

void Hechizo::SetVelocity(int velX, int velY){
    
    this->velocity.x = velX;
    this->velocity.y = velY;
}

void Hechizo::SetCurrentRow(int row){
    this->currentRow = row;
}

void Hechizo::SetPosition(int posX, int posY){
    this->position.x = posX;
    this->position.y = posY;
}

int Hechizo::GetPositionX(){
    return this->position.x;
}

int Hechizo::GetPositionY(){
    return this->position.y;
}