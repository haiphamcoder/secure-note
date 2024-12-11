cmake_minimum_required(VERSION 3.10)
project(SecureNote)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/usr/include/x86_64-linux-gnu/qt5")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(src)
add_subdirectory(lib)
# add_subdirectory(tests)
add_subdirectory(ui)

