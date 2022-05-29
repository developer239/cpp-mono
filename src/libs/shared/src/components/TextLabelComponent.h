#ifndef TEXT_LABEL_COMPONENT_H
#define TEXT_LABEL_COMPONENT_H

#include <string>
#include <SDL.h>

// TODO: make import absolute?
#include "../../externals/glm/vec2.hpp"

struct TextLabelComponent {
  glm::vec2 position{};
  std::string text;
  SDL_Color color{};
  std::string fontId;

  explicit TextLabelComponent(
      glm::vec2 position = glm::vec2(0),
      const std::string& text = "",
      const SDL_Color& color = { 255, 255, 255 },
      const std::string& assetId = "pico8-font-10"
  ) {
    this->position = position;
    this->text = text;
    this->color = color;
    this->fontId = assetId;
  }
};

#endif
