/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ACTIncreaseStrategy.h
 * Author: Merlin
 *
 * Created on April 26, 2017, 11:20 AM
 */

#ifndef ACTINCREASESTRATEGY_H
#define ACTINCREASESTRATEGY_H


#include "Strategy.h"
#include "PropertyMacro.h"

class Random;

class ACTIncreaseStrategy : public Strategy {
    DISALLOW_COPY_AND_ASSIGN_(ACTIncreaseStrategy)
    VIRTUAL_PROPERTY_REF(std::vector<double>, distribution)
    VIRTUAL_PROPERTY_REF(std::vector<double>, start_distribution)
    VIRTUAL_PROPERTY_REF(std::vector<double>, end_distribution)
    POINTER_PROPERTY(Random, random)
public:
    ACTIncreaseStrategy();
    //    MFTStrategy(const MFTStrategy& orig);
    virtual ~ACTIncreaseStrategy();

    virtual bool is_strategy(const std::string& sName);

    virtual void switch_therapy();

    virtual Therapy* get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;

    virtual void check_and_switch_therapy();
    
    void adjustDisttribution(int time, int totaltime);

private:

};

#endif /* ACTINCREASESTRATEGY_H */

