include_directories(
    ${CMAKE_SOURCE_DIR}/googletest
    ${CMAKE_SOURCE_DIR}/googletest/include
    )

macro(disco_test DISCO_EXAMPLE_NAME)

    project(${DISCO_EXAMPLE_NAME})

    add_executable(test${DISCO_EXAMPLE_NAME} "test${DISCO_EXAMPLE_NAME}.cpp")

    target_link_libraries(test${DISCO_EXAMPLE_NAME} gtest_main disco)

endmacro()

disco_test(Values)
disco_test(Interface)

add_test(
    NAME testfwk
    COMMAND testInterface
    )

add_test(
    NAME testdisco
    COMMAND testValues
    )


