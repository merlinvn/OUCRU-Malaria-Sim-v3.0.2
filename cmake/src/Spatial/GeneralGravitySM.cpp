//
// Created by Nguyen Tran on 1/29/2018.
//

#include "GeneralGravitySM.h"
#include "../Model.h"
#include "../Config.h"

namespace Spatial {

    GeneralGravitySM::GeneralGravitySM() {

    }

    GeneralGravitySM::~GeneralGravitySM() {

    }

    DoubleVector GeneralGravitySM::get_v_relative_outmovement_to_destination(const int &from_location,
                                                                             const DoubleVector &relative_distance_vector,
                                                                             const IntVector &v_number_of_residents_by_location) const {
        std::vector<double> v_relative_number_of_circulation_by_location(Model::CONFIG->number_of_locations(), 0);
        for (int target_location = 0; target_location < Model::CONFIG->number_of_locations(); target_location++) {
            if (relative_distance_vector[target_location] == 0) {
                v_relative_number_of_circulation_by_location[target_location] = 0;
            } else {
                v_relative_number_of_circulation_by_location[target_location] =
                        v_number_of_residents_by_location[from_location] *
                        v_number_of_residents_by_location[target_location] / relative_distance_vector[target_location];
            }
        }

        return v_relative_number_of_circulation_by_location;
    }
}