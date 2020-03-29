#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "../SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"
class TextureManager {
public:
    SDL_Texture* texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    int currentFrame;
    int currentRow;
};

#endif