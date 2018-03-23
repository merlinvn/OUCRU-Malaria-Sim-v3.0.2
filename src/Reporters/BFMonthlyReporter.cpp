//
// Created by Nguyen Tran on 3/5/2018.
//

#include "BFMonthlyReporter.h"
#include "../Model.h"
#include "../Config.h"
#include "../ModelDataCollector.h"

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
//        std::cout << Model::CONFIG->seasonal_factor_for_beta(Model::SCHEDULER->current_time()) << "\t";
        print_PfPR_0_5_by_location();

        std::cout << "-1111\t";

        print_monthly_incidence_by_location();

        std::cout << std::endl;
    }
}


void BFMonthlyReporter::after_run() {

}

void BFMonthlyReporter::print_PfPR_0_5_by_location() {

    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); ++loc) {
        std::cout << Model::DATA_COLLECTOR->get_blood_slide_prevalence(loc, 0, 5) * 100 << "\t";
    }

}

void BFMonthlyReporter::print_monthly_incidence_by_location() {
    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); ++loc) {
        std::cout << Model::DATA_COLLECTOR->monthly_number_of_treatment_by_location()[loc] << "\t";
    }

    std::cout << "-1111\t";

    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); ++loc) {
        std::cout << Model::DATA_COLLECTOR->monthly_number_of_clinical_episode_by_location()[loc] << "\t";
    }

}
