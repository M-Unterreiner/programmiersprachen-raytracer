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
  Scene read_sdf_to_scene();
  std::string get_filename();
  std::shared_ptr<Material> set_material(std::string rest);
  std::shared_ptr<Box> set_box(std::string rest);

  private:
  std::shared_ptr<File> file_to_read_;
  std::ifstream filestream_;
};




#endif // READER_HPP