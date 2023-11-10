cmake_minimum_required ( VERSION 3.1.0...3.27.0 )

project ( RTWeekend LANGUAGES CXX )

# Set to C++11
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )

# OpenMP package
FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
message("OPENMP FOUND")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Source

set ( EXTERNAL
  external/stb_image.h
)

set ( SOURCE_ONE_WEEKEND
  external/stb_image.h

  InOneWeekend/camera.h
  InOneWeekend/color.h
  InOneWeekend/hittable.h
  InOneWeekend/hittable_list.h
  InOneWeekend/interval.h
  InOneWeekend/material.h
  InOneWeekend/ray.h
#   InOneWeekend/rtw_stb_image.h
  InOneWeekend/rtweekend.h
  InOneWeekend/sphere.h
  InOneWeekend/vec3.h

  InOneWeekend/main.cpp
)

set ( SOURCE_NEXT_WEEK
  external/stb_image.h

  TheNextWeek/aabb.h
  TheNextWeek/bvh.h
  TheNextWeek/camera.h
  TheNextWeek/color.h
  TheNextWeek/constant_medium.h
  TheNextWeek/hittable.h
  TheNextWeek/hittable_list.h
  TheNextWeek/interval.h
  TheNextWeek/material.h
  TheNextWeek/perlin.h
  TheNextWeek/quad.h
  TheNextWeek/ray.h
  TheNextWeek/rtw_stb_image.h
  TheNextWeek/rtweekend.h
  TheNextWeek/sphere.h
  TheNextWeek/texture.h
  TheNextWeek/vec3.h

  TheNextWeek/main.cpp
)

set ( SOURCE_REST_OF_YOUR_LIFE
  external/stb_image.h

  TheRestOfYourLife/aabb.h
  TheRestOfYourLife/camera.h
  TheRestOfYourLife/color.h
  TheRestOfYourLife/constant_medium.h
  TheRestOfYourLife/hittable.h
  TheRestOfYourLife/hittable_list.h
  TheRestOfYourLife/interval.h
  TheRestOfYourLife/material.h
  TheRestOfYourLife/onb.h
  TheRestOfYourLife/pdf.h
  TheRestOfYourLife/perlin.h
  TheRestOfYourLife/quad.h
  TheRestOfYourLife/ray.h
  TheRestOfYourLife/rtw_stb_image.h
  TheRestOfYourLife/rtweekend.h
  TheRestOfYourLife/sphere.h
  TheRestOfYourLife/texture.h
  TheRestOfYourLife/vec3.h

  TheRestOfYourLife/main.cpp
)

# include_directories(src)

# Specific compiler flags below. We're not going to add options for all possible compilers, but if
# you're new to CMake (like we are), the following may be a helpful example if you're using a
# different compiler or want to set different compiler options.

message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPILER_ID})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/we 4265") # Class has virtual functions, but its non-trivial destructor is not virtual
    add_compile_options("/w3 5038") # Data member will be initialized after [other] data member
    add_compile_options("/we 5204") # Class has virtual functions, but its trivial destructor is not virtual
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wnon-virtual-dtor) # Class has virtual functions, but its destructor is not virtual
    add_compile_options(-Wreorder) # Data member will be initialized after [other] data member
    add_compile_options(-Wmaybe-uninitialized) # Variable improperly initialized
    add_compile_options(-Wunused-variable) # Variable is defined but unused
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wnon-virtual-dtor) # Class has virtual functions, but its destructor is not virtual
    add_compile_options(-Wreorder) # Data member will be initialized after [other] data member
    add_compile_options(-Wsometimes-uninitialized) # Variable improperly initialized
    add_compile_options(-Wunused-variable) # Variable is defined but unused
endif()

# Executables
add_executable(inOneWeekend      ${EXTERNAL} ${SOURCE_ONE_WEEKEND})
add_executable(theNextWeek       ${EXTERNAL} ${SOURCE_NEXT_WEEK})
add_executable(theRestOfYourLife ${EXTERNAL} ${SOURCE_REST_OF_YOUR_LIFE})
add_executable(cos_cubed         TheRestOfYourLife/cos_cubed.cpp         )
add_executable(cos_density       TheRestOfYourLife/cos_density.cpp       )
add_executable(integrate_x_sq    TheRestOfYourLife/integrate_x_sq.cpp    )
add_executable(pi                TheRestOfYourLife/pi.cpp                )
add_executable(estimate_halfway  TheRestOfYourLife/estimate_halfway.cpp  )
add_executable(sphere_importance TheRestOfYourLife/sphere_importance.cpp )
add_executable(sphere_plot       TheRestOfYourLife/sphere_plot.cpp       )