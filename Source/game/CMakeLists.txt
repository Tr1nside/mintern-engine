# Создаем исполняемый файл
add_executable(game_main
    src/game.cpp
)

# Публичные заголовки
target_include_directories(game_main PUBLIC
    include
)

# Линковка с engine
find_package(glfw3)
target_link_libraries(engine glfw)
