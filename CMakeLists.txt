CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(unit_test
unit_tests/unit_test.cpp)

#ADD_EXECUTABLE(rshell
#src/rshell.cpp)

ADD_EXECUTABLE(syscall
prototypes/syscall.cpp)

TARGET_LINK_LIBRARIES(unit_test gtest)
TARGET_LINK_LIBRARIES(syscall gtest)
TARGET_COMPILE_DEFINITIONS(unit_test PRIVATE gtest_disable_pthreads=ON) 
