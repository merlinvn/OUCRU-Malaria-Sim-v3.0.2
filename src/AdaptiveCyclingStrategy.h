/* 
 * File:   AdaptiveCyclingStrategy.h
 * Author: nguyentran
 *
 * Created on June 4, 2013, 11:10 AM
 */

#ifndef ADAPTIVECYCLINGSTRATEGY_H
#define    ADAPTIVECYCLINGSTRATEGY_H

#include "Strategy.h"
#include "PropertyMacro.h"

class AdaptiveCyclingStrategy : public Strategy {
DISALLOW_COPY_AND_ASSIGN_(AdaptiveCyclingStrategy)

VIRTUAL_PROPERTY_REF(int, index)

VIRTUAL_PROPERTY_REF(double, trigger_value)

VIRTUAL_PROPERTY_REF(int, delay_until_actual_trigger)

VIRTUAL_PROPERTY_REF(int, turn_off_days)

VIRTUAL_PROPERTY_REF(int, latest_switch_time)


public:
    AdaptiveCyclingStrategy();

//    AdaptiveCyclingStrategy(const AdaptiveCyclingStrategy& orig);
    virtual ~AdaptiveCyclingStrategy();

    virtual bool is_strategy(const std::string &sName);

    virtual void switch_therapy();

    virtual Therapy *get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;

    virtual void check_and_switch_therapy();

private:

};

#endif	/* ADAPTIVECYCLINGSTRATEGY_H */

