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
  std::string file_;

File():
filename_{"example.sdf"},
filedirectory_{"/home/martin/tmp/ressources/"},
file_{filedirectory_ + filename_}
{
  std::cout << "filename and directory wasn't set. " << file_ << " was used" << std::endl;
}

// TODO: If file doesn't exist it should use a fallback solution
File(std::string filename):
filename_(filename),
filedirectory_{"/home/martin/tmp/ressources/"}
{
  file_ = filedirectory_ + filename_;
  std::cout << "file directory wasn't set. " << file_ << " was used" << std::endl;
}

File(std::string filename, std::string filedirectory):
filename_(filename),
filedirectory_(filedirectory)
{
  file_ = filedirectory_ + filename_;
  std::cout << "file was set to " << file_ << std::endl;
}

void print_file()
{
  std::cout << filedirectory_ << filename_ << std::endl;
}

};
#endif // FILE_HPP