#include "Player.h"
#include "./Game.h"

Player::Player(int posX, int posY, int velX, int velY, int width, int height,int scale){
    this->position.x = posX;
    this->position.y = posY;
    this->velocity.x = velX;
    this->velocity.y = velY;
    this->width = width;
    this->height = height;
    this->scale = scale;
    //fireBall.Initialize(position.x, position.y, 8, 8, this->scale);
}

void Player::Draw(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    textureManager.texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 
    fireBall.Draw("assets/animation.png");
}

void Player::InputManager(){
    this->keystate = SDL_GetKeyboardState(0);
} 

void Player::Update(float deltaTime){

    if(this->KeyIsDown(SDL_SCANCODE_RIGHT) || this->KeyIsDown(SDL_SCANCODE_D)){ 
        if(
            this->colider.Initialize(this->position.x + (this->width * this->scale), this->position.y, 5, this->height * this->scale);
            this->colider.GetisTrigger() == false
        ){
            this->velocity.x = 200;
            this->velocity.y = 0;
        }else{
            this->velocity.x = 0;
        }
        this->numberFrame = 6;
        this->currentRow = 32;
        this->rWasPress = true;
        this->lWasPress = false;
        this->uWasPress = false;
        this->dWasPress = false;
    }else if(this->KeyIsDown(SDL_SCANCODE_LEFT) || this->KeyIsDown(SDL_SCANCODE_A)){
        if(
            this->colider.Initialize(this->position.x - 5, this->position.y, 5, this->height * this->scale);
            this->colider.GetisTrigger() == false
        ){
            this->velocity.x = -200;
            this->velocity.y = 0;
        }else{
            this->velocity.x = 0;
        }
        this->numberFrame = 6;
        this->currentRow = 16;
        this->rWasPress = false;
        this->lWasPress = true;
        this->uWasPress = false;
        this->dWasPress = false;
    }else if(this->KeyIsDown(SDL_SCANCODE_UP) || this->KeyIsDown(SDL_SCANCODE_W)){
        if(
            this->colider.Initialize(this->position.x, this->position.y - 5, this->width * this->scale, 5);
            this->colider.GetisTrigger() == false
        ){
            this->velocity.x = 0;
            this->velocity.y = -200;
        }else{
            this->velocity.y = 0;
        }
        this->numberFrame = 6;
        this->currentRow = 64;
        this->rWasPress = false;
        this->lWasPress = false;
        this->uWasPress = true;
        this->dWasPress = false;
    }else if(this->KeyIsDown(SDL_SCANCODE_DOWN) || this->KeyIsDown(SDL_SCANCODE_S)){
        if(
            this->colider.Initialize(this->position.x, this->position.y + (this->height * this->scale), this->width * this->scale, 5);
            this->colider.GetisTrigger() == false
        ){
            this->velocity.x = 0;
            this->velocity.y = 200;
        }else{
            this->velocity.y = 0;
        }
        this->numberFrame = 6;
        this->currentRow = 48;
        this->rWasPress = false;
        this->lWasPress = false;
        this->uWasPress = false;
        this->dWasPress = true;
    }else{
        this->numberFrame = 1;
        if(this->rWasPress == true){
            this->currentRow = 32;
        }else if(this->lWasPress == true){
            this->currentRow = 16;
        }else if(this->uWasPress == true){
            this->currentRow = 64;
        }else if(this->dWasPress == true){
            this->currentRow = 48;
        }else{
            this->currentRow = 0;
        }
        this->velocity.x = 0;
        this->velocity.y = 0;
    }

    this->currentFrame = 16 * int(((SDL_GetTicks() / 100) % this->numberFrame));

    this->position.x = this->position.x + this->velocity.x * deltaTime;
    this->position.y = this->position.y + this->velocity.y * deltaTime;

    textureManager.sourceRectangle.x = currentFrame;
    textureManager.sourceRectangle.y = currentRow;
    textureManager.sourceRectangle.w = this->width; 
    textureManager.sourceRectangle.h = this->height;

    textureManager.destinationRectangle.x = this->position.x;
    textureManager.destinationRectangle.y = this->position.y;
    textureManager.destinationRectangle.w = this->width * this->scale;
    textureManager.destinationRectangle.h = this->height * this->scale;

    if(this->KeyIsDown(SDL_SCANCODE_SPACE)){
        if(this->canFire == true){
            if(this->lWasPress == true){

                fireBall.Initialize(this->position.x, this->position.y + 6 * 4, 8, 8, 4);
                fireBall.colider.SetPosition(this->position.x, this->position.y + 6 * this->scale);
                fireBall.colider.SetVelocity(-300, 0);
                fireBall.SetVelocity(-300, 0);
                fireBall.SetCurrentRow(0);

            }else if(this->uWasPress == true){

                fireBall.Initialize(this->position.x + 10 * 4, this->position.y + 8  * 4, 8, 8, 4);
                fireBall.colider.SetVelocity(0, -300);
                fireBall.colider.SetPosition(this->position.x +  10 * this->scale, this->position.y);
                fireBall.SetVelocity(0, -300);
                fireBall.SetCurrentRow(8);
                            
            }else if(this->rWasPress == true){

                fireBall.Initialize(this->position.x + 9 * 4, this->position.y + 5  * 4, 8, 8, 4);
                fireBall.colider.SetVelocity(300, 0);
                fireBall.colider.SetPosition(this->position.x + 9 * this->scale, this->position.y + 5 * this->scale);
                fireBall.SetVelocity(300, 0);
                fireBall.SetCurrentRow(16);
                            
            }else if(this->dWasPress == true){

                fireBall.Initialize(this->position.x - 2 * 4, this->position.y + 2  * 4, 8, 8, 4);
                fireBall.colider.SetVelocity(0, 300);
                fireBall.colider.SetPosition(this->position.x - 2 * this->scale, this->position.y + 2 * this->scale);
                fireBall.SetVelocity(0, 300);
                fireBall.SetCurrentRow(24);
                            
            }
        }
    }

    fireBall.Update(deltaTime, this->position);
    
}

void Player::Render(){
    textureManager.destinationRectangle.x = WINDOW_WIDTH/2;
    textureManager.destinationRectangle.y = WINDOW_HEIGHT/2;
    SDL_RenderCopy(Game::renderer, textureManager.texture,
    &textureManager.sourceRectangle, &textureManager.destinationRectangle);
    fireBall.Render();
}

bool Player::KeyIsDown(SDL_Scancode key){
    if (this->keystate != 0){
        if(this->keystate[key] == 1){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

Hechizo& Player::GetFireBall(){
    return this->fireBall;
}

glm::vec2 Player::GetPlayerPosition(){
    return this->position;
}
