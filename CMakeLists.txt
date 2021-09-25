cmake_minimum_required(VERSION 3.10)

project(satisfactory_tools)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game/ui/handler.cpp
    src/game/entities/handler.cpp
    src/game/game.cpp
)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} 
            submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}")
        endif()
    endif()
endif()

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