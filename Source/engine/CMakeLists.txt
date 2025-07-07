# Создаем статическую библиотеку engine
add_library(engine STATIC
    src/core.cpp
    src/graphics/window.cpp
    src/input/input.cpp
)

# Публичные заголовки
target_include_directories(engine PUBLIC
    include
    src/graphics
    src/input
)

# Поиск и линковка GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(engine PUBLIC glfw)  # PRIVATE, если только engine использует GLFW

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")
file(GLOB_RECURSE MODULES "src/graphics/*.h" "src/input/*.h")

# Создание таргета с найденными файлами
target_sources(engine PUBLIC ${SOURCES} ${MODULES})