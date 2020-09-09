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

TEST_CASE("Camera")
{
  SECTION("Default Constructor")
  {
    Camera new_camera{};
    REQUIRE(new_camera.name_ == "Default camera");
    REQUIRE(new_camera.position_.x == 0 );
  }
}
