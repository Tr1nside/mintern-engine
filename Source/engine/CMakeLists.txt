# Создаем статическую библиотеку engine
add_library(engine STATIC
    src/core.cpp
)

# Публичные заголовки
target_include_directories(engine PUBLIC
    include
    ${GLFW_INCLUDE_DIRS}  # Если GLFW установлен в систему
)

# Поиск и линковка GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(engine PUBLIC glfw)  # PRIVATE, если только engine использует GLFW
