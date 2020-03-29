#ifndef GAME_H
#define GAME_H

#include "./SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"
#include <vector>



class Game {
private:
  bool isRunning;
  SDL_Window* window;
public:
  Game();
  ~Game();
  SDL_Window* GetWindow(){return window;}
  void Initialize(int width, int height);
  void ProcessInput();
  void Update();
  void Render();
  void Destroy();
  bool IsRunning();
  static SDL_Renderer* renderer;
  int ticksLastFrame;
};

#endif
