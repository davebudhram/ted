# Minimum version of CMake required
cmake_minimum_required(VERSION 3.16)

# Project name and version
project(TED VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Main Application (add source files for your main executable)
add_executable(TED src/main.cpp src/GapBuffer.cpp src/Controller.cpp src/TextEditor.cpp)


#***************************************************************************************************
#                                     SFML STUFF
#***************************************************************************************************
# Find SFML (if installed globally)
# Specify paths to SFML include and library directories
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")

# Include the SFML headers
include_directories(${SFML_INCLUDE_DIR})

# Link SFML libraries
find_library(SFML_GRAPHICS sfml-graphics PATHS ${SFML_LIBRARY_DIR})
find_library(SFML_WINDOW sfml-window PATHS ${SFML_LIBRARY_DIR})
find_library(SFML_SYSTEM sfml-system PATHS ${SFML_LIBRARY_DIR})

target_link_libraries(TED ${SFML_GRAPHICS} ${SFML_WINDOW} ${SFML_SYSTEM})

#***************************************************************************************************
#                                     TESTING STUFF
#***************************************************************************************************

# Fetch Catch2 automatically using FetchContent
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # Use an appropriate version of Catch2
)

# Ensure FetchContent is processed
FetchContent_MakeAvailable(Catch2)

# Add the test executable
add_executable(tests tests/test.cpp src/GapBuffer.cpp)

# Link Catch2 to the test executable
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)



