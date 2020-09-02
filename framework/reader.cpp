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

