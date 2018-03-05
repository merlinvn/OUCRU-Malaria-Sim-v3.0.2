//
// Created by Nguyen Tran on 3/5/2018.
//

#include "BFMonthlyReporter.h"
#include "../Model.h"
#include "../Config.h"

BFMonthlyReporter::BFMonthlyReporter() {

}

BFMonthlyReporter::~BFMonthlyReporter() {

}

void BFMonthlyReporter::initialize() {

}

void BFMonthlyReporter::before_run() {

}


void BFMonthlyReporter::begin_time_step() {

}

void BFMonthlyReporter::after_time_step() {
    if (Model::SCHEDULER->current_time() % Model::CONFIG->report_frequency() == 0) {
        std::cout << Model::SCHEDULER->current_time() << "\t";


        std::cout << std::endl;
    }
}


void BFMonthlyReporter::after_run() {

}
