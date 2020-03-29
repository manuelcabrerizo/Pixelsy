#include "./Game.h"
#include <iostream>
#include "Player.h"
#include "Constants.h"
#include "ColiderComponent.h"
#include "Enemy.h"

SDL_Renderer* Game::renderer;
Player player(70, 10, 0, 0, 16, 16, 4);
Enemy enemy(300, 200, 0, 0, 16, 16, 4, 80);
Enemy enemy2(100, 250, 0, 0, 16, 16, 4, 80);

Game::Game(){
  this->isRunning = false;
}

void Game::Initialize(int width, int height){
  //here we are goin to initialize sdl and also
  //all the entitys and component of our game.
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cerr << "Error Initializing SDL\n";
    return;
  }
  this->window = SDL_CreateWindow("Project-01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  if(!this->window){
    std::cerr << "Error Creating the window\n";
    return;
  }
  renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  
  if(!renderer){
    std::cerr << "Error Creating the renderer\n";
    return;
  }
  
  player.Draw("assets/MagoAnimations.png");
  enemy.Draw("assets/MonstroAnimationsFull.png");
  enemy2.Draw("assets/MonstroAnimationsFull.png");

  this->isRunning = true;
  return;
}

void Game::ProcessInput(){
  //TODO:
  //here we are going to get all the input from the user to
  //implement in our code.
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type)
  {
  case SDL_QUIT:
      this->isRunning = false;
      break;
  case SDL_KEYDOWN:
      if(event.key.keysym.sym == SDLK_ESCAPE){
          this->isRunning = false;
      }
  default:
      break;
  }

  player.InputManager();

}

void Game::Update(){
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->ticksLastFrame + FRAME_TARGET_TIME));
  float deltaTime = (SDL_GetTicks() - this->ticksLastFrame) / 1000.0f;
  if(deltaTime > 0.05){ deltaTime = 0.05; }
  this->ticksLastFrame = SDL_GetTicks();

  player.Update(deltaTime);
  if(enemy.GetLife() > 0){
    enemy.Update(deltaTime, &player);
    enemy.EnemyGetsShoot();
    player.colider.IsColiding(&enemy.colider);
    enemy.GetDangerZoneIzq()->IsColiding(&player.colider);
    enemy.GetDangerZoneDer()->IsColiding(&player.colider);
    enemy.GetDangerZoneUp()->IsColiding(&player.colider);
    enemy.GetDangerZoneDown()->IsColiding(&player.colider);
    enemy.GetDangerZoneUpIzq()->IsColiding(&player.colider);
    enemy.GetDangerZoneUpDer()->IsColiding(&player.colider);
    enemy.GetDangerZoneDownIzq()->IsColiding(&player.colider);
    enemy.GetDangerZoneDownDer()->IsColiding(&player.colider);
    player.GetFireBall().colider.IsColiding(&enemy.colider);

  }else{
    player.colider.SetIsTrigger(false);
  }

  if(enemy2.GetLife() > 0){
    enemy2.Update(deltaTime, &player);
    enemy2.EnemyGetsShoot();
    player.colider.IsColiding(&enemy2.colider);
    enemy2.GetDangerZoneIzq()->IsColiding(&player.colider);
    enemy2.GetDangerZoneDer()->IsColiding(&player.colider);
    enemy2.GetDangerZoneUp()->IsColiding(&player.colider);
    enemy2.GetDangerZoneDown()->IsColiding(&player.colider);
    enemy2.GetDangerZoneUpIzq()->IsColiding(&player.colider);
    enemy2.GetDangerZoneUpDer()->IsColiding(&player.colider);
    enemy2.GetDangerZoneDownIzq()->IsColiding(&player.colider);
    enemy2.GetDangerZoneDownDer()->IsColiding(&player.colider);
    player.GetFireBall().colider.IsColiding(&enemy2.colider);

  }else{
    player.colider.SetIsTrigger(false);
  }

  enemy.colider.IsColiding(&player.GetFireBall().colider);
  enemy2.colider.IsColiding(&player.GetFireBall().colider);
  
}

void Game::Render(){

  SDL_SetRenderDrawColor(renderer ,0, 102, 0, 255);
  SDL_RenderClear(renderer);

  player.Render();
  enemy.Render();
  enemy2.Render();

  SDL_RenderPresent(renderer);

}

void Game::Destroy(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Game::IsRunning(){
  return this-> isRunning;
}
