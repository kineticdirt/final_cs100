CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(library
	src/main.cpp
	src/library.cpp
	src/user.cpp
	src/catalog.cpp
)

