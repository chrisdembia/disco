project(disco CXX)
cmake_minimum_required(VERSION 2.8)

# User options
# -----------------------------------------------------------------------------
option(DISCO_BUILD_TESTS
    "Set up google-test targets."
    OFF)
option(DISCO_BUILD_EXAMPLES
    "Build examples that illustrate how to use the engine."
    OFF)
option(DISCO_BUILD_DOC
    "Create API documentation (requires Doxygen)."
    OFF)

# Dependencies
# -----------------------------------------------------------------------------
# We use Boost.Units. Boost.Units is headers-only; we do not need to link to
# any Boost libraries.
find_package(Boost 1.40 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# Our CMake settings
# -----------------------------------------------------------------------------
# Place libraries in the root of the build directory.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # static
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) # dynamic

# We've created this ourselves; on Windows machines, shared libraries go into
# the bin folder so that they are easily placed on the PATH.
if(WINDOWS)
    set(DISCO_SHARED_LIBRARY_DESTINATION bin)
else()
    set(DISCO_SHARED_LIBRARY_DESTINATION lib)
endif()

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
        install(DIRECTORY ${PROJECT_BINARY_DIR}/doc/html/ DESTINATION doc)
    endif(DOXYGEN_FOUND)
endif(DISCO_BUILD_DOC)

# The libraries.
# -----------------------------------------------------------------------------
add_subdirectory(disco)
