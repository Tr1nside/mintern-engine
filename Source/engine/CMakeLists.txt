# Поиск файлов
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.h")
set(ALL_FILES ${SOURCES} ${HEADERS})

# Создаем статическую библиотеку engine
add_library(engine STATIC ${ALL_FILES})

# Публичные заголовки
target_include_directories(engine PUBLIC
    include
    src/graphics
    src/input
    src/math
    src/utils
)

# Поиск и линковка GLFW
find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)
target_link_libraries(engine PUBLIC GLEW::GLEW glfw)  # PRIVATE, если только engine использует GLFW

# Создание таргета с найденными файлами
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
