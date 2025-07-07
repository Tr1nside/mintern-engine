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

# Рекурсивный поиск всех .cpp и .h файлов
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")
file(GLOB_RECURSE GRAPHICS "src/graphics/*.h")

# Создание таргета с найденными файлами
target_sources(game_main PUBLIC ${SOURCES} ${GRAPHICS})
