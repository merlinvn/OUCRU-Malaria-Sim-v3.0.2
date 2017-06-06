/* 
 * File:   LocationDatabase.h
 * Author: giangddh
 *
 * Created on April 30, 2017, 12:25 PM
 */

#ifndef LOCATIONDATABASE_H
#define	LOCATIONDATABASE_H

#include "PropertyMacro.h"
#include "LocationInfo.h"
#include <map>

typedef std::map<int, LocationInfo*> LocationInfoPtrMap;

class LocationDatabase {
    DISALLOW_COPY_AND_ASSIGN_(LocationDatabase)
    VIRTUAL_PROPERTY_REF(ProvincePtrVector, provinces)
            
public:
    LocationDatabase();
    virtual ~LocationDatabase();
    
    void add (LocationInfo* location_info);
    LocationInfo* get(const int& id);
    
private:
};

#endif	/* LOCATIONDATABASE_H */

