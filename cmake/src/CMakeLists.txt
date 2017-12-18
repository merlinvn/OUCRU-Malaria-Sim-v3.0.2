add_definitions(-std=c++11)

file(GLOB SRC_FILES *.cpp)

add_executable(MaSim ${SRC_FILES})

add_dependencies(MaSim yaml-cpp) 

target_link_libraries(MaSim ${Boost_LIBRARIES} ${YAML_CPP_LIBS_DIR}/libyaml-cpp.a ${GSL_LIBRARIES} ${GSLCBLAS_LIBRARIES})

