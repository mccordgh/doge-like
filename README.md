#C++ Game with SDL2

##Notes to self:
###When changing platforms change these vscode settings:
  - In CmakeLists.txt uncomment current platform (Mac, Linux, Windows), comment out other platforms.
  - Bottom Right of VSCode change the C/C++ Configuration to match your platform (Mac, Linux, Windows)

###Compiling:
  - VSCode Cmake Tools extension.
    - Set your Kit to:
      - Mac: ~Clang 11.0.3
      - Linux: GCC9
      - Windows: Not setup yet
    - Click "Build"
    - Click the Play button

###Dependencies:
  Linux:
    - install sdl2 and sdl2_image

  Mac:
    - install sdl2 and sdl2_image (i used brew)

  Windows:
    - install MinGW to C:\MinGW
    - extract sdl2 and sdl2_image files to c:\mingw_dev_lib\

##vcpkg stuff:

CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=C:/Users/mattm/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"

The package sdl2:x86-windows provides CMake targets:

    find_package(SDL2 CONFIG REQUIRED)
    target_link_libraries(main PRIVATE SDL2::SDL2 SDL2::SDL2main)

The package sdl2-gfx:x86-windows provides CMake targets:

    find_package(sdl2-gfx CONFIG REQUIRED)
    target_link_libraries(main PRIVATE SDL2::SDL2_gfx)

The package sdl2-image:x86-windows provides CMake targets:

    find_package(sdl2-image CONFIG REQUIRED)
    target_link_libraries(main PRIVATE SDL2::SDL2_image)

The package sdl2-mixer:x86-windows provides CMake targets:

    find_package(sdl2-mixer CONFIG REQUIRED)
    target_link_libraries(main PRIVATE SDL2::SDL2_mixer)

The package sdl2-net:x86-windows provides CMake targets:

    find_package(sdl2-net CONFIG REQUIRED)
    target_link_libraries(main PRIVATE SDL2::SDL2_net)

The package sdl2-ttf:x86-windows provides CMake targets:

    find_package(sdl2-ttf CONFIG REQUIRED)
    target_link_libraries(main PRIVATE SDL2::SDL2_ttf)

