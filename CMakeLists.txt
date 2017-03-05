cmake_minimum_required(VERSION 3.6)
project(cpc)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp hash_table/contains_duplicate_2.cpp hash_table/HashTable.h hash_table/contains_duplicate.cpp hash_table/contains_duplicate_3.cpp dynamic_programming/DynamicProgramming.h dynamic_programming/maximal_square.cpp tree/Tree.h tree/count_complete_tree_nodes.cpp math/Math.h math/rectangle_area.cpp stack/Stack.h stack/basic_calculator.cpp design/Design.h design/implement_stack_using_queues.cpp tree/invert_binary_tree.cpp)
add_executable(cpc ${SOURCE_FILES})