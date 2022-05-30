#pragma once

#include <string>
#include <glm/glm.hpp>
#include <SDL.h>

struct TextLabelComponent {
  glm::vec2 position;
  std::string text;
  SDL_Color color;
  std::string fontId;

  explicit TextLabelComponent(
      glm::vec2 position = glm::vec2(0),
      const std::string& text = "",
      const SDL_Color& color = { 0, 0, 0 },
      const std::string& assetId = "pico8-font-10"
  ) {
    this->position = position;
    this->text = text;
    this->fontId = assetId;
    this->color = color;
  }
};
