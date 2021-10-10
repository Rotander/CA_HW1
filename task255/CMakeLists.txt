cmake_minimum_required(VERSION 3.16)
project(task255)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        # Headers
        ball.h
        rnd.h
        tetrahedron.h
        parallelepiped.h
        shape.h
        container.h

        # Sources
        ball.cpp
        tetrahedron.cpp
        parallelepiped.cpp
        shape.cpp
        container.cpp
        main.cpp
        )

add_executable(task255 ${SOURCE_FILES})