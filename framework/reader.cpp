#include <memory>

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


void Reader::set_File(std::shared_ptr<File> file)
{
  file_ = std::move(file);
}

std::string Reader::get_filename()
{
  return file_->filename_;
}
