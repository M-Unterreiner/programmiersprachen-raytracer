#pragma once
#include <catch.hpp>

#include "../../framework/box.hpp"
#include "../../framework/color.hpp"
#include "../../framework/ray.hpp"
#include "../../framework/shape.hpp"
#include "../../framework/sphere.hpp"
#include "../../framework/reader.hpp"


TEST_CASE ("Shape")
{
  SECTION("Default constructor", "[Default]")
  {
    Shape s1{};
  }
}
