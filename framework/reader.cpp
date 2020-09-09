#include <memory>

#include <iostream>
#include <sstream>
#include <fstream>

#include "reader.hpp"
#include "file.hpp"

Reader::Reader():
file_to_read_{}
{
}

Reader::Reader(std::shared_ptr<File> file):
file_to_read_{file}
{
}

Reader::~Reader()
{
}


void Reader::set_file(std::shared_ptr<File> file)
{
  file_to_read_ = std::move(file);
}

std::string Reader::get_filename()
{
  return file_to_read_->filename_;
}

/*
  Tries to open file, if it failes it will return 1, if succeeded 0 
*/
bool Reader::open_file()
{
  std::cout << "### Try to open file ###" << std::endl;
  std::cout << file_to_read_->file_ << std::endl;

  filestream_.open(file_to_read_->file_);
  if (filestream_.is_open())
  {
    std::cout << "File is open" << std::endl;
    return 0;
  } else 
  {
    std::cout << "Files is not open" << std::endl;
    return 1;
  }

  if (filestream_.fail())
  {
    std::cout << file_to_read_->file_ << " failed to load" << std::endl;
    return 1;
  } else {
    std::cout << file_to_read_->file_ << " was sucessfull opened" << std::endl;
    return 0;
  }
}

/*
Closes the file, not necessary
*/
void Reader::close_file()
{
  filestream_.close();
}


/*
 read_file reads the file
*/
void Reader::read_file()
{

  if (!open_file()) 
  {
    std::string buffer;

    while(std::getline(filestream_, buffer))
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
      } // if keyword define
    } // while
    close_file();
  } // if opened  
}

/*
 Reads a sdf to scene
 TODO: Somehow the file could not be readed. 
*/
std::shared_ptr<Scene> Reader::read_sdf_to_scene()
{
  open_file();
  std::string buffer;
  auto new_scene = std::make_shared<Scene>();

  while(std::getline(filestream_, buffer))
  {
    std::stringstream stream (buffer); 
    std::string keyword;

    stream >> keyword;
    
    if ("define" == keyword)
    {
      stream >> keyword;

      if ("material" == keyword)
      {
        std::string rest;
        rest = stream.str();
        set_material(rest);
      }

      if ("shape" == keyword)
      {
        stream >> keyword;
        if ("box" == keyword)
        {
          std::string rest;

          rest = stream.str();
          set_box(rest);
        }

        if ("sphere" == keyword)
        {
          std::string rest;
          rest = stream.str();
          set_sphere(rest);
        }

        if ("composite" == keyword)
        {
          std::string rest;
          rest = stream.str();
          // set_composite(rest);

        }
      }
      if ("camera" == keyword)
      {
        std::string rest;
        rest = stream.str();
        // set_camera(rest);
      }
    }
  }
  close_file();

  return new_scene;
}

std::shared_ptr<Material> Reader::set_material(std::string rest)
  {
    
    auto material_ptr = std::make_shared<Material> ();
    std::stringstream stream;
    stream.str(rest);
    std::cout << stream.str() << std::endl;

    std::string trash; // Ugly!
    stream >> trash; // Ugly way to ignore the keywords define and material 
    stream >> trash; // Ugly way to ignore the keywords define and material 

    std::cout << stream.str() << std::endl;
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

    std::cout << *material_ptr << std::endl;

    return material_ptr;
  }

std::shared_ptr<Box> Reader::set_box(std::string rest)
{
  auto box_ptr = std::make_shared<Box>();

  std::stringstream stream;
  stream.str(rest);
  std::string trash; // Ugly!
  stream >> trash; // Ugly way to ignore the keywords define  
  stream >> trash; // Ugly way to ignore the keywords shape  
  stream >> trash; // Ugly way to ignore the keywords box  

  std::cout << stream.str() << std::endl;
  stream >> (*box_ptr).name_;
  stream >> (*box_ptr).min_.x;
  stream >> (*box_ptr).min_.y;
  stream >> (*box_ptr).min_.z;
  stream >> (*box_ptr).max_.x;
  stream >> (*box_ptr).max_.y;
  stream >> (*box_ptr).max_.z;

  // stream >> box_ptr->material;

  // How to set the material?

  (*box_ptr).print_box();

  return box_ptr; 
}


std::shared_ptr<Sphere> Reader::set_sphere(std::string rest)
{
  auto sphere_ptr = std::make_shared<Sphere>();

  std::stringstream stream;
  stream.str(rest);

  std::string trash; // Ugly!
  stream >> trash; // Ugly way to ignore the keywords define  
  stream >> trash; // Ugly way to ignore the keywords shape  
  stream >> trash; // Ugly way to ignore the keywords box  


  std::cout << stream.str() << std::endl;
  stream >> (*sphere_ptr).name_;
  stream >> (*sphere_ptr).center_.x;
  stream >> (*sphere_ptr).center_.y;
  stream >> (*sphere_ptr).center_.z;

  stream >> (*sphere_ptr).radius_;

  // stream >> box_ptr->material;

  sphere_ptr->print_sphere();

  return sphere_ptr;
}