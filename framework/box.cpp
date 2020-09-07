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