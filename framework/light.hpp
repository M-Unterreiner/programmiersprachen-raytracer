#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include <glm/vec3.hpp>
#include "color.hpp"

struct Light
{
  std::string name_ ="default light";
  Color color_ {0.0f, 0.0f, 0.0f};
  glm::vec3 position_ {0,0,0};
  unsigned int brightness_ {0};

  void print_light()
  {
    std::cout << name_ << std::endl;
    std::cout << "x: " << position_.x << " y: "<< position_.y << " z: " << position_.z << std::endl;
    std::cout << "r: " << color_.r << " g: "<< color_.g << " b: " << color_.b << std::endl;
  }

};


#endif // LIGHT_HPP