cmake_minimum_required(VERSION 3.10)

set(ENABLE_GTEST ON)

set(project_name "otus_hw_2")
project(${project_name})

enable_testing()
find_package(GTest REQUIRED)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(FULL_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PATCH_VERSION})

message(STATUS "Full version: ${FULL_VERSION}")

add_executable(${project_name} 
	main.cc
)

set_target_properties(${project_name} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

# if (ENABLE_GTEST)
# 	add_executable(${project_tests_name}
# 		test_version.cc
# 	)
# 	set_target_properties(${project_tests_name} PROPERTIES
# 		CXX_STANDARD 14
# 		CXX_STANDARD_REQUIRED ON
# 	)
# 	include_directories(${GTEST_INCLUDE_DIR})

# 	target_link_libraries(${project_tests_name} 
# 		GTest::GTest 
# 		GTest::Main
# 		${project_lib_name}
# 	)

# 	message(STATUS "Adds test ${project_tests_name}")

# 	add_test(NAME ${project_tests_name} COMMAND ${project_tests_name}
# )
# endif()

install(TARGETS ${project_name} RUNTIME DESTINATION bin)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CPACK_GENERATOR TGZ)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(CPACK_GENERATOR DEB)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PATCH_VERSION})

set(CPACK_PACKAGE_CONTACT alexey.gretsov@gmail.com)

include(CPack)

