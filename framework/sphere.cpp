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

  std::string Sphere::get_center_()
  {
  std::ostringstream os;
  os << center_.x << " " << center_.y << " " << center_.z;
  return os.str ();
  }

  std::string Sphere::get_radius_()
  {
    std::ostringstream os;
    os << radius_;
    return os.str();
  }

  void Sphere::print_sphere()
  {
    std::cout << name_ << "\n";
    std::cout << get_center_() << "\n";
    std::cout << get_radius_() << "\n";
  }
  