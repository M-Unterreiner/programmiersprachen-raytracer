#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <ostream>
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

  friend std::ostream &operator<<(std::ostream &os, Material const &m)
  {
    std::cout << "Name_: " << m.name_ << std::endl;
    std::cout << "ka: " << m.ka_.r << ", " << m.ka_.g << ", " << m.ka_.b << std::endl;
    std::cout << "kd: " << m.kd_.r << ", " << m.kd_.g << ", " << m.kd_.b << std::endl;
    std::cout << "ks: " << m.ks_.r << ", " << m.ks_.g << ", " << m.ks_.b << std::endl;
    return os;
  }
};

#endif 