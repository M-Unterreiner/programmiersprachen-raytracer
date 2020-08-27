#include <iostream>
#include <string>
#include "shape.hpp"
#include "color.hpp"

Shape::Shape():
  name_{"This is a empty shape!"},
  color_{Color{30.0f, 30.0f, 30.0f}}
{
}

Shape::Shape(std::string const& name, Color const& color):
  name_{name},
  color_{color}
{
}

Shape::~Shape()
{
}
