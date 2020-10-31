cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(doge-like VERSION 0.1.0)

# UNIX AND NOT APPLE = LINUX :)
if(UNIX AND NOT APPLE)
  SET(COVERAGE_COMPILE_FLAGS "-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -std=c++11 -Wall -Wextra -pedantic")
  SET(COVERAGE_LINK_FLAGS "-L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image")
elseif(APPLE)
  SET(COVERAGE_COMPILE_FLAGS "-I/usr/local/opt/readline/include -I/usr/local/include -D_THREAD_SAFE -std=c++11 -Wall -Wextra -pedantic")
  SET(COVERAGE_LINK_FLAGS "-L/usr/local/opt/readline/lib -L/usr/local/lib -lSDL2 -lSDL2_image")
elseif(WIN32)
  SET(COVERAGE_COMPILE_FLAGS "-std=c++17 -Wall -pedantic")
endif()

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_LINK_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if(UNIX AND NOT APPLE)
  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
elseif(APPLE)
  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
elseif(WIN32)
  find_package(SDL2 CONFIG REQUIRED)
  find_package(sdl2-image CONFIG REQUIRED)
endif()

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/src/ECS
  ${PROJECT_SOURCE_DIR}/src/entities
  ${PROJECT_SOURCE_DIR}/src/gfx
  ${PROJECT_SOURCE_DIR}/src/states
  ${PROJECT_SOURCE_DIR}/src/utils
  ${PROJECT_SOURCE_DIR}/src/worlds
)

add_executable(doge-like    src/main.cpp
                            src/Game.cpp
                            src/ECS/ECS.cpp
                            src/entities/GameObject.cpp
                            src/gfx/AssetManager.cpp
                            src/gfx/TextureManager.cpp
                            src/states/GameState.cpp
                            src/states/StateManager.cpp
                            src/utils/Collision.cpp
                            src/utils/Map.cpp
                            src/utils/Vector2D.cpp
                            src/worlds/World.cpp
)

if(UNIX AND NOT APPLE)
  target_link_libraries(doge-like ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
elseif(APPLE)
  target_link_libraries(doge-like ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
elseif(WIN32)
  target_link_libraries(doge-like PRIVATE SDL2::SDL2 SDL2::SDL2main)
  target_link_libraries(doge-like PRIVATE SDL2::SDL2_image)
endif()

if(UNIX AND NOT APPLE)
  file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
elseif(APPLE)
  file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
elseif(WIN32)
  file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/Debug)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
