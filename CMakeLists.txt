project(DISCO CXX)
cmake_minimum_required(VERSION 2.6)

set(LIBRARY_NAME "disco")

# --- User options
set(DISCO_BUILD_EXAMPLES FALSE CACHE BOOL)
set(DISCO_BUILD_DOC FALSE CACHE BOOL
    "Create API documentation (requires Doxygen).")

# Include headers.
include_directories(${CMAKE_SOURCE_DIR}/include)

# The library.
file(GLOB DISCO_SOURCES src/*.cpp)
file(GLOB DISCO_HEADERS include/*.h)

add_library(${LIBRARY_NAME} ${DISCO_SOURCES} ${DISCO_HEADERS})
