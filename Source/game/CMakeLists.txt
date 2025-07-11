# Создаем исполняемый файл
add_executable(game_main
    src/game.cpp
    include/game.h
)

# Публичные заголовки
target_include_directories(game_main PUBLIC
    include
)

# Линковка engine и GLFW
target_link_libraries(game_main PRIVATE engine)  # Линкуемся с engine

# Поиск файлов
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.h")
set(ALL_FILES ${SOURCES} ${HEADERS})

# Создание таргета с найденными файлами
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
