/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmartMFTStrategy.cpp
 * Author: Merlin
 * 
 * Created on August 25, 2017, 11:57 AM
 */

#include "SmartMFTStrategy.h"
#include "Model.h"
#include "Config.h"
#include "ModelDataCollector.h"
#include "Therapy.h"

SmartMFTStrategy::SmartMFTStrategy() {
}

SmartMFTStrategy::SmartMFTStrategy(const SmartMFTStrategy& orig) {
}

SmartMFTStrategy::~SmartMFTStrategy() {

}

IStrategy::StrategyType SmartMFTStrategy::get_type() const {
    return IStrategy::SmartMFT;
}

std::string SmartMFTStrategy::to_string() const {
    std::stringstream sstm;
    //    sstm << IStrategy::id << "-" << IStrategy::name << "-";
    //
    //    for (int i = 0; i < therapy_list().size() - 1; i++) {
    //        sstm << therapy_list()[i]->id() << ",";
    //    }
    //    sstm << therapy_list()[therapy_list().size() - 1]->id() << "-";
    //
    //    for (int i = 0; i < distribution().size() - 1; i++) {
    //        sstm << distribution()[i] << ",";
    //    }
    //    sstm << distribution()[therapy_list().size() - 1] << "-" << update_distribution_duration_;
    sstm << MFTStrategy::to_string() << "-" << update_distribution_duration_;
    return sstm.str();
}

void SmartMFTStrategy::update_end_of_time_step() {

    if (Model::SCHEDULER->current_time() > Model::CONFIG->start_treatment_day() + update_distribution_duration_
            && Model::SCHEDULER->current_time() % update_distribution_duration_ == 0) {
        //adjustDisttribution();
        double sum = 0;
        for (int i = 0; i < distribution().size(); i++) {
            if (Model::DATA_COLLECTOR->current_TF_by_therapy()[therapy_list()[i]->id()] <= 0) {
                distribution()[i] = 1.0 / 0.000000001;
            } else {
                distribution()[i] = 1.0 / Model::DATA_COLLECTOR->current_TF_by_therapy()[therapy_list()[i]->id()];
            }
            sum += distribution()[i];
        }

        for (int i = 0; i < distribution().size(); i++) {
            distribution()[i] = distribution()[i] / sum;
        }
    }
}

