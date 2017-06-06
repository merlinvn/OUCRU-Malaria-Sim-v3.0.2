/* 
 * File:   AdaptiveCyclingStrategy.cpp
 * Author: nguyentran
 * 
 * Created on June 4, 2013, 11:10 AM
 */

#include "AdaptiveCyclingStrategy.h"
#include "Model.h"
#include "ModelDataCollector.h"
#include "Config.h"
#include <iostream>

AdaptiveCyclingStrategy::AdaptiveCyclingStrategy() : trigger_value_(0), delay_until_actual_trigger_(0), turn_off_days_(0), latest_switch_time_(0) {
    set_index(0);
}

AdaptiveCyclingStrategy::AdaptiveCyclingStrategy(const AdaptiveCyclingStrategy& orig) {
}

AdaptiveCyclingStrategy::~AdaptiveCyclingStrategy() {
}

bool AdaptiveCyclingStrategy::is_strategy(const std::string& sName) {
    return ("AdaptiveCyclingStrategy" == sName);
}

void AdaptiveCyclingStrategy::switch_therapy() {
//    std::cout << "Switch from: " << index_ << "\t - to: " << index_ + 1;
    index_++;
    index_ %= therapy_list().size();

    Model::DATA_COLLECTOR->update_UTL_vector();
}

Therapy* AdaptiveCyclingStrategy::get_therapy() {
    return therapy_list()[index_];
}

std::string AdaptiveCyclingStrategy::to_string() const {
    return "AdaptiveCyclingStrategy";
}

int AdaptiveCyclingStrategy::to_int() const {
    return Strategy::AdaptiveCycling;
}

void AdaptiveCyclingStrategy::check_and_switch_therapy() {

    if (Model::SCHEDULER->current_time() > Model::CONFIG->start_treatment_day() + 60) {
        if (Model::SCHEDULER->current_time() == latest_switch_time_) {
            //            std::cout << "swith therapy" << std::endl;
            switch_therapy();
        } else {
            //average TF60
            double avg = 0;
            for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
                avg += Model::DATA_COLLECTOR->current_TF_by_location()[location];
            }
            avg = avg / Model::CONFIG->number_of_locations();

            if (avg > trigger_value_) {
                if (Model::SCHEDULER->current_time() > (latest_switch_time_ + turn_off_days_)) {
                    latest_switch_time_ = Model::SCHEDULER->current_time() + delay_until_actual_trigger_;
                    //                    std::cout << "switch at: " << latest_switch_time_ << std::endl;
                }
            }
        }
    }
}

void AdaptiveCyclingStrategy::check_and_switch_non_art_therapy() {
    
}