//
// Created by Nguyen Tran on 1/25/2018.
//

#ifndef SPATIAL_LOCATION_H
#define SPATIAL_LOCATION_H

#include "../PropertyMacro.h"
#include "Coordinate.h"
#include <memory>

namespace Spatial {

    /*!
     *  Location is the smallest entity in the spatial structure.
     *  Location could be district, province, or zone depends on the availability of the data
     */

    class Location {
    DISALLOW_COPY_AND_ASSIGN_(Location)

    public:
        int id;
        int populationSize;
        float beta;
        std::unique_ptr<Coordinate> coordinate;

    public:
        Location(int id = 0, int populationSize = 0, float beta = 0, float latitude=0, float longitutde=0);

        virtual ~Location();
    };
}


#endif //SPATIAL_LOCATION_H
