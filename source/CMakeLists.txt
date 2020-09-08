add_executable(example example.cpp)

target_link_libraries(example ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(example glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS example DESTINATION .)

add_executable(raytracer raytracer.cpp)

target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS raytracer DESTINATION .)

# Build tests
add_executable(tests
  tests.cpp
  ../framework/box.cpp
  ../framework/color.hpp
  ../framework/camera.hpp
  ../framework/light.hpp
  ../framework/material.hpp
  ../framework/shape.cpp
  ../framework/sphere.cpp

  # Why isn't file necessary? 
  #../framework/ray.hpp
  ../framework/reader.cpp
  )
  
target_link_libraries(tests
  ${GLFW_LIBRARIES}
  )

