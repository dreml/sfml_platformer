cmake_minimum_required(VERSION 3.28)

project(sfml_platformer)

# Генерация compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


# Ассеты
set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)
file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_BINARY_DIR})

# Добавляем директорию с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR}/include)

# Явно указываем все исходные файлы
set(SOURCES
    src/main.cpp
		src/game/Game.cpp
		src/game/Player.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
# Создаем исполняемый файл
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)
