cmake_minimum_required(VERSION 3.14)

# Project Name
project(Practica2_Tests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- LABORATORY FIXES (WINDOWS/MINGW) ---

# 1. SSL ERROR SOLUTION:
# Disable SSL verification to avoid download failures on university network
set(CMAKE_TLS_VERIFY 0)

# 2. RUNTIME CONFLICT SOLUTION:
# Force GTest to use the same dynamic libraries as MinGW
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# --- GOOGLE TEST CONFIGURATION (Automatic Download) ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# --- AUTOMATIC SOURCE DEFINITION ---

# Search for ALL .cpp files inside the src/ folder
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")

# IMPORTANT: We remove 'main.cpp' from this list to be able to use
# the rest of the code in tests without duplicating the 'main()' function
# (Adjust the path if your main.cpp is elsewhere)
list(FILTER ALL_SOURCES EXCLUDE REGEX "main.cpp$")

# --- MAIN EXECUTABLE (The normal application) ---
add_executable(MiPrograma src/main.cpp ${ALL_SOURCES})

# --- TEST EXECUTABLE (Google Test) ---
enable_testing()

add_executable(MisTests
  tests/test_main.cpp # Your test file
  ${ALL_SOURCES} # All logic WITHOUT the original main.cpp
)

# Includes and Libraries Configuration
target_include_directories(MisTests PRIVATE src)
target_link_libraries(MisTests GTest::gtest_main)

# Integration with VS Code Test Explorer
include(GoogleTest)
gtest_discover_tests(MisTests)
