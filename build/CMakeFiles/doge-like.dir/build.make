# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mccordinator/dev/cpp/games/doge-like

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mccordinator/dev/cpp/games/doge-like/build

# Include any dependencies generated for this target.
include CMakeFiles/doge-like.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/doge-like.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doge-like.dir/flags.make

CMakeFiles/doge-like.dir/src/main.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/doge-like.dir/src/main.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/main.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/main.cpp

CMakeFiles/doge-like.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/main.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/main.cpp > CMakeFiles/doge-like.dir/src/main.cpp.i

CMakeFiles/doge-like.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/main.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/main.cpp -o CMakeFiles/doge-like.dir/src/main.cpp.s

CMakeFiles/doge-like.dir/src/AssetManager.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/AssetManager.cpp.o: ../src/AssetManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/doge-like.dir/src/AssetManager.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/AssetManager.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/AssetManager.cpp

CMakeFiles/doge-like.dir/src/AssetManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/AssetManager.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/AssetManager.cpp > CMakeFiles/doge-like.dir/src/AssetManager.cpp.i

CMakeFiles/doge-like.dir/src/AssetManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/AssetManager.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/AssetManager.cpp -o CMakeFiles/doge-like.dir/src/AssetManager.cpp.s

CMakeFiles/doge-like.dir/src/Collision.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/Collision.cpp.o: ../src/Collision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/doge-like.dir/src/Collision.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/Collision.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/Collision.cpp

CMakeFiles/doge-like.dir/src/Collision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/Collision.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/Collision.cpp > CMakeFiles/doge-like.dir/src/Collision.cpp.i

CMakeFiles/doge-like.dir/src/Collision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/Collision.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/Collision.cpp -o CMakeFiles/doge-like.dir/src/Collision.cpp.s

CMakeFiles/doge-like.dir/src/Game.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/doge-like.dir/src/Game.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/Game.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/Game.cpp

CMakeFiles/doge-like.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/Game.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/Game.cpp > CMakeFiles/doge-like.dir/src/Game.cpp.i

CMakeFiles/doge-like.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/Game.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/Game.cpp -o CMakeFiles/doge-like.dir/src/Game.cpp.s

CMakeFiles/doge-like.dir/src/GameObject.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/GameObject.cpp.o: ../src/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/doge-like.dir/src/GameObject.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/GameObject.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/GameObject.cpp

CMakeFiles/doge-like.dir/src/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/GameObject.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/GameObject.cpp > CMakeFiles/doge-like.dir/src/GameObject.cpp.i

CMakeFiles/doge-like.dir/src/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/GameObject.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/GameObject.cpp -o CMakeFiles/doge-like.dir/src/GameObject.cpp.s

CMakeFiles/doge-like.dir/src/Map.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/Map.cpp.o: ../src/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/doge-like.dir/src/Map.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/Map.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/Map.cpp

CMakeFiles/doge-like.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/Map.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/Map.cpp > CMakeFiles/doge-like.dir/src/Map.cpp.i

CMakeFiles/doge-like.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/Map.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/Map.cpp -o CMakeFiles/doge-like.dir/src/Map.cpp.s

CMakeFiles/doge-like.dir/src/TextureManager.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/TextureManager.cpp.o: ../src/TextureManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/doge-like.dir/src/TextureManager.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/TextureManager.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/TextureManager.cpp

CMakeFiles/doge-like.dir/src/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/TextureManager.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/TextureManager.cpp > CMakeFiles/doge-like.dir/src/TextureManager.cpp.i

CMakeFiles/doge-like.dir/src/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/TextureManager.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/TextureManager.cpp -o CMakeFiles/doge-like.dir/src/TextureManager.cpp.s

CMakeFiles/doge-like.dir/src/Vector2D.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/Vector2D.cpp.o: ../src/Vector2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/doge-like.dir/src/Vector2D.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/Vector2D.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/Vector2D.cpp

CMakeFiles/doge-like.dir/src/Vector2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/Vector2D.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/Vector2D.cpp > CMakeFiles/doge-like.dir/src/Vector2D.cpp.i

CMakeFiles/doge-like.dir/src/Vector2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/Vector2D.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/Vector2D.cpp -o CMakeFiles/doge-like.dir/src/Vector2D.cpp.s

CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.o: CMakeFiles/doge-like.dir/flags.make
CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.o: ../src/ECS/ECS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.o -c /home/mccordinator/dev/cpp/games/doge-like/src/ECS/ECS.cpp

CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mccordinator/dev/cpp/games/doge-like/src/ECS/ECS.cpp > CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.i

CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mccordinator/dev/cpp/games/doge-like/src/ECS/ECS.cpp -o CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.s

# Object files for target doge-like
doge__like_OBJECTS = \
"CMakeFiles/doge-like.dir/src/main.cpp.o" \
"CMakeFiles/doge-like.dir/src/AssetManager.cpp.o" \
"CMakeFiles/doge-like.dir/src/Collision.cpp.o" \
"CMakeFiles/doge-like.dir/src/Game.cpp.o" \
"CMakeFiles/doge-like.dir/src/GameObject.cpp.o" \
"CMakeFiles/doge-like.dir/src/Map.cpp.o" \
"CMakeFiles/doge-like.dir/src/TextureManager.cpp.o" \
"CMakeFiles/doge-like.dir/src/Vector2D.cpp.o" \
"CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.o"

# External object files for target doge-like
doge__like_EXTERNAL_OBJECTS =

doge-like: CMakeFiles/doge-like.dir/src/main.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/AssetManager.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/Collision.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/Game.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/GameObject.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/Map.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/TextureManager.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/Vector2D.cpp.o
doge-like: CMakeFiles/doge-like.dir/src/ECS/ECS.cpp.o
doge-like: CMakeFiles/doge-like.dir/build.make
doge-like: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
doge-like: CMakeFiles/doge-like.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable doge-like"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/doge-like.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doge-like.dir/build: doge-like

.PHONY : CMakeFiles/doge-like.dir/build

CMakeFiles/doge-like.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doge-like.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doge-like.dir/clean

CMakeFiles/doge-like.dir/depend:
	cd /home/mccordinator/dev/cpp/games/doge-like/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mccordinator/dev/cpp/games/doge-like /home/mccordinator/dev/cpp/games/doge-like /home/mccordinator/dev/cpp/games/doge-like/build /home/mccordinator/dev/cpp/games/doge-like/build /home/mccordinator/dev/cpp/games/doge-like/build/CMakeFiles/doge-like.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doge-like.dir/depend

