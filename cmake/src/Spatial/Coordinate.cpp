//
// Created by Nguyen Tran on 1/25/2018.
//

#include <math.h>
#include "Coordinate.h"


Spatial::Coordinate::Coordinate(float latitude, float longitude): latitude{latitude}, longitude{longitude} {

}

Spatial::Coordinate::~Coordinate() {

}

double Spatial::Coordinate::calculate_distance_in_km(const Spatial::Coordinate &from, const Spatial::Coordinate &to) {
    // using Haversine
    double p = M_PI / 180;
    int R = 6371; // Radius of the Earth in km
    double dLat = p * (from.latitude - to.latitude);
    double dLon = p * (from.longitude - to.longitude);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(from.latitude * p) * cos(to.latitude * p) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double result = R * c;

    return result;
}
