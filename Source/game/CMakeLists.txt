# Создаем исполняемый файл
add_executable(game_main
    src/game.cpp
    src/game.h
)


# Линковка engine и GLFW
target_link_libraries(game_main PRIVATE engine)  # Линкуемся с engine

target_include_directories(game_main PUBLIC
    src 
)



# Поиск файлов
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
set(ALL_FILES ${SOURCES})

# Создание таргета с найденными файлами
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
