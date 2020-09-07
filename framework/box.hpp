#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include <sstream>

#include "shape.hpp"
#include "material.hpp"
#include "color.hpp"

class Box: public Shape
{
  public:
  Box();
  Box(glm::vec3 min, glm::vec3 max, std::string name, std::shared_ptr<Material>);
  ~Box();

  std::string test_min_();
  std::string test_max_();

  // private:
  glm::vec3 min_;
  glm::vec3 max_;
};

#endif