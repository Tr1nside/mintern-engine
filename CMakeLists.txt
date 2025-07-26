cmake_minimum_required(VERSION 3.35)
project(Mintern VERSION 1.0.0 LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Для совместимости с Clang/GCC


# Добавление подпроектов
add_subdirectory(Source/engine)
add_subdirectory(Source/game)
