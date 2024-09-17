set(gtest_force_shared_crt on)
add_subdirectory("googletest")

if(BUILD_TESTING)
	file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/libLifeSchedulerFramework/*.test.cpp")
	message(STATUS "beep ${SRC_FILES}")
	add_executable(${PROJECT_NAME}_test
		${SRC_FILES}
	)

	if (CMAKE_VERSION VERSION_GREATER 3.12)
		set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 20)
	endif()

	target_link_libraries(${PROJECT_NAME}_test PRIVATE
		GTest::gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(${PROJECT_NAME}_test)
endif()