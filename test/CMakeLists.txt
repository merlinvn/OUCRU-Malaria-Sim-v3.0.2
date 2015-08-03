file(GLOB_RECURSE project_SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM project_SRCS "${PROJECT_SOURCE_DIR}/src/main.cpp")

file (GLOB_RECURSE test_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)

SET (test_LIBS )
SET (test_BIN ${PROJECT_NAME}-unittests)

add_executable(${test_BIN} ${test_SRCS} ${project_SRCS})
TARGET_LINK_LIBRARIES(${test_BIN} ${test_LIBS})