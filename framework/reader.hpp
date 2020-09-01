#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <sstream>
#include <iostream>

class Reader
{
  public:  

  Reader();
  Reader(std::string filename);
  ~Reader();

  private:

  std::string filename_;
  std::string filedirectory_;
};



#endif // READER_HPP