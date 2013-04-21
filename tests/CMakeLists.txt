include_directories(
    ${CMAKE_SOURCE_DIR}/googletest
    ${CMAKE_SOURCE_DIR}/googletest/include
    )

add_executable(testValues testValues.cpp)
target_link_libraries(testValues gtest_main disco)

add_test(
    NAME testfwk
    COMMAND testInterface testNominal testLog testActivity
    )

add_test(
    NAME testdisco
    COMMAND testValues
    )


