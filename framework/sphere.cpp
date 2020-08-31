#include "sphere.hpp"

  Sphere::Sphere():
  Shape(),
  center_{0, 0, -10},
  radius_{5.0}
  {
  };

  Sphere::Sphere(glm::vec3 center, double radius, std::string name, std::shared_ptr<Material> material):
  Shape(name, material),
  center_{center},
  radius_{radius}
  {
  }

  Sphere::~Sphere()
  {
  };
