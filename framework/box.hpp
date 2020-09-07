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
  Box(glm::vec3 min, glm::vec3 max, std::string name, std::shared_ptr<Material>);
  ~Box();

  private:
  glm::vec3 min_;
  glm::vec3 max_;
};

#endif