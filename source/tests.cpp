#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "../framework/color.hpp"
#include "../framework/shape.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


TEST_CASE ("Shape")
{
  SECTION("Default constructor")
  {
    Shape s1{};
  }
}
