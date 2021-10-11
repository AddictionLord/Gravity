cmake_minimum_required(VERSION 3.16)

project(gravity)

find_package (Eigen3 REQUIRED)

add_executable(${PROJECT_NAME} 
    main.cpp 
    src/game.cpp 
    src/object.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)


target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${EIGEN_INCLUDE_DIR}
)



target_link_libraries(${PROJECT_NAME} PRIVATE
    -lsfml-graphics 
    -lsfml-window 
    -lsfml-system
    Eigen3::Eigen
)