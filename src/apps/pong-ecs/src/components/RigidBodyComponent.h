#pragma once

#include <glm/glm.hpp>

struct RigidBodyComponent {
  int width;
  int height;
  glm::vec2 velocity;
  glm::vec2 position;

  RigidBodyComponent(
      int width = 0,
      int height = 0,
      glm::vec2 position = glm::vec2(0.0, 0.0),
      glm::vec2 velocity = glm::vec2(0.0, 0.0)) {
    this->width = width;
    this->height = height;
    this->velocity = velocity;
    this->position = position;
  }
};
