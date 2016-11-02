project(MathLib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(ENABLE_SSE2 ON)
set(ENABLE_MP ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(PCHSupport)

message(STATUS "//----- MathLib ------")
#
# Source files.
#

set(HEADERS
	include/MathFunctions.h
	)
	
set(SOURCES
	src/MathFunctions.cpp
	)

set(MISC
	src/pch.h
	src/pch.cpp
	)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("" FILES ${MISC})

include_directories(
	include/MathLib
	${CMAKE_SOURCE_DIR}/modules/MathLib/include
	${CMAKE_SOURCE_DIR}/modules/MathLib/src
	)
	
	
add_library(MathLib ${HEADERS}
	${SOURCES}
	${MISC})