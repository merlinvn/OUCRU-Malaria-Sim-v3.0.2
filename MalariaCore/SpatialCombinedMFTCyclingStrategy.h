/* 
 * File:   SpatialCombinedMFTCyclingStrategy.h
 * Author: giangddh
 *
 * Created on November 29, 2016, 2:14 PM
 */

#ifndef SPATIALCOMBINEDMFTCYCLINGSTRATEGY_H
#define	SPATIALCOMBINEDMFTCYCLINGSTRATEGY_H

#include "Strategy.h"
#include "PropertyMacro.h"

class Random;

class SpatialCombinedMFTCyclingStrategy : public Strategy {
    DISALLOW_COPY_AND_ASSIGN_(SpatialCombinedMFTCyclingStrategy)
    VIRTUAL_PROPERTY_REF(int, index)
    VIRTUAL_PROPERTY_REF(int, cycling_time)
            
public:
    SpatialCombinedMFTCyclingStrategy();
    
    virtual ~SpatialCombinedMFTCyclingStrategy();
    
    virtual bool is_strategy(const std::string& sName);

    virtual void switch_therapy();

    virtual Therapy* get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;
    
    virtual void check_and_switch_therapy() ;
    
    virtual void check_and_switch_non_art_therapy();

private:

};

#endif	/* SPATIALCOMBINEDMFTCYCLINGSTRATEGY_H */

