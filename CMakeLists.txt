cmake_minimum_required(VERSION 3.10)
project(PrimeNumberAlgorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(PrimeNumberAlgorithms src/main.cpp src/BruteForce.cpp src/Fermat.cpp src/RabinMiller.cpp)

target_link_libraries(PrimeNumberAlgorithms)