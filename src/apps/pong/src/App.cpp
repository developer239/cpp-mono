#include <SDL.h>
#include "App.h"

// Declare two game objects for the ball and the paddle
struct game_object {
  float x;
  float y;
  float width;
  float height;
  float vel_x;
  float vel_y;
} ball, paddle;

void App::OnSetup() {
  ball.width = 15;
  ball.height = 15;
  ball.x = 20;
  ball.y = 20;
  ball.vel_x = 300;
  ball.vel_y = 300;

  paddle.width = 100;
  paddle.height = 20;
  paddle.x = (state.window.width / 2) - (paddle.width / 2);
  paddle.y = state.window.height - 40;
  paddle.vel_x = 0;
  paddle.vel_y = 0;
}

void App::OnInput(SDL_Event event) {
  switch (event.type) {
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_LEFT)
        paddle.vel_x = -400;
      if (event.key.keysym.sym == SDLK_RIGHT)
        paddle.vel_x = +400;
      break;
    case SDL_KEYUP:
      if (event.key.keysym.sym == SDLK_LEFT)
        paddle.vel_x = 0;
      if (event.key.keysym.sym == SDLK_RIGHT)
        paddle.vel_x = 0;
      break;
  }
}

void App::OnUpdate() {
  auto delta_time = time->deltaTime;
  auto WINDOW_WIDTH = state.window.width;
  auto WINDOW_HEIGHT = state.window.width;

  // update ball and paddle position
  ball.x += ball.vel_x * delta_time;
  ball.y += ball.vel_y * delta_time;
  paddle.x += paddle.vel_x * delta_time;
  paddle.y += paddle.vel_y * delta_time;

  // If ball is lower than the left wall, force the position to be zero before flipping the velocity
  if (ball.x <= 0) {
    ball.x = 0;
    ball.vel_x = -ball.vel_x;
  }
  // If ball is lower than the left wall, force the position to be zero before flipping the velocity
  if (ball.y <= 0) {
    ball.y = 0;
    ball.vel_y = -ball.vel_y;
  }
  // If ball x plus its width is greater than window width, force position to be at the right of the screen
  if (ball.x + ball.width > WINDOW_WIDTH) {
    ball.x = WINDOW_WIDTH - ball.width;
    ball.vel_x = -ball.vel_x;
  }
  // If ball y plus its height is greater than window height, force position to be at the bottom of the screen
  if (ball.x + ball.width > WINDOW_WIDTH) {
    ball.x = WINDOW_WIDTH - ball.width;
    ball.vel_x = -ball.vel_x;
  }

  // Check for ball collision with the paddle and force the ball position to be exactly on top of the paddle
  if (ball.y + ball.height >= paddle.y && ball.x + ball.width >= paddle.x && ball.x <= paddle.x + paddle.width) {
    ball.y = paddle.y - ball.height;
    ball.vel_y = -ball.vel_y;
  }

  // Prevent paddle from moving outside the boundaries of the window
  if (paddle.x <= 0)
    paddle.x = 0;
  if (paddle.x >= WINDOW_WIDTH - paddle.width)
    paddle.x = WINDOW_WIDTH - paddle.width;

  // Check for game over
  if (ball.y + ball.height > WINDOW_HEIGHT) {
    ball.x = WINDOW_WIDTH / 2;
    ball.y = 0;
  }
}

void App::OnRender() {
  // Draw a rectangle for the ball object
  SDL_Rect ball_rect = {
      (int) ball.x,
      (int) ball.y,
      (int) ball.width,
      (int) ball.height
  };
  SDL_SetRenderDrawColor(renderer->renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer->renderer, &ball_rect);

  // Draw a rectangle for the paddle object
  SDL_Rect paddle_rect = {
      (int) paddle.x,
      (int) paddle.y,
      (int) paddle.width,
      (int) paddle.height
  };
  SDL_SetRenderDrawColor(renderer->renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer->renderer, &paddle_rect);
}
