CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)


ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(library
	src/main.cpp
	src/library.cpp
	src/user.cpp
	src/catalog.cpp
	src/Admin.cpp
)

ADD_EXECUTABLE(test tests/unit_test.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

