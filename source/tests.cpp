#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <iostream>
#include <memory>

#include "../framework/box.hpp"
#include "../framework/color.hpp"
#include "../framework/ray.hpp"
#include "../framework/shape.hpp"
#include "../framework/sphere.hpp"
#include "../framework/reader.hpp"

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

TEST_CASE ("Ray")
{
  Ray ray1{};
}


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

TEST_CASE ("Reader")
{
  SECTION("Default Constructor")
  {
    Reader new_reader;
    
  }
  SECTION("Constructor with only the filename")
  {
    /*
    This test will create a empty file with the  constructor
    */
    auto file = std::make_shared<File>();
    Reader new_reader(file);
  }

  SECTION("Set file")
  {
    std::cout << "#### Set File ####" << std::endl;
    auto file = std::make_shared<File>("simple-scene.sdf");
    Reader new_reader{};
    std::cout << "Set File" << std::endl;
    new_reader.set_file(file);
    REQUIRE((new_reader).get_filename() == "simple-scene.sdf");
    REQUIRE((new_reader).open_file() == 0); // true means it failed
  }
  
  SECTION("Read a file")
  {
    std::cout << "Read file" << std::endl;
    auto file = std::make_shared<File>("example.sdf");
    Reader new_reader{file};
    REQUIRE((new_reader).open_file() == 0); // true means it failed
    new_reader.read_file();
  }

  /*
  With this test I only test a part of the material
  */
  SECTION("set_material")
  {
    std::cout << "set material" << std::endl;
    std::string new_material = "red 1 0 0 0 0 0 0 0 0 10";
    Reader new_reader{};

    auto material_ptr = new_reader.set_material(new_material);

    REQUIRE((*material_ptr).name_ == "red");
    REQUIRE((*material_ptr).ka_.r == 1.0f);
    REQUIRE((*material_ptr).kd_.g == 0.0f);
    REQUIRE((*material_ptr).ks_.b == 0.0f);
  }

  SECTION("set_box")
  {
    std::cout << "set box" << std::endl;
    std::string new_box = "rbottom -100 -80 -200 100 80 -100 red";
    Reader new_reader{};

    auto box_ptr = new_reader.set_box(new_box);

    REQUIRE(box_ptr->name_ == "rbottom");
    REQUIRE(box_ptr->test_min_() == "-100 -80 -200");
    REQUIRE(box_ptr->test_max_() == "100 80 -100");
    //REQUIRE(box_ptr->material_ == "red");
  }

  SECTION("set sphere")
  {
    std::cout << "set sphere" << std::endl;
    std::string new_sphere = "bsphere 0 0 -100 50 blue";
    Reader new_reader{};

    auto sphere_ptr = new_reader.set_sphere(new_sphere);

    REQUIRE(sphere_ptr->name_ == "bsphere");
    REQUIRE(sphere_ptr->get_center_() == "0 0 -100");
    REQUIRE(sphere_ptr->get_radius_() == "50");
    // REQUIRE(sphere_ptr->material_ == "blue");
  }


 // SECTION("Read scene in a file")
 // {
 //   std::cout << "Read file" << std::endl;
 //   auto file = std::make_shared<File>("simple-scene.sdf", "");
 //   Reader new_reader{file};
 //   new_reader.read_sdf_to_scene();
 // }
}