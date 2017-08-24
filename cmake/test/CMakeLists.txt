
include_directories(${GTEST_INCLUDE_DIRS})


file(GLOB TEST_SRC_FILES *.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ../src/Board.cpp ../src/Board.h)

#add_dependencies(${PROJECT_TEST_NAME} googletest)
#
#  {add_dependencies(${PROJECT_TEST_NAME} yaml_cpp) 

target_link_libraries(${PROJECT_TEST_NAME}

    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    pthread 

     ${Boost_LIBRARIES}   ${YAML_CPP_LIBS_DIR}/libyaml-cpp.a
)

target_compile_features(${PROJECT_TEST_NAME} PRIVATE cxx_range_for)
