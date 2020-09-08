#include <catch.hpp>

#include "../../framework/box.hpp"
#include "../../framework/color.hpp"
#include "../../framework/ray.hpp"
#include "../../framework/shape.hpp"
#include "../../framework/sphere.hpp"
#include "../../framework/reader.hpp"

TEST_CASE ("Sphere")
{
  SECTION("Default constructor", "[Default]")
  {
    Sphere s1{};
  }

  SECTION("Constructor")
  {
    glm::vec3 center{0.0f};
    double radius = 5.0;
    std::string name = "Sphere";
    std::shared_ptr<Material> material {};
    Sphere s2{center, radius, name, material};
  }
}