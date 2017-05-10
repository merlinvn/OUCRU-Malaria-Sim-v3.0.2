/* 
 * File:   GeneralGravity.h
 * Author: giangddh
 *
 * Created on December 14, 2016, 5:32 PM
 */

#ifndef GENERALGRAVITY_H
#define	GENERALGRAVITY_H

#include "SpatialStructure.h"
#include "PropertyMacro.h"

class GeneralGravity : public SpatialStructure {
    DISALLOW_COPY_AND_ASSIGN_(GeneralGravity)
    VIRTUAL_PROPERTY_REF(int, test)
            
public:
    GeneralGravity();
    
    virtual ~GeneralGravity();
    
    virtual std::string to_string() const;
    
    virtual int to_int() const;
    
    virtual std::vector<double> get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location);

};

#endif	/* GENERALGRAVITY_H */

