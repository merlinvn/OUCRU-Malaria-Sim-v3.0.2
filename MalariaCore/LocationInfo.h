/* 
 * File:   LocationInfo.h
 * Author: giangddh
 *
 * Created on May 1, 2017, 6:43 PM
 */

#ifndef LOCATIONINFO_H
#define	LOCATIONINFO_H

#include "TypeDef.h"
#include "PropertyMacro.h"
#include <boost/dynamic_bitset.hpp>

class LocationInfo {

    DISALLOW_COPY_AND_ASSIGN_(LocationInfo)
    VIRTUAL_PROPERTY_REF(int, id)
    VIRTUAL_PROPERTY_REF(int, pop_size)
    VIRTUAL_PROPERTY_REF(DoubleVector, coordinates)
    VIRTUAL_PROPERTY_REF(double, beta)
    VIRTUAL_PROPERTY_REF(DoubleVector, pop_proportion_by_districts)
    VIRTUAL_PROPERTY_REF(DoubleVector, beta_by_districts)
    VIRTUAL_PROPERTY_REF(DoubleVector2, coordinates_by_districts)
            
public:
    LocationInfo();
    virtual ~LocationInfo();
    
};

#endif	/* LOCATIONINFO_H */

