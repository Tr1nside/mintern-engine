# Создаем статическую библиотеку engine
add_library(engine STATIC
    src/core.cpp
)

# Публичные заголовки
target_include_directories(engine PUBLIC
    include
)

# Conan зависимости
find_package(glfw3)
target_link_libraries(engine glfw)

