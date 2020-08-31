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
  SECTION("Default constructor", "[Default]")
  {
    Shape s1{};
  }
}

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

TEST_CASE ("Box")
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
