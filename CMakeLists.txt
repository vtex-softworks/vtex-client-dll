cmake_minimum_required(VERSION 3.5)

project(version VERSION 1.0.0 LANGUAGES CXX)

# Set the source files for your DLL
set(SOURCES
    src/main.cc
    src/dll_main.cc

    src/hook.cc
    src/proxy.cc
    src/signature_check.cc
    src/trust_check.cc
    src/debug_console.cc
)

include_directories(include)

# Configure the project to build a shared library (DLL)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# stdafx.h
target_precompile_headers(${PROJECT_NAME} PRIVATE "include/stdafx.h")

# Enable threading support
find_package(Threads REQUIRED)

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME} Threads::Threads)