#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{
  glm::vec3 origin_ = {0.0f, 0.0f, 0.0f};
  glm::vec3 direction_ = {0.0f, 0.0f, -1.0f};

  // Does Ray need a constructor even it is a DTO?

  Ray():
    origin_{0.0f, 0.0f, 0.0f},
    direction_{0.0f, 0.0f, -1.0f}
  {}

  Ray(glm::vec3 origin_, glm::vec3 direction): 
  origin_{origin_},
  direction_{glm::normalize(direction)} 
  {}
};

#endif 