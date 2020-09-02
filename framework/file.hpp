#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <sstream>
#include <iostream>
// #include <filesystem>

struct File
{
  std::string filename_;
  std::string filedirectory_;

File():
filename_{"example.sdf"},
filedirectory_{"../../ressources/"}
{
}

File(std::string filename):
filename_(filename),
filedirectory_{"../../ressources/"}
{
  std::cout << "file directory wasn't set. " << filedirectory_ << " was used" << std::endl;
}

File(std::string filename, std::string filedirectory):
filename_(filename),
filedirectory_(filedirectory)
{
}

void print_file()
{
  std::cout << filedirectory_ << filename_ << std::endl;
}

};
#endif // FILE_HPP