#include <catch.hpp>

#include "../../framework/box.hpp"
#include "../../framework/color.hpp"
#include "../../framework/ray.hpp"
#include "../../framework/shape.hpp"
#include "../../framework/sphere.hpp"
#include "../../framework/reader.hpp"

TEST_CASE ("File")
{
  SECTION("Default constructor")
  {
    File file{};
    file.print_file();
  }
  SECTION("Default constructor with smart pointer")
  {
    auto file = std::make_shared<File>();
    file->print_file();
  }
}