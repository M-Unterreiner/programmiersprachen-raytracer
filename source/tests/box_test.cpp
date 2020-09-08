#pragma once
#include <catch.hpp>

#include "../../framework/box.hpp"
#include "../../framework/color.hpp"
#include "../../framework/ray.hpp"
#include "../../framework/shape.hpp"
#include "../../framework/sphere.hpp"
#include "../../framework/reader.hpp"

TEST_CASE("Box")
{
  SECTION("Default constructor", "[Default]")
  {
    Box b1{};
  }
  SECTION("Constructor")
  {
    glm::vec3 min{0.0f,0.0f,0.0f};
    glm::vec3 max{5.0f,5.0f,5.0f};
    std::string name = "Simple Box";
    std::shared_ptr<Material> material{};
    Box b2{min,max, name, material};
  }
}