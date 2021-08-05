cmake_minimum_required(VERSION 3.1)

project(MotorMC)

# Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
link_directories(/usr/local/lib)
include_directories(/usr/local/include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "-O3 -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g3 -Wall -Wextra")

file(GLOB_RECURSE src
     "src/*.c"
)

link_libraries(tomcrypt tfm yyjson)

if(DEFINED WIN32 OR DEFINED MSYS)
     # LINK CURL
     add_compile_definitions(
          CURL_STATICLIB
          WITH_SSL=STATIC
     )
     link_libraries(-l:libcurl.a advapi32 crypt32 -l:libzstd.a -l:libz.a ws2_32)

     link_libraries(deflatestatic -l:libpthread.a)
else()
     link_libraries(deflate pthread curl)

     if(DEFINED UNIX)
          link_libraries(dl)
     endif()
endif()

add_executable(MotorMC ${src})