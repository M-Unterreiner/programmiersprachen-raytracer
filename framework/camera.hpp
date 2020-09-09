#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include <cmath>

struct Camera
{
  std::string name_;
  double fov_;
  glm::vec3 position_;
  glm::vec3 direction_; 

  void print_camera()
  {
    std::cout << name_ << std::endl;
    std::cout << fov_  << std::endl;
  }


};


#endif //CAMERA_HPP