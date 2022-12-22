# specify minimum required cmake version
cmake_minimum_required(VERSION 3.0)

# specify project name
project(Physics_Sim VERSION 1.0)

#set c++ to 17
set(CMAKE_CXX_STANDARD 17)

#add executables
add_executable(Physics_Sim driver.cpp
                            Ball.cpp
                            Container.cpp
                            VectorMath.cpp)

target_include_directories(Physics_Sim PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
                           
#add SFML library
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Physics_Sim sfml-graphics sfml-audio)

#add openmp library
find_package(OpenMP REQUIRED)
target_link_libraries(Physics_Sim OpenMP::OpenMP_CXX)

