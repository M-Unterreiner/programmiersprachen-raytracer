#ifndef READER_HPP
#define READER_HPP

#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include "file.hpp"

class Reader
{
  public:  

  Reader();
  Reader(std::shared_ptr<File> filename);
  ~Reader();
  void set_File(std::shared_ptr<File> filename);
  void read_File();
  std::string get_filename();


  private:
  std::shared_ptr<File> file_;
};




#endif // READER_HPP