/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrategyBuilder.cpp
 * Author: Merlin
 * 
 * Created on August 23, 2017, 11:03 AM
 */

#include "StrategyBuilder.h"
#include "IStrategy.h"
#include "SFTStrategy.h"
#include "Config.h"
#include "Model.h"
#include "CyclingStrategy.h"
#include "AdaptiveCyclingStrategy.h"
#include "MFTStrategy.h"
#include "ACTIncreaseStrategy.h"

StrategyBuilder::StrategyBuilder() {
}

StrategyBuilder::StrategyBuilder(const StrategyBuilder& orig) {
}

StrategyBuilder::~StrategyBuilder() {
}

IStrategy* StrategyBuilder::build(const YAML::Node& ns, const int& strategy_id) {
    IStrategy::StrategyType type = IStrategy::StrategyTypeMap[ns["type"].as<std::string>()];

    switch (type) {
        case IStrategy::SFT:
            return buildSFTStrategy(ns, strategy_id);
        case IStrategy::Cycling:
            return buildCyclingStrategy(ns, strategy_id);
        case IStrategy::AdaptiveCycling:
            return buildAdaptiveCyclingStrategy(ns, strategy_id);
        case IStrategy::MFT:
            return buildMFTStrategy(ns, strategy_id);

        case IStrategy::ACTIncreaseOvertime:
            return buildACTIncreaseStrategy(ns, strategy_id);
        default:
            return NULL;
    }

    return NULL;
}

void StrategyBuilder::add_therapies(const YAML::Node& ns, IStrategy*& result) {
    for (int i = 0; i < ns["therapyID"].size(); i++) {
        result->add_therapy(Model::CONFIG->therapy_db()[ns["therapyID"][i].as<int>()]);
    }
}

void StrategyBuilder::add_distributions(const YAML::Node& ns, DoubleVector& v) {
    for (int i = 0; i < ns.size(); i++) {
        v.push_back(ns[i].as<double>());
    }
}

IStrategy* StrategyBuilder::buildSFTStrategy(const YAML::Node& ns, const int& strategy_id) {
    IStrategy* result = new SFTStrategy();
    result->id = strategy_id;
    result->name = ns["name"].as<std::string>();
    result->add_therapy(Model::CONFIG->therapy_db()[ns["therapyID"].as<int>()]);
    return result;
}

IStrategy* StrategyBuilder::buildCyclingStrategy(const YAML::Node& ns, const int& strategy_id) {
    IStrategy* result = new CyclingStrategy();
    result->id = strategy_id;
    result->name = ns["name"].as<std::string>();

    ((CyclingStrategy*) result)->set_cycling_time(ns["cycling_time"].as<int>());

    for (int i = 0; i < ns["therapyID"].size(); i++) {
        result->add_therapy(Model::CONFIG->therapy_db()[ns["therapyID"][i].as<int>()]);
    }

    return result;
}

IStrategy* StrategyBuilder::buildAdaptiveCyclingStrategy(const YAML::Node& ns, const int& strategy_id) {
    IStrategy* result = new AdaptiveCyclingStrategy();
    result->id = strategy_id;
    result->name = ns["name"].as<std::string>();

    ((AdaptiveCyclingStrategy*) result)->set_trigger_value(ns["trigger_value"].as<double>());
    ((AdaptiveCyclingStrategy*) result)->set_delay_until_actual_trigger(ns["delay_until_actual_trigger"].as<int>());
    ((AdaptiveCyclingStrategy*) result)->set_turn_off_days(ns["turn_off_days"].as<int>());

    add_therapies(ns, result);
    return result;
}

IStrategy* StrategyBuilder::buildMFTStrategy(const YAML::Node& ns, const int& strategy_id) {
    IStrategy* result = new MFTStrategy();
    result->id = strategy_id;
    result->name = ns["name"].as<std::string>();

    add_distributions(ns["distribution"], ((MFTStrategy*) result)->distribution());

    add_therapies(ns, result);
    return result;
}

IStrategy* StrategyBuilder::buildACTIncreaseStrategy(const YAML::Node& ns, const int& strategy_id) {

    IStrategy* result = new ACTIncreaseStrategy();
    result->id = strategy_id;
    result->name = ns["name"].as<std::string>();

    add_distributions(ns["start_distribution"], ((ACTIncreaseStrategy*) result)->start_distribution());
    add_distributions(ns["start_distribution"], ((ACTIncreaseStrategy*) result)->distribution());
    add_distributions(ns["end_distribution"], ((ACTIncreaseStrategy*) result)->end_distribution());

    add_therapies(ns, result);

    return result;
}


