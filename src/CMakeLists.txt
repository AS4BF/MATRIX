project(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    sub::alloc
    sub::algebra
)





    