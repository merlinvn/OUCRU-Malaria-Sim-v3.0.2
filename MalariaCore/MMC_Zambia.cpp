#include "MMC_Zambia.h"
#include "Model.h"
#include "ModelDataCollector.h"

MMC_Zambia::MMC_Zambia() {
    
}

MMC_Zambia::MMC_Zambia(const MMC_Zambia&) {
    
}

MMC_Zambia::~MMC_Zambia() {
    
}

std::string MMC_Zambia::to_string() const {
    return "MMC_Zambia";
}

int MMC_Zambia::to_int() const {
    return SpatialStructure::MMC_Zambia;
}

std::vector<double> MMC_Zambia::get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location) {
    std::vector<double> v_relative_number_of_circulation_by_location(Model::CONFIG->number_of_locations(), 0);
    for (int target_location = 0; target_location < Model::CONFIG->number_of_locations(); target_location++) {
        if (relative_distance_vector[target_location] == 0) {
            v_relative_number_of_circulation_by_location[target_location] = 0;
        } else {
            v_relative_number_of_circulation_by_location[target_location] = theta_ * ( pow(v_original_pop_size_by_location[from_location], alpha_) + pow(v_original_pop_size_by_location[target_location], beta_) )  / ( pow(relative_distance_vector[target_location], gamma_) );
        }
    }
    
    return v_relative_number_of_circulation_by_location;
}
