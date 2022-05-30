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
  // update ball and paddle position
  ball.x += ball.velX * time->deltaTime;
  ball.y += ball.velY * time->deltaTime;
  paddle.x += paddle.velX * time->deltaTime;
  paddle.y += paddle.velY * time->deltaTime;

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
  if (ball.x + ball.width > state.window.width) {
    ball.x = state.window.width - ball.width;
    ball.velX = -ball.velX;
  }

  // If ball y plus its height is greater than window height, force position to be at the bottom of the screen
  if (ball.x + ball.width > state.window.width) {
    ball.x = state.window.width - ball.width;
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
  if (paddle.x >= state.window.width - paddle.width)
    paddle.x = state.window.width - paddle.width;

  // Check for game over
  if (ball.y + ball.height > state.window.height) {
    ball.x = state.window.width / 2;
    ball.y = 0;
  }
}

void App::OnRender() {
  ball.Render(*renderer);
  paddle.Render(*renderer);
}
