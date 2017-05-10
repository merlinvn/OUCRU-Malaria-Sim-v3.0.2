/* 
 * File:   CyclingStrategy.cpp
 * Author: nguyentran
 * 
 * Created on June 4, 2013, 11:10 AM
 */

#include "CyclingStrategy.h"
#include "Therapy.h"
#include "Model.h"
#include "ModelDataCollector.h"

CyclingStrategy::CyclingStrategy() : index_(0), cycling_time_(0) {
}

CyclingStrategy::CyclingStrategy(const CyclingStrategy& orig) {
}

CyclingStrategy::~CyclingStrategy() {
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
    return "CyclingStrategy";
}

int CyclingStrategy::to_int() const {
    return Strategy::Cycling;
}

void CyclingStrategy::check_and_switch_therapy() {

    if (Model::SCHEDULER->current_time() > Model::CONFIG->start_treatment_day()) {
        if (((Model::SCHEDULER->current_time() - Model::CONFIG->start_treatment_day()) % cycling_time_) == 0) {

            switch_therapy();
        }
    }

}