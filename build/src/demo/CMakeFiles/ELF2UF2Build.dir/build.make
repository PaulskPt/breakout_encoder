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
CMAKE_SOURCE_DIR = /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build

# Utility rule file for ELF2UF2Build.

# Include the progress variables for this target.
include src/demo/CMakeFiles/ELF2UF2Build.dir/progress.make

src/demo/CMakeFiles/ELF2UF2Build: src/demo/CMakeFiles/ELF2UF2Build-complete


src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
src/demo/CMakeFiles/ELF2UF2Build-complete: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/CMakeFiles
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/CMakeFiles/ELF2UF2Build-complete
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-done

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/elf2uf2 && /usr/bin/cmake -E echo_append
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/elf2uf2 && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/pico-sdk/tools/elf2uf2
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/elf2uf2
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/tmp
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E make_directory /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E echo_append
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E echo_append
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E echo_append
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: src/demo/elf2uf2/tmp/ELF2UF2Build-cfgcmd.txt
src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/elf2uf2 && /usr/bin/cmake "-GUnix Makefiles" /mnt/i/pico/pico-sdk/tools/elf2uf2
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/elf2uf2 && /usr/bin/cmake -E touch /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure

src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'ELF2UF2Build'"
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/elf2uf2 && $(MAKE)

ELF2UF2Build: src/demo/CMakeFiles/ELF2UF2Build
ELF2UF2Build: src/demo/CMakeFiles/ELF2UF2Build-complete
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-install
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-mkdir
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-download
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-update
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-patch
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-configure
ELF2UF2Build: src/demo/elf2uf2/src/ELF2UF2Build-stamp/ELF2UF2Build-build
ELF2UF2Build: src/demo/CMakeFiles/ELF2UF2Build.dir/build.make

.PHONY : ELF2UF2Build

# Rule to build all files generated by this target.
src/demo/CMakeFiles/ELF2UF2Build.dir/build: ELF2UF2Build

.PHONY : src/demo/CMakeFiles/ELF2UF2Build.dir/build

src/demo/CMakeFiles/ELF2UF2Build.dir/clean:
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo && $(CMAKE_COMMAND) -P CMakeFiles/ELF2UF2Build.dir/cmake_clean.cmake
.PHONY : src/demo/CMakeFiles/ELF2UF2Build.dir/clean

src/demo/CMakeFiles/ELF2UF2Build.dir/depend:
	cd /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/src/demo /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo /mnt/i/pico/paul_projects/pico/breakout_encoder_cpp_final/build/src/demo/CMakeFiles/ELF2UF2Build.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/demo/CMakeFiles/ELF2UF2Build.dir/depend

