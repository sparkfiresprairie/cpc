cmake_minimum_required(VERSION 3.6)
project(cpc)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp hash_table/contains_duplicate_2.cpp hash_table/HashTable.h hash_table/contains_duplicate.cpp hash_table/contains_duplicate_3.cpp dynamic_programming/DynamicProgramming.h dynamic_programming/maximal_square.cpp tree/Tree.h tree/count_complete_tree_nodes.cpp math/Math.h math/rectangle_area.cpp stack/Stack.h stack/basic_calculator.cpp design/Design.h design/implement_stack_using_queues.cpp tree/invert_binary_tree.cpp stack/basic_calculator_2.cpp array/Array.h array/summary_ranges.cpp array/majority_element_2.cpp tree/kth_smallest_element_in_a_bst.cpp math/power_of_two.cpp math/power_of_three.cpp math/power_of_four.cpp design/implement_queue_using_stacks.cpp linked_list/LinkedList.h linked_list/palindrome_linked_list.cpp tree/lowest_common_ancestor_of_a_binary_search_tree.cpp tree/lowest_common_ancestor_of_a_binary_tree.cpp array/product_of_array_except_self.cpp array/sliding_window_maximum.cpp binary_search/BinarySearch.h binary_search/search_a_2d_matrix_2.cpp divide_and_conquer/DivideAndConquer.h)
add_executable(cpc ${SOURCE_FILES})