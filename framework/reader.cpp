#include <memory>

#include <iostream>
#include <sstream>
#include <fstream>

#include "reader.hpp"
#include "file.hpp"

Reader::Reader():
file_to_read_()
{
}

Reader::Reader(std::shared_ptr<File> file):
file_to_read_(file)
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
Scene Reader::read_sdf_to_scene()
{
  open_file();
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
      stream >> keyword;

      if ("material" == keyword)
      {
        std::cout << "material" << std::endl;
        // std::string rest;
        // stream.str(rest);
        // set_material(rest);
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
  close_file();
}

std::shared_ptr<Material> Reader::set_material(std::string rest)
  {
    auto material_ptr = std::make_shared<Material> ();
    std::stringstream stream;
    stream.str(rest);
    stream >> material_ptr->ka_.r;
    stream >> material_ptr->ka_.g;
    stream >> material_ptr->ka_.r;
    
    stream >> material_ptr->kd_.r;
    stream >> material_ptr->kd_.g;
    stream >> material_ptr->kd_.r;

    stream >> material_ptr->ks_.r;
    stream >> material_ptr->ks_.g;
    stream >> material_ptr->ks_.r;

    return material_ptr;
  }