cmake_minimum_required(VERSION 3.10)

project(satisfactory_tools)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game/game.cpp

    src/game/entities/handler.cpp
    src/game/entities/production.cpp

    src/game/ui/handler.cpp
)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(external/sdl)
add_subdirectory(external/sdl_image)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/sdl/include
    PUBLIC external/sdl_image
    PUBLIC external/ge
)

target_link_directories(${PROJECT_NAME}
    PUBLIC external/sdl
    PUBLIC external/sdl_image
    PRIVATE external/ge
)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

if (MSVC)
    target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)
else (MSVC)
    target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)
endif (MSVC)