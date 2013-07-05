project(disco CXX)
cmake_minimum_required(VERSION 2.6)

# User options
# -----------------------------------------------------------------------------
option(DISCO_BUILD_TESTS "Set up google-test targets." OFF)
option(DISCO_BUILD_EXAMPLES
    "Build examples that illustrate how to use the engine."
    OFF)
option(DISCO_BUILD_DOC
    "Create API documentation (requires Doxygen)."
    OFF)

# Our CMake settings
# -----------------------------------------------------------------------------
# Place libraries in the root of the build directory.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # static
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # dynamic

# Build googletest.
# -----------------------------------------------------------------------------
if(DISCO_BUILD_TESTS)
    # To use CTest.
    enable_testing()
    # To build the googletest project.
    add_subdirectory(googletest)
    # To build this project's tests.
    add_subdirectory(tests)
endif()

# Doxygen API documentation.
# -----------------------------------------------------------------------------
if(DISCO_BUILD_DOC)
    find_package(Doxygen REQUIRED)
    if(DOXYGEN_FOUND)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
            ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile @ONLY)
        add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM)
        install(DIRECTORY doc DESTINATION doc)
    endif(DOXYGEN_FOUND)
endif(DISCO_BUILD_DOC)

# The libraries.
# -----------------------------------------------------------------------------
add_subdirectory(disco)
