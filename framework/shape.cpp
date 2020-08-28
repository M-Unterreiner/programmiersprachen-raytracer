#include <iostream>
#include <string>
#include <memory>
#include "shape.hpp"
#include "color.hpp"
#include "material.hpp"

Shape::Shape():
  name_{"This is a empty shape!"},
  material_{}
{
}

Shape::Shape(std::string const& name, std::shared_ptr<Material> const& material):
  name_{name},
  material_{material}
{
}

Shape::~Shape()
{
}
