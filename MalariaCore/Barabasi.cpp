#include "Barabasi.h"
#include "Model.h"
#include "ModelDataCollector.h"
#include "cmath"

Barabasi::Barabasi() {
    
}

Barabasi::Barabasi(const Barabasi&) {
    
}

Barabasi::~Barabasi() {
    
}

std::string Barabasi::to_string() const {
    return "Barabasi";
}

int Barabasi::to_int() const {
    return SpatialStructure::Barabasi;
}

std::vector<double> Barabasi::get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location) {
    std::vector<double> v_relative_number_of_circulation_by_location(Model::CONFIG->number_of_locations(), 0);
    
    for (int target_location = 0; target_location < Model::CONFIG->number_of_locations(); target_location++) {
        if (relative_distance_vector[target_location] == 0) {
            v_relative_number_of_circulation_by_location[target_location] = 0;
        } else {
            v_relative_number_of_circulation_by_location[target_location] = pow((relative_distance_vector[target_location] + r_g_0_), -beta_r_) * exp(-r_g_0_ / kappa_);   // equation from Barabasi's paper
        }
    }
    
    return v_relative_number_of_circulation_by_location;
}
