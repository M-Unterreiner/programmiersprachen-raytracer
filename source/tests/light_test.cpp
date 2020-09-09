/*
Just a dummy test for testing purposes
*/
#include <catch.hpp>

#include "../../framework/box.hpp"
#include "../../framework/color.hpp"
#include "../../framework/ray.hpp"
#include "../../framework/shape.hpp"
#include "../../framework/sphere.hpp"
#include "../../framework/reader.hpp"


TEST_CASE("Light")
{
  SECTION("Default Constructor")
  {
    Light new_light{};
    REQUIRE(new_light.name_ == "default light");
    REQUIRE(new_light.position_.x == 0);
    REQUIRE(new_light.color_.r == 0.0);
  }

  // define light sun 1000 700 0 .2 .2 .2
}

