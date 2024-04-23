cmake_minimum_required(VERSION 3.5.0)
project(FragmentAssembly VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(FragmentAssembly main.cpp node.h node.cpp graph.h graph.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
