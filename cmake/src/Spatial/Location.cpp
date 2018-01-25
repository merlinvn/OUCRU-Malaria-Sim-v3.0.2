//
// Created by Nguyen Tran on 1/25/2018.
//

#include "Location.h"


Spatial::Location::Location(int id, int populationSize, float beta, float latitude, float longitutde) :
        id{id}, populationSize{populationSize}, beta{beta},
        coordinate{std::make_unique<Coordinate>(latitude, longitutde)} {

}

Spatial::Location::~Location() {

}
