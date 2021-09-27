cmake_minimum_required ( VERSION 3.1.0 )

project ( RTWeekend
  VERSION 3.0.0
  LANGUAGES CXX
)

# Set to c++11
set ( CMAKE_CXX_STANDARD 11 )

# Source
set ( COMMON_ALL
  rtweekend.h
  camera.h
  ray.h
  vec3.h
)

set ( SOURCE_ONE_WEEKEND
  ${COMMON_ALL}
  hittable.h
  hittable_list.h
  material.h
  sphere.h
  main.cpp
)


# Executables
add_executable(inOneWeekend      ${SOURCE_ONE_WEEKEND})