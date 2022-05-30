#include <SDL.h>
#include "App.h"

void App::OnSetup() {
}

void App::OnInput(SDL_Event event) {
  switch (event.type) {
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_LEFT)
        paddle.velX = -400;
      if (event.key.keysym.sym == SDLK_RIGHT)
        paddle.velX = +400;
      break;
    case SDL_KEYUP:
      if (event.key.keysym.sym == SDLK_LEFT)
        paddle.velX = 0;
      if (event.key.keysym.sym == SDLK_RIGHT)
        paddle.velX = 0;
      break;
  }
}

void App::OnUpdate() {
  auto delta_time = time->deltaTime;
  auto WINDOW_WIDTH = state.window.width;
  auto WINDOW_HEIGHT = state.window.width;

  // update ball and paddle position
  ball.x += ball.velX * delta_time;
  ball.y += ball.velY * delta_time;
  paddle.x += paddle.velX * delta_time;
  paddle.y += paddle.velY * delta_time;

  // If ball is lower than the left wall, force the position to be zero before flipping the velocity
  if (ball.x <= 0) {
    ball.x = 0;
    ball.velX = -ball.velX;
  }
  // If ball is lower than the left wall, force the position to be zero before flipping the velocity
  if (ball.y <= 0) {
    ball.y = 0;
    ball.velY = -ball.velY;
  }
  // If ball x plus its width is greater than window width, force position to be at the right of the screen
  if (ball.x + ball.width > WINDOW_WIDTH) {
    ball.x = WINDOW_WIDTH - ball.width;
    ball.velX = -ball.velX;
  }
  // If ball y plus its height is greater than window height, force position to be at the bottom of the screen
  if (ball.x + ball.width > WINDOW_WIDTH) {
    ball.x = WINDOW_WIDTH - ball.width;
    ball.velX = -ball.velX;
  }

  // Check for ball collision with the paddle and force the ball position to be exactly on top of the paddle
  if (ball.y + ball.height >= paddle.y && ball.x + ball.width >= paddle.x && ball.x <= paddle.x + paddle.width) {
    ball.y = paddle.y - ball.height;
    ball.velY = -ball.velY;
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
