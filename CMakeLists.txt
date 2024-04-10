cmake_minimum_required(VERSION 3.27)
project(ecosystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(ecosystem main.cpp
        inc/Zombie.h
        inc/Human.h
        inc/GameSpecs.h
        src/Organism.cpp
        src/City.cpp
        src/Human.cpp
        src/Zombie.cpp
        src/EmptySpace.cpp
        inc/EmptySpace.h
)
