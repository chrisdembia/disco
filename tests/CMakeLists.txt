include_directories(
    ${CMAKE_SOURCE_DIR}/googletest
    ${CMAKE_SOURCE_DIR}/googletest/include
    )

macro(disco_test DISCO_TEST_NAME)

    project(${DISCO_TEST_NAME})

    add_executable(test${DISCO_TEST_NAME} "test${DISCO_TEST_NAME}.cpp")

    target_link_libraries(test${DISCO_TEST_NAME} gtest_main
        discoframework)

    add_test(NAME test${DISCO_TEST_NAME} COMMAND test${DISCO_TEST_NAME})

endmacro()

disco_test(Values)
disco_test(Interface)
