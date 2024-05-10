cmake_minimum_required(VERSION 3.12)

project(ULib)

include_directories(${CMAKE_CURRENT_LIST_DIR}/)

if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    # add_compile_definitions(/w35045)
    add_compile_options(/wd5045)
endif()

# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) 
add_subdirectory(src/)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(test)
endif()
