# CMakeList.txt : CMake project for LifeSchedulerFramework, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("libLifeSchedulerFramework")

# Add source to this project's executable.
add_library (${PROJECT_NAME})

target_sources(${PROJECT_NAME} 
	PRIVATE
		"libLifeSchedulerFramework/Tag.h"
		"libLifeSchedulerFramework/Tag.cpp"
		"libLifeSchedulerFramework/Item.h" 
		"libLifeSchedulerFramework/Item.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET libLifeSchedulerFramework PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
include(CTest)
add_subdirectory("External/googletest")

if(BUILD_TESTING)
	file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/libLifeSchedulerFramework/*.test.cpp")
	file(GLOB H_FILES "${PROJECT_SOURCE_DIR}/libLifeSchedulerFramework/*.test.cpp")
	add_executable(${PROJECT_NAME}_test
		${SRC_FILES}
		${H_FILES}
	)

	target_link_libraries(${PROJECT_NAME}_test PRIVATE
		GTest::gtest_main
	)
	include(GoogleTest)
	gtest_discover_tests(${PROJECT_NAME}_test)
endif()