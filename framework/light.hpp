#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include <glm/vec3.hpp>
#include "color.hpp"

struct Light
{
  std::string name_ ="default light";
  Color color_ {0.0f, 0.0f, 0.0f};
  glm::vec3 position_ {0,0,0};
  unsigned int brightness_ {0};
};


#endif // LIGHT_HPP