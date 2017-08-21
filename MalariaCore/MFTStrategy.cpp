/* 
 * File:   MFTStrategy.cpp
 * Author: nguyentran
 * 
 * Created on June 4, 2013, 11:09 AM
 */

#include "MFTStrategy.h"
#include "Random.h"
#include "Model.h"
#include <assert.h>

MFTStrategy::MFTStrategy() : distribution_() {
    //    if (config != NULL) {
    //        if (config->model() != NULL) {
    //            random_ = config->model()->random();
    //        }
    //    }

}

MFTStrategy::MFTStrategy(const MFTStrategy& orig) {
}

MFTStrategy::~MFTStrategy() {
}

std::vector<Therapy*>& MFTStrategy::get_therapy_list(){
    return therapy_list_;
}

void MFTStrategy::add_therapy(Therapy* therapy){
    therapy_list_.push_back(therapy);
}

bool MFTStrategy::is_strategy(const std::string& sName) {
    return ("MFTStrategy" == sName);
}

Therapy* MFTStrategy::get_therapy() {

    double P = Model::RANDOM->random_flat(0.0, 1.0);

    double sum = 0;
    for (int i = 0; i < distribution_.size(); i++) {
        sum += distribution_[i];
        if (P <= sum) {
            return therapy_list()[i];
        }
    }

    return therapy_list()[therapy_list().size() - 1];
}

std::string MFTStrategy::to_string() const {
    return "MFTStrategy";
}

IStrategy::StrategyType MFTStrategy::get_type() const {
    return IStrategy::MFT;
}

void MFTStrategy::update_end_of_time_step()  {
    //do nothing here
}