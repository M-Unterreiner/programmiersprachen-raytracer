#include "box.hpp"

Box::Box():
  Shape{},
  min_{0.0f, 0.0f, 0.0f},
  max_{1.0f, 1.0f, 1.0f}
{
}

Box::Box(glm::vec3 minimum, glm::vec3 maximum, std::string name, std::shared_ptr<Material> material):
  Shape{name, material},
  min_{minimum},
  max_{maximum}
{
}

Box::~Box()
{
}

// ostream would be more elegant
std::string Box::test_min_()
{
  std::ostringstream os;
  os << min_.x << " " << min_.y << " " << min_.z;
  return os.str ();
}

std::string Box::test_max_()
{
  std::ostringstream os;
  os << max_.x << " " << max_.y << " " << max_.z;
  return os.str ();
}


  void Box::print_box()
  {
    std::cout << name_ << "\n";
    std::cout << test_min_() << "\n";
    std::cout << test_max_() << "\n";
  }
  