/* 
 * File:   Strategy.h
 * Author: nguyentran
 *
 * Created on June 3, 2013, 7:50 PM
 */

#ifndef STRATEGY_H
#define    STRATEGY_H

#include <string>
#include <vector>
#include "PropertyMacro.h"
#include "Config.h"

class Therapy;

class Strategy {
public:
    enum StrategyType {
        SFT = 0,
        Cycling = 1,
        MFT = 2,
        AdaptiveCycling = 3
    };

DISALLOW_COPY_AND_ASSIGN_(Strategy)

VIRTUAL_PROPERTY_REF(std::vector<Therapy *>, therapy_list)

POINTER_PROPERTY(Config, config)

public:
    Strategy();

    //    Strategy(const Strategy& orig);
    virtual ~Strategy();

    //
    //    std::vector<Therapy*> therapyList;
    //    std::vector<DrugType*> drugTypeList;

    void add_therapy(Therapy *therapy);

    virtual bool is_strategy(const std::string &sName) = 0;

    virtual void switch_therapy() = 0;

    virtual Therapy *get_therapy() = 0;

    virtual std::string to_string() const = 0;

    virtual int to_int() const = 0;

    virtual void check_and_switch_therapy() = 0;

private:

};

#endif	/* STRATEGY_H */

