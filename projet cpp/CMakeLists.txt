cmake_minimum_required(VERSION 3.10)

project(NomDeVotreProjet)

set(CMAKE_CXX_STANDARD 11)


add_executable(simulation main.cpp Problem.cpp Equation.cpp UniformMesh.cpp variable.cpp Upwind.cpp)


enable_testing()


add_test(structure_test simulation)
add_test(UnitaryTest tests)

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(tests UnitaryTest.cpp Equation.cpp Problem.cpp UniformMesh.cpp main.cpp variable.cpp Upwind.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)


gtest_discover_tests(tests)

