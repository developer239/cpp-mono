#pragma once

#include <glm/glm.hpp>

struct BoundingBoxComponent {
  int positionX;
  int positionY;
  int width;
  int height;
  SDL_Color color;
  int thickness;

  BoundingBoxComponent(
      const int& positionX = 0,
      const int& positionY = 0,
      const int& width = 0,
      const int& height = 0,
      const cv::Scalar& color = cv::Scalar(255, 0, 0),
      const int& thickness = 1
  ) {
    this->positionX = positionX;
    this->positionY = positionY;
    this->width = width;
    this->height = height;
    this->color = color;
    this->thickness = thickness;
  }
};

#endif
