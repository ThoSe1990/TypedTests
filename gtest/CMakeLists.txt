

set(XML_FILE_PATH "${PROJECT_SOURCE_DIR}/gtest/examples/example.xml")
set(JSON_FILE_PATH "${PROJECT_SOURCE_DIR}/gtest/examples/example.json")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/book_test_variables.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/book_test_variables.hpp)


set(target unittests)

add_executable(${target} ${CMAKE_CURRENT_SOURCE_DIR}/book_interface_tests.cc)

target_include_directories(${target} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${target} ${CONAN_LIBS})

add_test(NAME ${target} COMMAND ${target})
