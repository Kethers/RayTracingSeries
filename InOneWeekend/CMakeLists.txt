cmake_minimum_required ( VERSION 3.1.0 )

project ( RTWeekend
  VERSION 3.0.0
  LANGUAGES CXX
)

# Set to c++11
set ( CMAKE_CXX_STANDARD 11 )

FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
message("OPENMP FOUND")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Source
set ( COMMON_ALL
  rtweekend.h
  camera.h
  ray.h
  vec3.h
  interval.h
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

