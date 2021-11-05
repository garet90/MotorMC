cmake_minimum_required(VERSION 3.1)

enable_language(C)

include(TestBigEndian)
test_big_endian(BIG_ENDIAN)

project(MotorMC)

# Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
link_directories(/usr/local/lib)
include_directories(/usr/local/include)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

if(BIG_ENDIAN)
     set(CMAKE_C_FLAGS "-O3 -Wall -Wextra -D__ENDIANNESS__=1")
     set(CMAKE_C_FLAGS_DEBUG "-O0 -g3 -Wall -Wextra -D__ENDIANNESS__=1")
else()
     set(CMAKE_C_FLAGS "-O3 -Wall -Wextra -D__ENDIANNESS__=0")
     set(CMAKE_C_FLAGS_DEBUG "-O0 -g3 -Wall -Wextra -D__ENDIANNESS__=0")
endif()

file(GLOB_RECURSE src
     "src/*.c"
)

link_libraries(m)

if(DEFINED WIN32 OR DEFINED MSYS)
     # LINK CURL
     add_compile_definitions(
          CURL_STATICLIB
          WITH_SSL=STATIC
     )
     link_libraries(-l:libssl.a -l:libcrypto.a -l:libgmp.a -l:libcurl.a advapi32 crypt32 -l:libzstd.a -l:libz.a ws2_32)

     link_libraries(deflatestatic -l:libpthread.a)
else()
     if (DEFINED APPLE)
          # Link OpenSSL and GMP statically
          link_libraries(libssl.a libcrypto.a libgmp.a)
     else()
          # Link OpenSSL and GMP dynamically
          link_libraries(ssl crypto gmp)
     endif()

     link_libraries(deflate pthread curl)

     if(DEFINED UNIX)
          link_libraries(dl)
     endif()
endif()

add_executable(MotorMC ${src})