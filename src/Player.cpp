#include "Player.h"
#include "./Game.h"

Player::Player(int posX, int posY, int velX, int velY, int width, int height,int scale){
    this->position.x = posX;
    this->position.y = posY;
    this->width = width;
    this->height = height;
    this->scale = scale;

    currentRow = 0;
    numberFrame = 1;

    this->colider.Initialize(this->position.x, this->position.y, this->width * this->scale, this->height * this->scale);
    fireBalls.push_back(&fireBallUno);
    fireBalls.push_back(&fireBallDos);
    fireBalls.push_back(&fireBallTres);

}

void Player::Draw(const char* filePath){
    SDL_Surface* tempSurface = IMG_Load(filePath);
    textureManager.texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface); 
    fireBallUno.Draw("assets/animation.png");
    fireBallDos.Draw("assets/animation.png");
    fireBallTres.Draw("assets/animation.png");
}

void Player::InputManager(){
    this->keystate = SDL_GetKeyboardState(0);
} 

void Player::Update(float deltaTime, TileMap* map){

    glm::vec2 NewVelocity = {};

    if(this->KeyIsDown(SDL_SCANCODE_A))
    {
        NewVelocity.x = -200;
        NewVelocity.y = 0;
        numberFrame = 6;
        currentRow = 16;
        rWasPress = false;
        lWasPress = true;
        uWasPress = false;
        dWasPress = false;
    }
    else if(this->KeyIsDown(SDL_SCANCODE_D))
    {
        NewVelocity.x = 200;
        NewVelocity.y = 0;
        numberFrame = 6;
        currentRow = 32;
        rWasPress = true;
        lWasPress = false;
        uWasPress = false;
        dWasPress = false;
    }
    else if(this->KeyIsDown(SDL_SCANCODE_W))
    {
        NewVelocity.x = 0;
        NewVelocity.y = -200;
        numberFrame = 6;
        currentRow = 64;
        rWasPress = false;
        lWasPress = false;
        uWasPress = true;
        dWasPress = false;
    }
    else if(this->KeyIsDown(SDL_SCANCODE_S))
    {
        NewVelocity.x = 0;
        NewVelocity.y = 200;
        numberFrame = 6;
        currentRow = 48;
        rWasPress = false;
        lWasPress = false;
        uWasPress = false;
        dWasPress = true;
    }else{
        numberFrame = 1;
    }


   this->currentFrame = 16 * int(((SDL_GetTicks() / 100) % this->numberFrame));

    glm::vec2 NewPosition = this->position + NewVelocity * deltaTime; 

    /*Player Tile Position*/
    int TileMLX = (NewPosition.x + 20) / map->TileWidth;
    int TileMLY = (NewPosition.y + 45) / map->TileHeight;

    int TileMRX = (NewPosition.x + 44) / map->TileWidth;
    int TileMRY = (NewPosition.y + 45) / map->TileHeight;

    int TileLX = (NewPosition.x + 20) / map->TileWidth;
    int TileLY = (NewPosition.y + 64) / map->TileHeight;

    int TileRX = (NewPosition.x + 44) / map->TileWidth;
    int TileRY = (NewPosition.y + 64) / map->TileHeight;

    std::vector<Tile>& Tile = *map->GetTiles();

    if(Tile[TileMRX + TileMRY * map->GetMapWidth()].type == TileType::NO_SOILID &&
        Tile[TileMLX + TileMLY * map->GetMapWidth()].type == TileType::NO_SOILID &&
        Tile[TileLX + TileLY * map->GetMapWidth()].type == TileType::NO_SOILID &&
        Tile[TileRX + TileRY * map->GetMapWidth()].type == TileType::NO_SOILID)
    {
        this->position = NewPosition;

        this->colider.Initialize(this->position.x, this->position.y, this->width * this->scale, this->height * this->scale);
    }  

    if(this->KeyIsDown(SDL_SCANCODE_SPACE)){
        if(coolDown >= 0.2){
            coolDown = 0;
            if(contador <= 2){
                if(this->lWasPress == true){

                    fireBalls[contador]->Initialize(this->position.x, this->position.y + 6 * 4, 8, 8, 4);
                    fireBalls[contador]->colider.SetPosition(this->position.x, this->position.y + 6 * this->scale);
                    fireBalls[contador]->colider.SetVelocity(-300, 0);
                    fireBalls[contador]->SetVelocity(-300, 0);
                    fireBalls[contador]->SetCurrentRow(0);

                }else if(this->uWasPress == true){

                    fireBalls[contador]->Initialize(this->position.x + 10 * 4, this->position.y + 8  * 4, 8, 8, 4);
                    fireBalls[contador]->colider.SetVelocity(0, -300);
                    fireBalls[contador]->colider.SetPosition(this->position.x +  10 * this->scale, this->position.y);
                    fireBalls[contador]->SetVelocity(0, -300);
                    fireBalls[contador]->SetCurrentRow(8);
                            
                }else if(this->rWasPress == true){

                    fireBalls[contador]->Initialize(this->position.x + 9 * 4, this->position.y + 5  * 4, 8, 8, 4);
                    fireBalls[contador]->colider.SetVelocity(300, 0);
                    fireBalls[contador]->colider.SetPosition(this->position.x + 9 * this->scale, this->position.y + 5 * this->scale);
                    fireBalls[contador]->SetVelocity(300, 0);
                    fireBalls[contador]->SetCurrentRow(16);
                            
                }else if(this->dWasPress == true){

                    fireBalls[contador]->Initialize(this->position.x - 2 * 4, this->position.y + 2  * 4, 8, 8, 4);
                    fireBalls[contador]->colider.SetVelocity(0, 300);
                    fireBalls[contador]->colider.SetPosition(this->position.x - 2 * this->scale, this->position.y + 2 * this->scale);
                    fireBalls[contador]->SetVelocity(0, 300);
                    fireBalls[contador]->SetCurrentRow(24);
                            
                }
                contador++;
            }else{
                contador = 0;
            }
        }
    }
    coolDown += deltaTime;
    fireBallUno.Update(deltaTime, this->position);
    fireBallDos.Update(deltaTime, this->position);
    fireBallTres.Update(deltaTime, this->position);
    
}

void Player::Render(){

    textureManager.sourceRectangle.x = currentFrame;
    textureManager.sourceRectangle.y = currentRow;
    textureManager.sourceRectangle.w = this->width; 
    textureManager.sourceRectangle.h = this->height;

    textureManager.destinationRectangle.x = this->position.x;
    textureManager.destinationRectangle.y = this->position.y;
    textureManager.destinationRectangle.w = this->width * this->scale;
    textureManager.destinationRectangle.h = this->height * this->scale;


    textureManager.destinationRectangle.x = WINDOW_WIDTH/2;
    textureManager.destinationRectangle.y = WINDOW_HEIGHT/2;
    SDL_RenderCopy(Game::renderer, textureManager.texture,
    &textureManager.sourceRectangle, &textureManager.destinationRectangle);
    fireBallUno.Render();
    fireBallDos.Render();
    fireBallTres.Render();
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
    return this->fireBallUno;
}

glm::vec2 Player::GetPlayerPosition(){
    return this->position;
}
