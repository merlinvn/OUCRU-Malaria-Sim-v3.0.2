file(GLOB SRC_FILES *.cpp *.h Spatial/*.cpp Spatial/*.h)

add_executable(MaSim ${SRC_FILES} ObjectPool.h)

add_dependencies(MaSim yaml-cpp) 

target_link_libraries(MaSim ${Boost_LIBRARIES}
        ${YAML_CPP_LIBS_DIR}/libyaml-cpp.a
        ${GSL_LIBRARIES}
        ${GSLCBLAS_LIBRARIES})

install(TARGETS MaSim DESTINATION ${PROJECT_SOURCE_DIR}/bin)