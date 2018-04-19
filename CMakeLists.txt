cmake_minimum_required(VERSION 3.5)
project(FinalTest)

set(CMAKE_CXX_STANDARD 11)

FILE(GLOB sources ./*.cpp ./*.h  */*.cpp */*.h */*/*.cpp */*/*.h)

include_directories(. Triangle Triangle/Utils TriangleTest MainTest)
add_executable(FinalTest ${sources})

