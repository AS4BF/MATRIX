project(LinAlgebra)

add_library(
    ${PROJECT_NAME} src/Matrix.cpp
    )

add_library(
    sub::algebra ALIAS ${PROJECT_NAME}
    )

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include
    )