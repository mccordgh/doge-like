#C++ Game with SDL2

##Notes to self:
###When changing platforms change these vscode settings:
  - In CmakeLists.txt uncomment current platform (Mac, Linux, Windows), comment out other platforms.
  - Bottom Right of VSCode change the C/C++ Configuration to match your platform (Mac, Linux, Windows)

###Compiling: aka how I got this to compile for the first time on each OS and this might be outdated by now who knows :)
  - VSCode Cmake Tools extension.
    - Set your Kit to:
      - Mac: Clang 11.0.3
      - Linux: GCC9
      - Windows: Visual Studio Community 2019 Release - amd64
    - Click "Build"
    - Click the Play button

  Linux:
    - install sdl2 and sdl2_image (sudo apt install ...)
    - open project folder in vscode
    - Make sure C++ and CMake Tools extensions are installed
    - Set CMake Tools Kit to GCC9
    - Cross fingers, Build, & Play  

  Mac:
    - install sdl2 and sdl2_image (i used brew)
    - open project folder in vscode
    - Make sure C++ and CMake Tools extensions are installed
    - Set CMake Tools Kit to Clang ~11.0.3
    - Cross fingers, Build, & Play  

  Windows: (The windows is kind of a frankenstein but I _believe_ that vcpkg is handling libraries so)
    - Install vcpkg following these instructions: https://docs.microsoft.com/en-us/cpp/build/vcpkg?view=vs-2019
    - Run vcpkg integrate install
    - Install sdl2:x64-windows, sdl2-image:x64-windows, sdl2-gfx:x64-windows, sdl2-mixer:x64-windows, sdl2-net:x64-windows, sdl2-ttf:x64-windows
    - open project folder in vscode
    - Set Kit to Visual Studio Community 2019 Release - amd64
    - Cross fingers, Build, & Play  

##vcpkg stuff on Windows (should be already setup):

CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=C:/Users/mattm/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"
