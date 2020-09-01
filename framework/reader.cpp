#include <string>
#include <sstream>
#include <iostream>

#include "reader.hpp"

Reader::Reader():
 filename_("example.sdf"),
 filedirectory_("../../ressources/")
{
  std::cout << "example.sdf was loaded" << std::endl;
}

Reader::Reader(std::string filename):
  filename_(filename),
  filedirectory_("../../ressources/")
{
  std::cout << filename_ <<  " was loaded" << std::endl;
}

Reader::~Reader()
{
}