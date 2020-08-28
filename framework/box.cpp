#include "box.hpp"

Box::Box():
  Shape{},
  minimum_{0.0f, 0.0f, 0.0f},
  maximum_{1.0f, 1.0f, 1.0f}
{
}

Box::~Box()
{
}