cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Array/Array.h Array/Array.cpp LinkedList/LinkedList.h LinkedList/LinkedList.cpp LinkedList/Node.cpp LinkedList/Node.h HeapMax/HeapMax.cpp HeapMax/HeapMax.h Tree/RedBlackTree.cpp Tree/RedBlackTree.h Tree/Colour.cpp Tree/NodeRB.cpp Tree/NodeRB.h)
