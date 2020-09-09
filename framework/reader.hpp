#ifndef READER_HPP
#define READER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <memory>
#include <string>
#include "file.hpp"
#include "scene.hpp"
#include "box.hpp"
#include "light.hpp"
#include "camera.hpp"


class Reader
{
  public:  

  Reader();
  Reader(std::shared_ptr<File> filename);
  ~Reader();
  void set_file(std::shared_ptr<File> filename);
  void read_file();
  bool open_file();
  void close_file();

  std::shared_ptr<Scene> read_sdf_to_scene();
  std::string get_filename();
  std::shared_ptr<Material> set_material(std::string rest);
  std::shared_ptr<Box> set_box(std::string rest, std::shared_ptr<Scene> scene = nullptr);
  std::shared_ptr<Sphere> set_sphere(std::string rest, std::shared_ptr<Scene> scene = nullptr);
  std::shared_ptr<Light> set_light(std::string rest);
  std::shared_ptr<Camera> set_camera(std::string rest);

 
  private : 
  std::shared_ptr<Material> find_material(std::string findkey, std::map<std::string, std::shared_ptr<Material>> const &material_map); 

  std::shared_ptr<File> file_to_read_;
  std::ifstream filestream_;
  };

#endif // READER_HPP