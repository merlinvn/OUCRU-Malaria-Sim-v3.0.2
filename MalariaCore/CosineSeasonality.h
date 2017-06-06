/* 
 * File:   CosineSeasonality.h
 * Author: giangddh
 *
 * Created on June 2, 2017, 4:17 PM
 */

#ifndef COSINESEASONALITY_H
#define	COSINESEASONALITY_H

#include "SeasonalStructure.h"
#include "PropertyMacro.h"

class CosineSeasonality : public SeasonalStructure {
    DISALLOW_COPY_AND_ASSIGN_(CosineSeasonality)
    VIRTUAL_PROPERTY_REF(int, test)
    VIRTUAL_PROPERTY_REF(double, peak)
    VIRTUAL_PROPERTY_REF(double, trough)
    VIRTUAL_PROPERTY_REF(int, phi_upper)
    VIRTUAL_PROPERTY_REF(int, phi_lower)
            
public:
    CosineSeasonality();
    
    virtual ~CosineSeasonality();
    
    virtual std::string to_string() const;
    
    virtual int to_int() const;
    
    virtual double get_seasonality();


};

#endif	/* COSINESEASONALITY_H */

