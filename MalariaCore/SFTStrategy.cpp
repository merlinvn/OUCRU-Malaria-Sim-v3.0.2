/* 
 * File:   SFTStrategy.cpp
 * Author: nguyentran
 * 
 * Created on June 3, 2013, 8:00 PM
 */

#include <assert.h>
#include "SFTStrategy.h"
#include "Therapy.h"
#include "IStrategy.h"

SFTStrategy::SFTStrategy() {
}

SFTStrategy::SFTStrategy(const SFTStrategy& orig) {
}

SFTStrategy::~SFTStrategy() {
}

std::vector<Therapy*>& SFTStrategy::get_therapy_list(){
    return therapy_list_;
}

void SFTStrategy::add_therapy(Therapy* therapy) {
    therapy_list_.push_back(therapy);
}

bool SFTStrategy::is_strategy(const std::string& sName) {
    return ("SFTStrategy" == sName);
}

Therapy* SFTStrategy::get_therapy() {
    return therapy_list_[0];
}

std::string SFTStrategy::to_string() const {
    return "SFTStrategy";
}

IStrategy::StrategyType SFTStrategy::get_type() const {
    return IStrategy::SFT;
}

void SFTStrategy::update_end_of_time_step() {
    //do nothing here
}