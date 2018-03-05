//
// Created by Nguyen Tran on 3/5/2018.
//

#include "BFFarmReporter.h"
#include "../Model.h"
#include "../Random.h"
#include "../Config.h"
#include <boost/format.hpp>

BFFarmReporter::BFFarmReporter() {

}

BFFarmReporter::~BFFarmReporter() {

}

void BFFarmReporter::initialize() {

}

void BFFarmReporter::before_run() {
    std::cout << Model::RANDOM->seed() << std::endl;

}

void BFFarmReporter::begin_time_step() {

}

void BFFarmReporter::after_time_step() {

}

void BFFarmReporter::after_run() {
    outout_parameters();


    std::cout << std::endl;
}

void BFFarmReporter::outout_parameters() {
    std::cout << boost::format("%1%\t%2%\t")
                 % Model::RANDOM->seed()
                 % Model::CONFIG->number_of_locations();

}
