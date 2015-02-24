cmake_minimum_required (VERSION 2.8.3)
project (email-date-repair)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

configure_file (
      "${PROJECT_SOURCE_DIR}/src/config.h.in"
      "${PROJECT_BINARY_DIR}/config.h"
      )

add_definitions(-Wall)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(SRC
  src/main.cpp
  )

# libraries

# end libraries

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

add_executable(email-date-repair ${SRC})
# target_link_libraries(email-date-repair ${FUSE_LIBRARIES})
