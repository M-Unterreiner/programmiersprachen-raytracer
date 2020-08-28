#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>
#include <color.hpp>

struct Material
{
  std::string name_;
  Color ka_;
  Color kd_;
  Color ks_;
};


#endif 