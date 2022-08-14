cmake_minimum_required(VERSION 3.20)
project(MyProject1)

add_subdirectory(../../../../Catch2 Catch2-build)

add_executable(MyProject1Test test-main.cpp doubly_linked_list.cpp)
target_link_libraries(MyProject1Test PRIVATE Catch2::Catch2)