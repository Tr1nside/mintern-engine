# Создаем исполняемый файл
add_executable(game_main
    src/game.cpp
)

# Публичные заголовки
target_include_directories(game_main PUBLIC
    include
)

# Линковка engine и GLFW
target_link_libraries(game_main PRIVATE engine)  # Линкуемся с engine
