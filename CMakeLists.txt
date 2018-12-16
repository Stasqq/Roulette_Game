cmake_minimum_required(VERSION 3.12)
project(roulette_proi_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(roulette_proi_v2 main.cpp CyclicList.h Component.cpp Component.h Roulette.cpp Roulette.h)