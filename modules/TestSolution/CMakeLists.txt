project(TestSolution)


message(STATUS "//----- TestSolution ------")

#
# 3rd party libraries.
#

# boost libraries.

find_package(Boost REQUIRED COMPONENTS
	filesystem
	system
	unit_test_framework)

include_directories (${TEST_SOURCE_DIR}/src
                     ${Boost_INCLUDE_DIRS}
					 ${CMAKE_SOURCE_DIR}/modules/MathLib/include
                     )

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (TestSolution src/test.cpp)

target_link_libraries (TestSolution
                     MathLib
                     ${Boost_FILESYSTEM_LIBRARY}
                     ${Boost_SYSTEM_LIBRARY}
                     ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                     )
					 
#
# Copy dependent DLLs and data files to the output directory.
#
if (MSVC)
	set(_BINARIES "")
		list(APPEND _BINARIES "${BOOST_LIBRARYDIR}/boost_unit_test_framework-vc120-mt-gd-1_59.dll")
		
	# Copy files.
	foreach(_binary ${_BINARIES})
		get_filename_component(_binary_filename ${_binary} NAME)
		add_custom_command(
			TARGET TestSolution
			POST_BUILD
			COMMAND
				${CMAKE_COMMAND} -E copy_if_different ${_binary} $<TARGET_FILE_DIR:TestSolution>
			COMMENT
				"Copying dependencies..."
			VERBATIM)
	endforeach()
endif()
add_test (NAME MyTest COMMAND TestSolution)