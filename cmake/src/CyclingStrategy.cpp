/* 
 * File:   CyclingStrategy.cpp
 * Author: nguyentran
 * 
 * Created on June 4, 2013, 11:10 AM
 */

#include "CyclingStrategy.h"
#include "Model.h"
#include "Config.h"
#include "ModelDataCollector.h"
#include <sstream>
#include "IStrategy.h"
#include "Therapy.h"

CyclingStrategy::CyclingStrategy() : index_(0), cycling_time_(0) {
}

CyclingStrategy::CyclingStrategy(const CyclingStrategy& orig) {
}

CyclingStrategy::~CyclingStrategy() {
}

std::vector<Therapy*>& CyclingStrategy::get_therapy_list() {
    return therapy_list_;
}

void CyclingStrategy::add_therapy(Therapy* therapy) {
    therapy_list_.push_back(therapy);
}

bool CyclingStrategy::is_strategy(const std::string& sName) {
    return ("CyclingStrategy" == sName);
}

void CyclingStrategy::switch_therapy() {
    //    std::cout << "Switch from: " << index_ << "\t - to: " << index_ + 1;
    index_++;
    index_ %= therapy_list().size();
    Model::DATA_COLLECTOR->update_UTL_vector();
}

Therapy* CyclingStrategy::get_therapy() {

    //int index = ((Global::scheduler->currentTime - Global::startTreatmentDay) / circleTime) % therapyList.size();
    return therapy_list()[index_];
}

std::string CyclingStrategy::to_string() const {
    std::stringstream sstm;
    sstm << IStrategy::id << "-" << IStrategy::name << "-";
    for (int i = 0; i < therapy_list_.size() - 1; i++) {
        sstm << therapy_list_[i]->id() << ",";
    }
    sstm << therapy_list_[therapy_list_.size() - 1]->id();
    return sstm.str();
}

IStrategy::StrategyType CyclingStrategy::get_type() const {
    return IStrategy::Cycling;
}

void CyclingStrategy::update_end_of_time_step() {

    if (Model::SCHEDULER->current_time() > Model::CONFIG->start_treatment_day()) {
        if (((Model::SCHEDULER->current_time() - Model::CONFIG->start_treatment_day()) % cycling_time_) == 0) {
            switch_therapy();
        }
    }

}