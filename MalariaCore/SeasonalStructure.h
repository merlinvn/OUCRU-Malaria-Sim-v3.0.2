/* 
 * File:   SeasonalStructure.h
 * Author: giangddh
 *
 * Created on June 2, 2017, 4:01 PM
 */

#ifndef SEASONALSTRUCTURE_H
#define	SEASONALSTRUCTURE_H

#include <string>
#include <vector>
#include "PropertyMacro.h"
#include "Config.h"

class SeasonalStructure {
public:
    enum SeasonalStructureType {
        CosineSeasonality = 0,
    };

    DISALLOW_COPY_AND_ASSIGN_(SeasonalStructure)
    POINTER_PROPERTY(Config, config)
    VIRTUAL_PROPERTY_REF(int, test)

public:
    SeasonalStructure();
    //    Strategy(const Strategy& orig);
    virtual ~SeasonalStructure();
    
    virtual std::string to_string() const = 0;
    
    virtual int to_int() const = 0;
    
    virtual double get_seasonality();

private:

};

#endif	/* SEASONALSTRUCTURE_H */

