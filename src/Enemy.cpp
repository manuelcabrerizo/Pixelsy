#include "./Enemy.h"

Enemy::Enemy(int posX, int posY, int velX, int velY, int width, int height,int scale, int life){
    this->position.x = posX;
    this->position.y = posY;
    this->velocity.x = velX;
    this->velocity.y = velY;
    this->width = width;
    this->height = height;
    this->scale = scale;
    this->life = life;
}

void Enemy::Draw(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    textureManager.texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 
}

void Enemy::Update(float deltaTime, Player* player){

    this->colider.Initialize(this->position.x, this->position.y, this->width * this->scale, this->height * this->scale);
    this->dangerZoneIzq.Initialize(this->position.x - (this->width * 3) * this->scale, this->position.y, (this->width * 3) * this->scale, this->height * this->scale);
    this->dangerZoneDer.Initialize(this->position.x + this->width * this->scale, this->position.y, (this->width * 3) * this->scale, this->height * this->scale);
    this->dangerZoneUp.Initialize(this->position.x, this->position.y - (this->height * 3) * this->scale, this->width * this->scale, (this->height * 3) * this->scale);
    this->dangerZoneDown.Initialize(this->position.x, this->position.y + this->height * this->scale, this->width * this->scale, (this->height * 3) * this->scale);
    this->dangerZoneUpIzq.Initialize(this->position.x - (this->width * 3) * this->scale,  this->position.y - (this->height * 3) * this->scale,
     (this->width * 3) * this->scale, (this->height * 3) * this->scale);
    this->dangerZoneDownIzq.Initialize(this->position.x - (this->width * 3) * this->scale, this->position.y + this->height * this->scale,
     (this->width * 3) * this->scale, (this->height * 3) * this->scale);
    this->dangerZoneUpDer.Initialize(this->position.x + this->width * this->scale, this->position.y - (this->height * 3) * this->scale,
     (this->width * 3) * this->scale, (this->height * 3) * this->scale);
    this->dangerZoneDownDer.Initialize(this->position.x + this->width * this->scale, this->position.y + this->height * this->scale,
     (this->width * 3) * this->scale, (this->height * 3) * this->scale);
     

    if(this->GetDangerZoneIzq()->GetisTrigger()){
        this->SetVelocity(-60, 0);
        this->currentRow = 112;
    }else if(this->GetDangerZoneDer()->GetisTrigger()){
        this->SetVelocity(60, 0);
        this->currentRow = 96;
    }else if(this->GetDangerZoneUp()->GetisTrigger()){
        this->SetVelocity(0, -60);
        this->currentRow = 144;
    }else if(this->GetDangerZoneDown()->GetisTrigger()){
        this->SetVelocity(0, 60);
        this->currentRow = 96;
    }else if(this->GetDangerZoneUpIzq()->GetisTrigger()){
        this->SetVelocity(-40, -40);
        this->currentRow = 176;
    }else if(this->GetDangerZoneUpDer()->GetisTrigger()){
        this->SetVelocity(40, -40);
        this->currentRow = 160;
    }else if(this->GetDangerZoneDownDer()->GetisTrigger()){
        this->SetVelocity(40, 40);
        this->currentRow = 96;
    }else if(this->GetDangerZoneDownIzq()->GetisTrigger()){
        this->SetVelocity(-40, 40);
        this->currentRow = 112;
    }else{
        this->SetVelocity(0, 0);
        this->currentRow = 16;
    }
    if(this->colider.GetisTrigger() == true){
        this->currentRow = 128;
    }

    this->numberFrame = 7;
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
    
    

}

void Enemy::Render(){
    if(this->life > 0){
        SDL_RenderCopy(Game::renderer, textureManager.texture,
        &textureManager.sourceRectangle, &textureManager.destinationRectangle);
    }
}

void Enemy::EnemyGetsShoot(){
    if(this->colider.GetisTrigger() == true){
        this->life = this->life - 2;
    }
}
int Enemy::GetLife(){
    return this->life;
}

ColiderComponent* Enemy::GetDangerZoneIzq(){
    return &this->dangerZoneIzq;
}
ColiderComponent* Enemy::GetDangerZoneDer(){
    return &this->dangerZoneDer;
}
ColiderComponent* Enemy::GetDangerZoneUp(){
    return &this->dangerZoneUp;
}
ColiderComponent* Enemy::GetDangerZoneDown(){
    return &this->dangerZoneDown;
}
ColiderComponent* Enemy::GetDangerZoneUpIzq(){
    return &this->dangerZoneUpIzq;
}
ColiderComponent* Enemy::GetDangerZoneUpDer(){
    return &this->dangerZoneUpDer;
}
ColiderComponent* Enemy::GetDangerZoneDownIzq(){
    return &this->dangerZoneDownIzq;
}
ColiderComponent* Enemy::GetDangerZoneDownDer(){
    return &this->dangerZoneDownDer;
}

void Enemy::SetVelocity(int velX, int velY){
    this->velocity.x = velX;
    this->velocity.y = velY;
}
