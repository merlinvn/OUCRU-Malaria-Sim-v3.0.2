
file(GLOB SRC_FILES *.cpp)

add_executable(MaSim ${SRC_FILES})

#add_dependencies(MaSim yaml_cpp) 

target_link_libraries(MaSim ${Boost_LIBRARIES} ${YAML_CPP_LIBS_DIR}/libyaml-cpp.a ${GSL_LIBRARIES} ${GSLCBLAS_LIBRARIES}
)

target_compile_features(MaSim PRIVATE cxx_range_for)
