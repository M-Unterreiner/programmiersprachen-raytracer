#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include <string>
#include <iostream>
#include "material.hpp"

class Shape
{
  private:
  std::string name_;
  std::shared_ptr <Material> material_;

  public:
  Shape();
  Shape(std::string const& name, std::shared_ptr<Material> const& color);
  ~Shape();
};


#endif
