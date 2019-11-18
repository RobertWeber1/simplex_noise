cmake_minimum_required(VERSION 3.10)

project("simplex_noise" CXX)


add_executable(${PROJECT_NAME}-test EXCLUDE_FROM_ALL
	test/catch.cpp
	test/square_root.cpp
	test/squash.cpp
	test/vector.cpp
	test/calc.cpp
)

target_compile_options(${PROJECT_NAME}-test
	PRIVATE -std=c++1z
	PRIVATE -fsanitize=address
	PRIVATE -fsanitize=undefined
)

target_include_directories(${PROJECT_NAME}-test
	PRIVATE src/
	PRIVATE test/
)

target_link_libraries(${PROJECT_NAME}-test
	asan
	ubsan
)
