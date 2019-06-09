CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/client.cpp
    src/pipe.cpp
    src/command.cpp
    src/and.cpp
    src/semi.cpp
    src/input.cpp
    src/iopipe.cpp
    src/output.cpp
)

ADD_EXECUTABLE(test
    unit_tests/unit_test.cpp
    src/client.cpp
    src/pipe.cpp
    src/command.cpp
    src/and.cpp
    src/semi.cpp
    src/input.cpp
    src/iopipe.cpp
    src/output.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
