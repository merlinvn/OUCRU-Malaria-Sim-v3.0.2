/* 
 * File:   SpatialMFTStrategy.h
 * Author: giangddh
 *
 * Created on November 25, 2016, 4:04 PM
 */

#ifndef SPATIALMFTSTRATEGY_H
#define	SPATIALMFTSTRATEGY_H

#include "Strategy.h"
#include "PropertyMacro.h"

class Random;

class SpatialMFTStrategy : public Strategy {
    DISALLOW_COPY_AND_ASSIGN_(SpatialMFTStrategy)
    VIRTUAL_PROPERTY_REF(std::vector<double>, distribution)
    VIRTUAL_PROPERTY_REF(int, day_until_next_redraw_random_for_changing_drug)
    POINTER_PROPERTY(Random, random)
    
    VIRTUAL_PROPERTY_REF(std::vector<double>, therapy_by_location)
            
public:
    SpatialMFTStrategy();
    
    virtual ~SpatialMFTStrategy();
    
    virtual bool is_strategy(const std::string& sName);

    virtual void switch_therapy();

    virtual Therapy* get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;
    
    virtual void check_and_switch_therapy() ;
    
    void draw_random_location_for_assigning_therapy();

private:

};

#endif	/* SPATIALMFTSTRATEGY_H */

