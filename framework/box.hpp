#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>

#include "shape.hpp"
#include "material.hpp"
#include "color.hpp"

class Box: public Shape
{
  public:
  Box();
  ~Box();

  private:
  glm::vec3 minimum_;
  glm::vec3 maximum_;
};

#endif