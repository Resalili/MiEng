cmake_minimum_required(VERSION 3.16)
project(Renderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пошук GLFW і GLEW через pkg-config
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

# Include directories
include_directories(
    ${GLFW_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/local/include
)

# Library directories
link_directories(
    ${GLFW_LIBRARY_DIRS}
    ${GLEW_LIBRARY_DIRS}
    /usr/local/lib
)

# 🔹 Ось тут — обов’язково без пропусків і лапок
add_executable(Renderer
    main.cpp
    Renderer.cpp
)

# Framework і бібліотеки
target_link_libraries(Renderer
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
    "-framework OpenGL"
)
