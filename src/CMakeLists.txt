cmake_minimum_required(VERSION 3.12)

set(SOURCE_FILE_ALL 
    ${CMAKE_CURRENT_LIST_DIR}/ULib.c
    ${CMAKE_CURRENT_LIST_DIR}/uconfig/uconfig.c
    ${CMAKE_CURRENT_LIST_DIR}/uprotocol/uprotocol.c
)

set(HEADER_FILE_ALL 
    ${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/uconfig/
    ${CMAKE_CURRENT_LIST_DIR}/uprotocol/
)

add_library(ULib OBJECT)
target_sources(ULib PRIVATE ${SOURCE_FILE_ALL})
target_include_directories(ULib PUBLIC ${HEADER_FILE_ALL}/)

