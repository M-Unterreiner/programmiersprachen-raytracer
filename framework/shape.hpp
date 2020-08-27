#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "color.hpp"

class Shape
{
  private:
  std::string name_;
  Color color_;

  public:
  Shape();
  Shape(std::string const& name, Color const& color);
  ~Shape();
};


#endif
