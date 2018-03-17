//
// Created by Nguyen Tran on 3/17/2018.
//

#include <sstream>
#include "NestedSwitchingDifferentDistributionByLocationStrategy.h"
#include "../Model.h"
#include "../Config.h"
#include "../Random.h"
#include "../Person.h"
#include "../Scheduler.h"
#include "../Therapy.h"
#include "MFTRebalancingStrategy.h"
#include "CyclingStrategy.h"
#include "AdaptiveCyclingStrategy.h"
#include "NestedSwitchingStrategy.h"

NestedSwitchingDifferentDistributionByLocationStrategy::NestedSwitchingDifferentDistributionByLocationStrategy() = default;

NestedSwitchingDifferentDistributionByLocationStrategy::~NestedSwitchingDifferentDistributionByLocationStrategy() = default;

void NestedSwitchingDifferentDistributionByLocationStrategy::add_strategy(IStrategy *strategy) {
    strategy_list_.push_back(strategy);
}

void NestedSwitchingDifferentDistributionByLocationStrategy::add_therapy(Therapy *therapy) {


}

Therapy *NestedSwitchingDifferentDistributionByLocationStrategy::get_therapy(Person *person) {
    int loc = person->location();
    double P = Model::RANDOM->random_flat(0.0, 1.0);

    double sum = 0;
    for (int i = 0; i < distribution_[loc].size(); i++) {
        sum += distribution_[loc][i];
        if (P <= sum) {
            return strategy_list_[i]->get_therapy(person);
        }
    }
    return strategy_list_[strategy_list_.size() - 1]->get_therapy(person);
}

std::string NestedSwitchingDifferentDistributionByLocationStrategy::to_string() const {
    std::stringstream sstm;
    sstm << IStrategy::id << "-" << IStrategy::name << "-" << " switch to " << switch_to_strategy_id_ << " at "
         << strategy_switching_day_ << std::endl;


    for (int i = 0; i < distribution_[Model::CONFIG->number_of_locations() - 1].size(); i++) {
        sstm << distribution_[Model::CONFIG->number_of_locations() - 1][i] << ",";
    }
    sstm << std::endl;

    for (int i = 0; i < distribution_[Model::CONFIG->number_of_locations() - 1].size(); i++) {
        sstm << start_distribution_[Model::CONFIG->number_of_locations() - 1][i] << ",";
    }
    sstm << std::endl;

    for (int i = 0; i < distribution_[Model::CONFIG->number_of_locations() - 1].size(); i++) {
        sstm << end_distribution_[Model::CONFIG->number_of_locations() - 1][i] << ",";
    }
    sstm << std::endl;
    return sstm.str();
}

IStrategy::StrategyType NestedSwitchingDifferentDistributionByLocationStrategy::get_type() const {
    return IStrategy::NestedSwitching;
}

void NestedSwitchingDifferentDistributionByLocationStrategy::update_end_of_time_step() {
    if (Model::SCHEDULER->current_time() == strategy_switching_day_) {
        //        std::cout << to_string() << std::endl;
        strategy_list_[0] = Model::CONFIG->strategy_db()[switch_to_strategy_id_];


        if (Model::CONFIG->strategy_db()[switch_to_strategy_id_]->get_type() == IStrategy::NestedSwitching) {
            ((NestedSwitchingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->adjustDisttribution(
                    Model::SCHEDULER->current_time(), Model::CONFIG->total_time());
        }
        if (Model::CONFIG->strategy_db()[switch_to_strategy_id_]->get_type() ==
            IStrategy::NestedSwitchingDifferentDistributionByLocation) {
            ((NestedSwitchingDifferentDistributionByLocationStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->adjustDisttribution(
                    Model::SCHEDULER->current_time(), Model::CONFIG->total_time());
        }

        //        std::cout << to_string() << std::endl;
    }

    if (Model::SCHEDULER->current_time() % 30 == 0) {
        adjustDisttribution(Model::SCHEDULER->current_time(), Model::CONFIG->total_time());
        //        std::cout << to_string() << std::endl;
    }
    // update each strategy in the nest
    for (int i = 0; i < strategy_list_.size(); i++) {
        strategy_list_[i]->update_end_of_time_step();
    }
}

void NestedSwitchingDifferentDistributionByLocationStrategy::adjustDisttribution(int time, int totaltime) {
    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); loc++) {
        double dACT = ((end_distribution_[loc][0] - start_distribution_[loc][0]) * time) / totaltime +
                      start_distribution_[loc][0];

        distribution_[loc][0] = dACT;
        double otherD = (1 - dACT) / (distribution_[loc].size() - 1);
        for (int i = 1; i < distribution_[loc].size(); i++) {
            distribution_[loc][i] = otherD;
        }
    }
//    std::cout << to_string() << std::endl;
}

void NestedSwitchingDifferentDistributionByLocationStrategy::initialize_update_time() {
    // when switch to MFTBalancing
    if (Model::CONFIG->strategy_db()[switch_to_strategy_id_]->get_type() == IStrategy::MFTRebalancing) {
        //        std::cout << "hello" << std::endl;
        ((MFTRebalancingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->set_next_update_time(-1);
        ((MFTRebalancingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->set_latest_adjust_distribution_time(
                strategy_switching_day_);
    }
    // when switch to Cycling
    if (Model::CONFIG->strategy_db()[switch_to_strategy_id_]->get_type() == IStrategy::Cycling) {
        //        std::cout << "hello" << std::endl;
        ((CyclingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->set_next_switching_day(
                strategy_switching_day_ +
                ((CyclingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->cycling_time());
    }
    // when switch to AdaptiveCycling
    if (Model::CONFIG->strategy_db()[switch_to_strategy_id_]->get_type() == IStrategy::AdaptiveCycling) {
        ((AdaptiveCyclingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->set_latest_switch_time(
                strategy_switching_day_);
        ((AdaptiveCyclingStrategy *) Model::CONFIG->strategy_db()[switch_to_strategy_id_])->set_index(-1);
    }
}
