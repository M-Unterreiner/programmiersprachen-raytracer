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

/*
https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-1.cpp
*/

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

