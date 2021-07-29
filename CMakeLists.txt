cmake_minimum_required(VERSION 3.16)
project(TemplateBinaryTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(TemplateBinaryTree main.cpp BinaryTree_Node.cpp BinaryTree_Node.h BinaryTree.cpp BinaryTree.h Node.h)