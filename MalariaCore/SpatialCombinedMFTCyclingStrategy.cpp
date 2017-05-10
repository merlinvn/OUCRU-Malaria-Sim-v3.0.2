#include "SpatialCombinedMFTCyclingStrategy.h"
#include "Therapy.h"
#include "Model.h"
#include "ModelDataCollector.h"

SpatialCombinedMFTCyclingStrategy::SpatialCombinedMFTCyclingStrategy() : index_(0), cycling_time_(0) {
}

SpatialCombinedMFTCyclingStrategy::SpatialCombinedMFTCyclingStrategy(const SpatialCombinedMFTCyclingStrategy& orig) {
}

SpatialCombinedMFTCyclingStrategy::~SpatialCombinedMFTCyclingStrategy() {
}

bool SpatialCombinedMFTCyclingStrategy::is_strategy(const std::string& sName) {
    return ("CyclingStrategy" == sName);
}

void SpatialCombinedMFTCyclingStrategy::switch_therapy() {
//    std::cout << "Switch from: " << index_ << "\t - to: " << index_ + 1;
    index_++;
    index_ %= therapy_list().size();
    Model::DATA_COLLECTOR->update_UTL_vector();
}

Therapy* SpatialCombinedMFTCyclingStrategy::get_therapy() {

    if (Model::DATA_COLLECTOR->collect_person_location() % 3 == 0) {
        return therapy_list()[(index_ + 0) % 3];
    } else if (Model::DATA_COLLECTOR->collect_person_location() % 3 == 1) {
        return therapy_list()[(index_ + 1) % 3];
    } else {
        return therapy_list()[(index_ + 2) % 3];
    }
}

std::string SpatialCombinedMFTCyclingStrategy::to_string() const {
    return "SpatialCombinedMFTCyclingStrategy";
}

int SpatialCombinedMFTCyclingStrategy::to_int() const {
    return Strategy::SpatialCombinedMFTCycling;
}

void SpatialCombinedMFTCyclingStrategy::check_and_switch_therapy() {

    if (Model::SCHEDULER->current_time() > Model::CONFIG->start_treatment_day()) {
        if (((Model::SCHEDULER->current_time() - Model::CONFIG->start_treatment_day()) % cycling_time_) == 0) {

            switch_therapy();
        }
    }

}

void SpatialCombinedMFTCyclingStrategy::check_and_switch_non_art_therapy() {
    
}
