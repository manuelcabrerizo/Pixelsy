#if 1
#include "TileMap.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Constants.h"

TileMap::TileMap()
{
    MapWidth = 0;
    MapHeight = 0;
}

void TileMap::Initiallize(std::string fileS, const char* filePath){
    std::ifstream file(fileS);

    std::string line;
    std::string lastLine;
    if(file.is_open()){
        while (std::getline(file, line)){
            if(line != "\0"){
                this->texto += line;
                if(line.size() > 0){
                    lastLine = line;
                } 
                this->texto += "\r\n";
                MapHeight++;
            }
        }

        std::istringstream linesCount(lastLine);
        std::vector<std::string> WidthCount(std::istream_iterator<std::string>{linesCount},
        std::istream_iterator<std::string>());

        MapWidth = WidthCount.size();

    }else{
        std::cout << "Error!!!!!\n";
    }
    file.close();
    std::istringstream split(this->texto);
    std::vector<std::string> resultado(std::istream_iterator<std::string>{split},
    std::istream_iterator<std::string>());

    SDL_Surface* tempSurface = IMG_Load(filePath);
    texturemanager.texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    std::cout << "Test1" << std::endl;
    FillTiles(resultado); 
}

void TileMap::FillTiles(std::vector<std::string> data){
    this->texturemanager.sourceRectangle.w = 16;
    this->texturemanager.sourceRectangle.h = 16; 
    for(int y = 0; y < MapHeight; y++){
        for(int x = 0; x < MapWidth; x++){
             std::cout << data[(y * MapWidth) + x] << " ";
           if(data[(y * MapWidth) + x] == "1"){
                this->texturemanager.sourceRectangle.x = 0;
                this->texturemanager.sourceRectangle.y = 0; 
           }else if(data[(y * MapWidth) + x] == "2"){
                this->texturemanager.sourceRectangle.x = 16;
                this->texturemanager.sourceRectangle.y = 0; 
           }else if(data[(y * MapWidth) + x] == "3"){
                this->texturemanager.sourceRectangle.x = 32;
                this->texturemanager.sourceRectangle.y = 0; 
           }else if(data[(y * MapWidth) + x] == "4"){
                this->texturemanager.sourceRectangle.x = 48;
                this->texturemanager.sourceRectangle.y = 0; 
           }else if(data[(y * MapWidth) + x] == "5"){
                this->texturemanager.sourceRectangle.x = 64;
                this->texturemanager.sourceRectangle.y = 0; 
           }else if(data[(y * MapWidth) + x] == "6"){
                this->texturemanager.sourceRectangle.x = 80;
                this->texturemanager.sourceRectangle.y = 0; 
           }else if(data[(y * MapWidth) + x] == "7"){
                this->texturemanager.sourceRectangle.x = 0;
                this->texturemanager.sourceRectangle.y = 16; 
           }else if(data[(y * MapWidth) + x] == "8"){
                this->texturemanager.sourceRectangle.x = 16;
                this->texturemanager.sourceRectangle.y = 16; 
           }else if(data[(y * MapWidth) + x] == "9"){
                this->texturemanager.sourceRectangle.x = 32;
                this->texturemanager.sourceRectangle.y = 16; 
           }else if(data[(y * MapWidth) + x] == "10"){
                this->texturemanager.sourceRectangle.x = 48;
                this->texturemanager.sourceRectangle.y = 16; 
           }else if(data[(y * MapWidth) + x] == "11"){
                this->texturemanager.sourceRectangle.x = 64;
                this->texturemanager.sourceRectangle.y = 16; 
           }else if(data[(y * MapWidth) + x] == "12"){
                this->texturemanager.sourceRectangle.x = 80;
                this->texturemanager.sourceRectangle.y = 16; 
           }else if(data[(y * MapWidth) + x] == "13"){
                this->texturemanager.sourceRectangle.x = 0;
                this->texturemanager.sourceRectangle.y = 32; 
           }else if(data[(y * MapWidth) + x] == "14"){
                this->texturemanager.sourceRectangle.x = 16;
                this->texturemanager.sourceRectangle.y = 32; 
           }else if(data[(y * MapWidth) + x] == "15"){
                this->texturemanager.sourceRectangle.x = 32;
                this->texturemanager.sourceRectangle.y = 32; 
           }else if(data[(y * MapWidth) + x] == "16"){
                this->texturemanager.sourceRectangle.x = 48;
                this->texturemanager.sourceRectangle.y = 32; 
           }else if(data[(y * MapWidth) + x] == "17"){
                this->texturemanager.sourceRectangle.x = 64;
                this->texturemanager.sourceRectangle.y = 32; 
           }else if(data[(y * MapWidth) + x] == "18"){
                this->texturemanager.sourceRectangle.x = 80;
                this->texturemanager.sourceRectangle.y = 32; 
           }else if(data[(y * MapWidth) + x] == "19"){
                this->texturemanager.sourceRectangle.x = 0;
                this->texturemanager.sourceRectangle.y = 48; 
           }else if(data[(y * MapWidth) + x] == "20"){
                this->texturemanager.sourceRectangle.x = 16;
                this->texturemanager.sourceRectangle.y = 48; 
           }else if(data[(y * MapWidth) + x] == "21"){
                this->texturemanager.sourceRectangle.x = 32;
                this->texturemanager.sourceRectangle.y = 48; 
           }else if(data[(y * MapWidth) + x] == "22"){
                this->texturemanager.sourceRectangle.x = 48;
                this->texturemanager.sourceRectangle.y = 48; 
           }else if(data[(y * MapWidth) + x] == "23"){
                this->texturemanager.sourceRectangle.x = 64;
                this->texturemanager.sourceRectangle.y = 48; 
           }else if(data[(y * MapWidth) + x] == "24"){
                this->texturemanager.sourceRectangle.x = 80;
                this->texturemanager.sourceRectangle.y = 48; 
           }else if(data[(y * MapWidth) + x] == "25"){
                this->texturemanager.sourceRectangle.x = 0;
                this->texturemanager.sourceRectangle.y = 64; 
           }else if(data[(y * MapWidth) + x] == "26"){
                this->texturemanager.sourceRectangle.x = 16;
                this->texturemanager.sourceRectangle.y = 64; 
           }else if(data[(y * MapWidth) + x] == "27"){
                this->texturemanager.sourceRectangle.x = 32;
                this->texturemanager.sourceRectangle.y = 64; 
           }else if(data[(y * MapWidth) + x] == "28"){
                this->texturemanager.sourceRectangle.x = 48;
                this->texturemanager.sourceRectangle.y = 64; 
           }else if(data[(y * MapWidth) + x] == "29"){
                this->texturemanager.sourceRectangle.x = 64;
                this->texturemanager.sourceRectangle.y = 64; 
           }else if(data[(y * MapWidth) + x] == "30"){
                this->texturemanager.sourceRectangle.x = 80;
                this->texturemanager.sourceRectangle.y = 64; 
           }else if(data[(y * MapWidth) + x] == "31"){
                this->texturemanager.sourceRectangle.x = 0;
                this->texturemanager.sourceRectangle.y = 80; 
           }else if(data[(y * MapWidth) + x] == "32"){
                this->texturemanager.sourceRectangle.x = 16;
                this->texturemanager.sourceRectangle.y = 80; 
           }else if(data[(y * MapWidth) + x] == "33"){
                this->texturemanager.sourceRectangle.x = 32;
                this->texturemanager.sourceRectangle.y = 80; 
           }else if(data[(y * MapWidth) + x] == "34"){
                this->texturemanager.sourceRectangle.x = 48;
                this->texturemanager.sourceRectangle.y = 80; 
           }else if(data[(y * MapWidth) + x] == "35"){
                this->texturemanager.sourceRectangle.x = 64;
                this->texturemanager.sourceRectangle.y = 80; 
           }else if(data[(y * MapWidth) + x] == "36"){
                this->texturemanager.sourceRectangle.x = 80;
                this->texturemanager.sourceRectangle.y = 80; 
           }
    
           tiles.push_back(this->texturemanager.sourceRectangle);
        }
        std::cout << std::endl;
    }
}

void TileMap::Update(glm::vec2 Position)
{
    this->PlayerPos = Position;
    CameraOffset.x = WINDOW_WIDTH/2 - Position.x;
    CameraOffset.y = WINDOW_HEIGHT/2 - Position.y;
}

void TileMap::Render()
{
    for(int y = 0; y < MapHeight; y++){
        for(int x = 0; x < MapWidth; x++){
            
            SDL_Rect destinationRect;
            SDL_Rect sourceRect = tiles[(y * MapWidth) + x];

            destinationRect.w  = sourceRect.w * 4;
            destinationRect.h = sourceRect.h * 4;
            destinationRect.x = (x * sourceRect.w * 4)+CameraOffset.x;
            destinationRect.y = (y * sourceRect.h * 4)+CameraOffset.y;

            SDL_RenderCopy(Game::renderer, texturemanager.texture,
            &sourceRect, &destinationRect);

            
        }
    }
}


#endif