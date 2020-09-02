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

  private:
  // File file_;
  // Add smart pointer as a file
  std::shared_ptr<File> file_;
};



#endif // READER_HPP