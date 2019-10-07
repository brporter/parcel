cmake_minimum_required(VERSION 3.10.0)

project (parcel LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(3rdparty/googletest)