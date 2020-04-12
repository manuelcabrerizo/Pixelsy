#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>
#include "TextureManager.h"
#include "../SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"
#include "GLM/glm.hpp"
#include "ColiderComponent.h"
#include "Tile.h"

class TileMap
{
private:
    std::string texto;
    int MapWidth;
    int MapHeight;
    glm::vec3 CameraOffset;
    TextureManager texturemanager;
    std::vector<Tile>tiles;
    void FillTiles(std::vector<std::string> data);
    glm::vec2 PlayerPos;
public:
    TileMap();
    void Initiallize(std::string fileS, const char* filePath);
    void SetTileTexture();
    void Update(glm::vec2 Position);
    void Render();
    std::vector<Tile>* GetTiles() {return &this->tiles;} 
    int GetMapWidth()const {return this->MapWidth;}
    ColiderComponent colider;
    int TileWidth = 64;
    int TileHeight = 64;
};

#endif