#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "../framework/box.hpp"
#include "../framework/color.hpp"
#include "../framework/shape.hpp"
#include "../framework/sphere.hpp"

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

TEST_CASE ("Sphere")
{
  SECTION("Default constructor")
  {
    Sphere s1{};
  }

}

TEST_CASE ("Box")
{
  SECTION("Default constructor")
  {
    Box b1{};
  }
}