#SET(CMAKE_C_COMPILER /home/ubuntu/zapcc-20170802-175507/bin/zapcc)
#SET(CMAKE_CXX_COMPILER /home/ubuntu/zapcc-20170802-175507/bin/zapcc++)

cmake_minimum_required(VERSION 2.8)
project (POMS)

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

#includes Gtest
#add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#${COMMON_INCLUDES}
#include dependent libs

add_subdirectory(${EXT_PROJECTS_DIR}/yaml-cpp)
set(YAML_CPP_INCLUDE_DIRS ${EXT_PROJECTS_DIR}/yaml-cpp/include)
set(YAML_CPP_LIBS_DIR ${CMAKE_BINARY_DIR}/ext/yaml-cpp)

include_directories(${YAML_CPP_INCLUDE_DIRS})

find_package(GSL REQUIRED)
if(GSL_FOUND)
    include_directories(${GSL_INCLUDE_DIRS}) 
endif()

find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)

#Setup test project
#set(PROJECT_TEST_NAME hello2_test)
#add_subdirectory(test)

#enable_testing()
#add_test(test1 ${CMAKE_BINARY_DIR}/bin/${PROJECT_TEST_NAME} --gtest_color=yes)


#add_custom_target(run
#    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/bin/hello_2
#    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/bin/hello_2
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#)
