cmake_minimum_required(VERSION 3.1)

project(MotorMC)

# Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
LINK_DIRECTORIES(/usr/local/lib)
include_directories(/usr/local/include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "-O3 -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g -Wall -Wextra")

file(GLOB_RECURSE src
     "src/*.c"
)

link_libraries(tomcrypt curl tfm pthread yyjson deflate)

if(DEFINED WIN32)
     link_libraries(ws2_32)
elseif(DEFINED UNIX)
     link_libraries(dl)
endif()

add_executable(MotorMC ${src})