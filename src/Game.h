#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "TileMap.h"
#include "./SDL2/SDL.h"
#include "./SDL2/SDL_image.h"
#include "./SDL2/SDL_ttf.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game {
private:
  bool isRunning;
  SDL_Window* window;
  std::vector<std::string> tileMap;
  Player player;
  Enemy enemy;
  Enemy enemy2;
  TileMap map;
  std::vector<std::string>mapData;

public:
  Game();
  ~Game();
  SDL_Window* GetWindow(){return window;}
  void Initialize(int width, int height);
  void ProcessInput();
  void Update(float deltaTime);
  void Render();
  void Destroy();
  bool IsRunning();
  static SDL_Renderer* renderer;
  int ticksLastFrame;
};

#endif
