#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{
  glm::vec3 origin = {0.0f, 0.0f, 0.0f};
  glm::vec3 direction = {0.0f, 0.0f, -1.0f};

  // Does Ray need a constructor even it is a DTO? 
};

#endif 