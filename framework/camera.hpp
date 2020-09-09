#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include <cmath>

struct Camera
{
  std::string name_ = {"Default camera"};
  double fov_ = {45};
  glm::vec3 position_= {0,0,0};
  glm::vec3 direction_; 

  void print_camera()
  {
    std::cout << name_ << std::endl;
    std::cout << "x: " << position_.x << " y: " << position_.y << " z: " << position_.z << std::endl;
    std::cout << fov_  << std::endl;
  }


};


#endif //CAMERA_HPP