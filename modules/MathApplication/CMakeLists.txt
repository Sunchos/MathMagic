project(MathApplication)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(ENABLE_SSE2 ON)
set(ENABLE_MP ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(PCHSupport)

message(STATUS "//----- MathApplication ------")

#
# 3rd party libraries.
#

# boost libraries.
if (MSVC)
	# Disable auto-linking to boost libraries.
	add_definitions(-DBOOST_ALL_NO_LIB)
endif()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS
	filesystem
	system
	unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

if (MSVC)
	# warning C4251: 'name' : class 'name' needs to have dll-interface to be used by clients of class 'name'.
	add_definitions(/wd4251)
	# warning C4503: decorated name length exceeded, name was truncated.
	add_definitions(/wd4503)
	# warning C4714: function 'name' marked as __forceinline not inlined.
	add_definitions(/wd4714)
endif()

#
# Source files.
#

set(HEADERS
	)
	
set(SOURCES
	src/main.cpp
	)

set(MISC
	src/pch.h
	src/pch.cpp
	)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("" FILES ${MISC})

add_executable(MathApplication 
	${HEADERS}
	${SOURCES}
	${MISC})
	
set_target_properties(MathApplication PROPERTIES OUTPUT_NAME "MathApplication")

add_precompiled_headers(MathApplication "src/")

include_directories(
	include/MathApplication
	${CMAKE_SOURCE_DIR}/modules/MathApplication/include
	${CMAKE_SOURCE_DIR}/modules/MathApplication/src
	${CMAKE_SOURCE_DIR}/modules/MathLib/include
	)
	
target_link_libraries(MathApplication
	${Boost_LIBRARIES}
	MathLib
	)
	
add_dependencies(MathApplication
	boost
	MathLib
	)
	
#set(MODULES_TESTGEO ${MODULES_PATH}/MathApplication)
set(_APPS "\${CMAKE_INSTALL_PREFIX}/MathApplication.exe")