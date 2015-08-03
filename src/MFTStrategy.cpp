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

MFTStrategy::MFTStrategy(const MFTStrategy &orig) {
}

MFTStrategy::~MFTStrategy() {
}

bool MFTStrategy::is_strategy(const std::string &sName) {
    return ("MFTStrategy" == sName);
}

void MFTStrategy::switch_therapy() {
    assert(false);
}

Therapy *MFTStrategy::get_therapy() {


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

int MFTStrategy::to_int() const {
    return Strategy::MFT;
}

void MFTStrategy::check_and_switch_therapy() {
    //do nothing here
}