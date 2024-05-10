cmake_minimum_required(VERSION 3.12)
project(ULibTest)

# Add unity double suport
add_compile_definitions(UNITY_INCLUDE_CONFIG_H)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Unity)

add_executable(ULibTest test.c test_uconfig_if.c test_uprotocol_if.c)
 
target_link_libraries(ULibTest ULib unity)

add_test(ULibTest ULibTest)
