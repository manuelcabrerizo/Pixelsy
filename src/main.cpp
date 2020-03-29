#include <iostream>
#include "./SDL2/SDL.h"
#include "./Game.h"

int main (int argc, char* args[]){
  Game* game = new Game();

  game->Initialize(680, 460);
  float LastTime = SDL_GetTicks();

  while (game->IsRunning()) {
    game->ProcessInput();
    game->Update();
    game->Render();

    float CurrentTime = SDL_GetTicks();
    float MSPerFrame = (CurrentTime - LastTime);
    LastTime = CurrentTime;

    char buffer[25];
    sprintf(buffer, "FPS: %f - MS: %f", 1/(MSPerFrame/1000), MSPerFrame);
    SDL_SetWindowTitle(game->GetWindow(), buffer);
  }
  game->Destroy();
  return 0;
}
