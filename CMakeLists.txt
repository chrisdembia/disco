project(DISCO CXX)
cmake_minimum_required(VERSION 2.6)

set(LIBRARY_NAME "disco")

# --- User options
set(DISCO_BUILD_EXAMPLES FALSE CACHE BOOL
    "Build examples.")
set(DISCO_BUILD_DOC FALSE CACHE BOOL
    "Create API documentation (requires Doxygen).")

# Include headers.
include_directories(${CMAKE_SOURCE_DIR}/include)

# The library.
file(GLOB DISCO_SOURCES src/*.cpp)
file(GLOB DISCO_HEADERS include/*/*/*)

add_library(${LIBRARY_NAME} ${DISCO_SOURCES} ${DISCO_HEADERS})

# Doxygen API documentation
if(DISCO_BUILD_DOC)
    find_package(Doxygen REQUIRED)
    if(DOXYGEN_FOUND)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile
            ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile @ONLY)
        add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM)
    endif(DOXYGEN_FOUND)
endif(DISCO_BUILD_DOC)
