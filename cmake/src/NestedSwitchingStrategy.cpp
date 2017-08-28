/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NestedSwitchingStrategy.cpp
 * Author: Merlin
 * 
 * Created on August 25, 2017, 11:07 AM
 */

#include "NestedSwitchingStrategy.h"
#include "Config.h"
#include "Model.h"
#include "Random.h"
#include "Scheduler.h"

NestedSwitchingStrategy::NestedSwitchingStrategy() {
}

NestedSwitchingStrategy::NestedSwitchingStrategy(const NestedSwitchingStrategy& orig) {
}

NestedSwitchingStrategy::~NestedSwitchingStrategy() {
}

void NestedSwitchingStrategy::add_strategy(IStrategy* strategy) {
    strategy_list_.push_back(strategy);
}

Therapy* NestedSwitchingStrategy::get_therapy() {
    double P = Model::RANDOM->random_flat(0.0, 1.0);

    double sum = 0;
    for (int i = 0; i < distribution_.size(); i++) {
        sum += distribution_[i];
        if (P <= sum) {
            return strategy_list_[i]->get_therapy();
        }
    }

    return strategy_list_[strategy_list_.size() - 1]->get_therapy();
}

void NestedSwitchingStrategy::add_therapy(Therapy* therapy) {

}

IStrategy::StrategyType NestedSwitchingStrategy::get_type() const {
    return IStrategy::NestedSwitching;
}

std::string NestedSwitchingStrategy::to_string() const {
    std::stringstream sstm;
    sstm << IStrategy::id << "-" << IStrategy::name << "-";
    return sstm.str();
}

void NestedSwitchingStrategy::update_end_of_time_step() {
    if (Model::SCHEDULER->current_time() == strategy_switching_day_) {
        //        std::cout << to_string() << std::endl;   
        strategy_list_[0] = Model::CONFIG->strategy_db()[switch_to_strategy_id_];
        //        std::cout << to_string() << std::endl;
    }

    if (Model::SCHEDULER->current_time() % 30 == 0) {
        adjustDisttribution(Model::SCHEDULER->current_time(), Model::CONFIG->total_time());
        //        std::cout << to_string() << std::endl;
    }
}

void NestedSwitchingStrategy::adjustDisttribution(int time, int totaltime) {

    double dACT = ((end_distribution_[0] - start_distribution_[0]) * time) / totaltime + start_distribution_[0];

    distribution_[0] = dACT;
    double otherD = (1 - dACT) / (distribution_.size() - 1);
    for (int i = 1; i < distribution_.size(); i++) {
        distribution_[i] = otherD;
    }
}