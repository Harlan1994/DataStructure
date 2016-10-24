cmake_minimum_required(VERSION 3.6)
project(DataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SqList/SqList.h LinkedList/LinkedList.h LinkedList/LinkedListTest.cpp DLinkedList/DLinkedList.h)
add_executable(DataStructure ${SOURCE_FILES})