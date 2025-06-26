project(allocator)

add_library(
    ${PROJECT_NAME} src/Allocator.cpp src/LinAllocator.cpp
    )

add_library(
    sub::alloc ALIAS ${PROJECT_NAME}
    )

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include
    )

    