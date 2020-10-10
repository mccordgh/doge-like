cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(doge-like VERSION 0.1.0)

# LINUX
# SET(COVERAGE_COMPILE_FLAGS "-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -std=c++11")
# SET(COVERAGE_LINK_FLAGS "-L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image")

# MAC
SET(COVERAGE_COMPILE_FLAGS "-I/usr/local/opt/readline/include -I/usr/local/include -D_THREAD_SAFE -std=c++11 -Wall -Wextra -pedantic")
SET(COVERAGE_LINK_FLAGS "-L/usr/local/opt/readline/lib -L/usr/local/lib -lSDL2 -lSDL2_image")

add_compile_options("-v")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_LINK_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/src/ECS)

add_executable(doge-like    src/main.cpp
                            src/AssetManager.cpp
                            src/Collision.cpp
                            src/Game.cpp
                            src/GameObject.cpp
                            src/Map.cpp
                            src/TextureManager.cpp
                            src/Vector2D.cpp
                            src/ECS/ECS.cpp)

target_link_libraries(doge-like ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
