cmake_minimum_required(VERSION 3.16)

project(gravity)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    -lsfml-graphics 
    -lsfml-window 
    -lsfml-system
)