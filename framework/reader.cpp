#include <memory>

#include <iostream>
#include <sstream>
#include <fstream>

#include "reader.hpp"
#include "file.hpp"

Reader::Reader():
file_()
{
}

Reader::Reader(std::shared_ptr<File> file):
file_(file)
{
}

Reader::~Reader()
{
}


void Reader::set_file(std::shared_ptr<File> file)
{
  file_ = std::move(file);
}

std::string Reader::get_filename()
{
  return file_->filename_;
}

/*
 read_file reads the file
*/
void Reader::read_file()
{
  std::string example = file_->file_;

  std::ifstream filestream;
  filestream.open(file_->file_);
  std::string buffer;

  while(std::getline(filestream, buffer))
  {
    std::cout << "While" << std::endl;

    std::stringstream stream (buffer);
    std::string keyword;

    stream >> keyword;

    if ("define" == keyword)
    {
      std::cout << "define" << std::endl;

      if ("material" == keyword)
      {
        std::cout << "material" << std::endl;
      }

      if ("shape" == keyword)
      {
        std::cout << "shape" << std::endl;

        if ("box" == keyword)
        {
          std::cout << "box" << std::endl;
        }

        if ("sphere" == keyword)
        {
          std::cout << "sphere" << std::endl;
        }

        if ("composite" == keyword)
        {
          std::cout << "composite" << std::endl;
        }
      }

      if ("camera" == keyword)
      {
        std::cout << "camera" << std::endl;
      }
    }
  }
}

Scene Reader::read_file_to_scene()
{
  std::string example = file_->file_;

  std::ifstream filestream;
  filestream.open(file_->file_);
  std::string buffer;

  while(std::getline(filestream, buffer))
  {
    std::cout << "While" << std::endl;

    std::stringstream stream (buffer);
    std::string keyword;

    stream >> keyword;

    if ("define" == keyword)
    {
      std::cout << "define" << std::endl;
      stream >> keyword;

      if ("material" == keyword)
      {
        void set_material(std::stringstream stream);
      }

      if ("shape" == keyword)
      {
        std::cout << "shape" << std::endl;

        if ("box" == keyword)
        {
          std::cout << "box" << std::endl;
        }

        if ("sphere" == keyword)
        {
          std::cout << "sphere" << std::endl;
        }

        if ("composite" == keyword)
        {
          std::cout << "composite" << std::endl;
        }
      }

      if ("camera" == keyword)
      {
        std::cout << "camera" << std::endl;
      }
    }
  }
}

std::shared_ptr<Material> Reader::set_material(std::stringstream stream)
  {
    auto material_ptr = std::make_shared<Material> ();
    stream >> material_ptr->name_;
    stream >> material_ptr->ka_.r;
    stream >> material_ptr->ka_.g;
    stream >> material_ptr->ka_.b;
    stream >> material_ptr->kd_.r;
    stream >> material_ptr->kd_.g;
    stream >> material_ptr->kd_.b;
    stream >> material_ptr->ks_.r;
    stream >> material_ptr->ks_.g;
    stream >> material_ptr->ks_.b;
  }