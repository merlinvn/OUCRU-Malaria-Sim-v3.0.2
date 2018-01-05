#include "SpatialMFTStrategy.h"
#include "Random.h"
#include "Model.h"
#include "ModelDataCollector.h"
#include <assert.h>

SpatialMFTStrategy::SpatialMFTStrategy() : distribution_(), therapy_by_location_(Model::CONFIG->number_of_locations()) {
    //    if (config != NULL) {
    //        if (config->model() != NULL) {
    //            random_ = config->model()->random();
    //        }
    //    }

}

SpatialMFTStrategy::SpatialMFTStrategy(const SpatialMFTStrategy& orig) {
}

SpatialMFTStrategy::~SpatialMFTStrategy() {
}

bool SpatialMFTStrategy::is_strategy(const std::string& sName) {
    return ("SpatialMFTStrategy" == sName);
}

void SpatialMFTStrategy::switch_therapy() {
    assert(false);
}

Therapy* SpatialMFTStrategy::get_therapy() {

    if (Model::SCHEDULER->current_time() == Model::CONFIG->start_collect_data_day()) {
        draw_random_location_for_assigning_therapy();
    }
    
    return therapy_list()[therapy_by_location_[Model::DATA_COLLECTOR->collect_person_location()]];
}

std::string SpatialMFTStrategy::to_string() const {
    return "SpatialMFTStrategy";
}

int SpatialMFTStrategy::to_int() const {
    return Strategy::SpatialMFT;
}

void SpatialMFTStrategy::check_and_switch_therapy()  {
    //do nothing here
}

void SpatialMFTStrategy::draw_random_location_for_assigning_therapy() {
    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); loc++) {
        double P = Model::RANDOM->random_flat(0.0, 1.0);
        if (P < 0.3333) {
            therapy_by_location_[loc] = 0;
        } else if (P < 0.6666 && P > 0.3333) {
            therapy_by_location_[loc] = 1;
        } else {
            therapy_by_location_[loc] = 2;
        }
    }
}
