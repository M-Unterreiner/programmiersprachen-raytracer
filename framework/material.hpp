#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <string>

#include <color.hpp>

struct Material
{
  std::string name_ = "Default material";
  Color ka_{1.0f, 0.0f, 0.0f};
  Color kd_{1.0f, 0.0f, 0.0f};
  Color ks_{1.0f, 0.0f, 0.0f};

  void print_material()
  {
    ka_.print_color();
    kd_.print_color();
    ks_.print_color();
  }
};

#endif 