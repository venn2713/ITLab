cmake_minimum_required(VERSION 3.10)
project(PrimeNumberAlgorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(PrimeNumberAlgorithms main.cpp BruteForce.cpp Fermat.cpp RabinMiller.cpp Utility.cpp)


target_link_libraries(PrimeNumberAlgorithms)
