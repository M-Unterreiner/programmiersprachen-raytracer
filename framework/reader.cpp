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
    std::cout << "File was opened" << std::endl;
    return 0;
  } else 
  {
    std::cout << "Error: Files is not open" << std::endl;
    return 1;
  }

  if (filestream_.fail())
  {
    std::cout << file_to_read_->file_ << "Error: failed to load File" << std::endl;
    return 1;
  } else {
    std::cout << file_to_read_->file_ << " was sucessfully opened" << std::endl;
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
  std::string buffer;
  auto new_scene = std::make_shared<Scene>();

  open_file();

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
          set_sphere(rest, new_scene);
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

std::shared_ptr<Box> Reader::set_box(std::string rest, std::shared_ptr<Scene> scene)
{
  std::string findkey;
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
  stream >> findkey; 

  if(scene)
  {
  box_ptr->material_ = find_material(findkey, (*scene).material_map_);
  ((*scene).shape_vector).push_back(box_ptr);
  }

  (*box_ptr).print_box();

  return box_ptr; 
}

/*
Returns a pointer to a Sphere or added it a scene
*/
std::shared_ptr<Sphere> Reader::set_sphere(std::string rest, std::shared_ptr<Scene> scene)
{
  auto sphere_ptr = std::make_shared<Sphere>();

  std::stringstream stream;
  std::string findkey;
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

  stream >> findkey;
  
  if(scene)
  {
  sphere_ptr->material_ = find_material(findkey, (*scene).material_map_);
  ((*scene).shape_vector).push_back(sphere_ptr);
  }

  sphere_ptr->print_sphere();

  return sphere_ptr;
}


std::shared_ptr<Light> Reader::set_light(std::string rest)
{
  auto light_ptr = std::make_shared<Light>();

  std::stringstream stream;
  stream.str(rest);

  std::string trash; // Ugly!
  stream >> trash; // Ugly way to ignore the keywords define  
  stream >> trash; // Ugly way to ignore the keywords shape  

  std::cout << stream.str() << std::endl;
  // define light sun 1000 700 0 .2 .2 .2
  stream >> (*light_ptr).name_;
  stream >> (*light_ptr).position_.x;
  stream >> (*light_ptr).position_.y;
  stream >> (*light_ptr).position_.z;
  stream >> (*light_ptr).color_.r; 
  stream >> (*light_ptr).color_.g; 
  stream >> (*light_ptr).color_.b; 

  (*light_ptr).print_light();

  return light_ptr;
}

std::shared_ptr<Camera> Reader::set_camera(std::string rest)
{
  // define camera eye 45.0
  auto camera_ptr = std::make_shared<Camera>();

  std::stringstream stream;
  stream.str(rest);

  std::string trash; // Ugly!
  stream >> trash; // Ugly way to ignore the keywords define  
  stream >> trash; // Ugly way to ignore the keywords shape  

  stream >> (*camera_ptr).name_;
  stream >> (*camera_ptr).fov_;
  
  (*camera_ptr).print_camera();
  return camera_ptr;  
}

/*
Search with an iterator trough the material_map
*/
std::shared_ptr<Material> Reader::find_material(std::string findkey, std::map<std::string, std::shared_ptr<Material>> const &material_map)
{
  auto iterator = material_map.find(findkey);

  if (iterator != material_map.end())
  {
    std::cout << "Material " << findkey << " exists." << std::endl;
    return iterator->second;
    //first ist key, second ist value
  }
  else
  {
    std::cout << "Material " << findkey << " could not be found" << std::endl;
    return nullptr;
  }
}
