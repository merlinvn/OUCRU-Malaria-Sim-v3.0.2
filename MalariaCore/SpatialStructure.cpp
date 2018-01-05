#include "SpatialStructure.h"
#include <boost/foreach.hpp>

SpatialStructure::SpatialStructure() {
}

SpatialStructure::SpatialStructure(const SpatialStructure& orig) {
}

SpatialStructure::~SpatialStructure() {
}

std::vector<double> SpatialStructure::get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location) {
    return relative_distance_vector;
}