cmake_minimum_required(VERSION 3.8)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "C:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake" CACHE PATH "toolchain file")
endif()

project(newbie)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Assimp REQUIRED)
find_package(SOIL CONFIG REQUIRED)

add_subdirectory(Core)
add_subdirectory(Engine)
add_subdirectory(Custom)
add_subdirectory(Editor)
add_subdirectory(App)

add_dependencies(Engine Core)
add_dependencies(Custom Engine)
add_dependencies(Editor Custom)
add_dependencies(App Custom)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Editor)