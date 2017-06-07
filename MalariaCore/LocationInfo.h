/* 
 * File:   LocationInfo.h
 * Author: giangddh
 *
 * Created on May 1, 2017, 6:43 PM
 */

#ifndef LOCATIONINFO_H
#define LOCATIONINFO_H

#include "TypeDef.h"
#include "PropertyMacro.h"
#include <math.h>

class Vector2D {
public:
    float x;
    float y;

    Vector2D(const float &_x = 0, const float &_y = 0) : x(_x), y(_y) {
    }

    static double get_distance_in_Km_from_LatLon(const Vector2D &from, const Vector2D &to) {
        // using Haversine
        double p = M_PI / 180;
        int R = 6371; // Radius of the Earth in km
        double dLat = p * (from.x - to.x);
        double dLon = p * (from.y - to.y);
        double a = sin(dLat / 2) * sin(dLat / 2) + cos(from.x * p) * cos(to.x * p) * sin(dLon / 2) * sin(dLon / 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        double result = R * c;

        return result;
    }

    static double get_Euclidean_distance(const Vector2D &from, const Vector2D &to) {
        return sqrt((from.x - to.x) * (from.x - to.x) + (from.y - to.y) * (from.y - to.y));
    }
};

class District {

    DISALLOW_COPY_AND_ASSIGN_(District)
public:
    District() {
    };
    int id;
    int province_id;
    int pop_size;
    Vector2D coordinate;
    double beta;
};

typedef std::vector<District *> DistrictPtrVector;

class Province {
    DISALLOW_COPY_AND_ASSIGN_(Province)
public:
    int id;
    int pop_size;
    DistrictPtrVector districts;

    Province() {
    }

    int get_pop_size() {
        int pop_size = 0;
        for (int i = 0; i < districts.size(); i++) {
            pop_size += districts[i]->pop_size;
        }
        return pop_size;
    }
};

typedef std::vector<Province *> ProvincePtrVector;
//TODO: Release memory

class LocationInfo {
    DISALLOW_COPY_AND_ASSIGN_(LocationInfo)
public:
    DistrictPtrVector districts;
    ProvincePtrVector provinces;
    //double distance_unit;

public:

    LocationInfo() {
    };

    virtual ~LocationInfo() {
    };
};

#endif /* LOCATIONINFO_H */
