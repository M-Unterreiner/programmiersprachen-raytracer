#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <math.h>
#include "shape.hpp"

class Sphere: public Shape
{
  public:
  Sphere();
  Sphere(glm::vec3 center, double radius, std::string name, std::shared_ptr<Material> material);
  ~Sphere();

  private:
  glm::vec3 center_;
  double radius_;
};

#endif