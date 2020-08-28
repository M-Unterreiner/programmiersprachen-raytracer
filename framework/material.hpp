#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>
#include <color.hpp>

struct Material
{
  std::string name_;
  Color ka_{1.0f, 0.0f, 0.0f};
  Color kd_{1.0f, 0.0f, 0.0f};
  Color ks_{1.0f, 0.0f, 0.0f};
};


#endif 