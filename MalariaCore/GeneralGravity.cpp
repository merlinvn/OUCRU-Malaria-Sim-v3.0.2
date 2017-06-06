#include "GeneralGravity.h"
#include "Model.h"
#include "ModelDataCollector.h"

GeneralGravity::GeneralGravity() {
    
}

GeneralGravity::GeneralGravity(const GeneralGravity&) {
    
}

GeneralGravity::~GeneralGravity() {
    
}

std::string GeneralGravity::to_string() const {
    return "GeneralGravity";
}

int GeneralGravity::to_int() const {
    return SpatialStructure::GeneralGravity;
}

std::vector<double> GeneralGravity::get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location) {
    std::vector<double> v_relative_number_of_circulation_by_location(Model::CONFIG->number_of_locations(), 0);
    for (int target_location = 0; target_location < Model::CONFIG->number_of_locations(); target_location++) {
        if (relative_distance_vector[target_location] == 0) {
            v_relative_number_of_circulation_by_location[target_location] = 0;
        } else {
            v_relative_number_of_circulation_by_location[target_location] = v_original_pop_size_by_location[from_location] * v_original_pop_size_by_location[target_location] / relative_distance_vector[target_location];
        }
    }
    
    return v_relative_number_of_circulation_by_location;
//    return relative_distance_vector;
}
