#include <catch.hpp>

#include "../../framework/box.hpp"
#include "../../framework/color.hpp"
#include "../../framework/ray.hpp"
#include "../../framework/shape.hpp"
#include "../../framework/sphere.hpp"
#include "../../framework/reader.hpp"

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