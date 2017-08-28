/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmartMFTStrategy.h
 * Author: Merlin
 *
 * Created on August 25, 2017, 11:57 AM
 */

#ifndef SMARTMFTSTRATEGY_H
#define SMARTMFTSTRATEGY_H

#include "MFTStrategy.h"
#include "PropertyMacro.h"

class SmartMFTStrategy : public MFTStrategy {
    DISALLOW_COPY_AND_ASSIGN_(SmartMFTStrategy)
    VIRTUAL_PROPERTY_REF(int, update_distribution_duration)
public:
    SmartMFTStrategy();
    //        SmartMFTStrategy(const SmartMFTStrategy & orig);
    virtual ~SmartMFTStrategy();


    virtual std::string to_string() const;

    virtual IStrategy::StrategyType get_type() const;

    virtual void update_end_of_time_step();




private:

};

#endif /* SMARTMFTSTRATEGY_H */

