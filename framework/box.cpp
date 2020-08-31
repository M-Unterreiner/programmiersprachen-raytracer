#include "box.hpp"

Box::Box():
  Shape{},
  minimum_{0.0f, 0.0f, 0.0f},
  maximum_{1.0f, 1.0f, 1.0f}
{
}

Box::Box(glm::vec3 minimum, glm::vec3 maximum, std::string name, std::shared_ptr<Material> material):
  Shape{name, material},
  minimum_{minimum},
  maximum_{maximum}
{
}

Box::~Box()
{
}