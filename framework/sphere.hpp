#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <ostream>
#include <sstream>

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
  std::string get_center_();
  std::string get_radius_();
  void print_sphere();
  // private:
  glm::vec3 center_;
  double radius_;
};

#endif