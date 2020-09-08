#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include <cmath>

struct Camera
{
  std::string name_;
  glm::vec3 position_;
  glm::vec3 direction_; 

};


#endif //CAMERA_HPP