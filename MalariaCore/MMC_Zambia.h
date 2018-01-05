/* 
 * File:   MMC_Zambia.h
 * Author: giangddh
 *
 * Created on December 22, 2016, 3:25 PM
 */

#ifndef MMC_ZAMBIA_H
#define	MMC_ZAMBIA_H

#include "SpatialStructure.h"
#include "PropertyMacro.h"

class MMC_Zambia : public SpatialStructure {
    DISALLOW_COPY_AND_ASSIGN_(MMC_Zambia)
    VIRTUAL_PROPERTY_REF(int, test)
    VIRTUAL_PROPERTY_REF(double, theta)
    VIRTUAL_PROPERTY_REF(double, alpha)
    VIRTUAL_PROPERTY_REF(double, beta)
    VIRTUAL_PROPERTY_REF(double, gamma)
            
public:
    MMC_Zambia();
    
    virtual ~MMC_Zambia();
    
    virtual std::string to_string() const;
    
    virtual int to_int() const;
    
    virtual std::vector<double> get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location);

};

#endif	/* MMC_ZAMBIA_H */

