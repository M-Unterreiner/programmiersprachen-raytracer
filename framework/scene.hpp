#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <set>

#include "color.hpp"
#include "material.hpp"
#include "shape.hpp"
#include "sphere.hpp"

struct Scene
{
  std::string name_ = "empty scene";
  
  std::map<std::string, std::shared_ptr<Material>> material_map_;
  std::vector<std::shared_ptr<Shape>> shape_vector;

};


#endif //SCENE_HPP