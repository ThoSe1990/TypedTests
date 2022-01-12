

set(target dont_marry_frameworks)

add_executable(${target} 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp 
)

target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${target} PUBLIC ${CONAN_LIBS} stdc++fs)