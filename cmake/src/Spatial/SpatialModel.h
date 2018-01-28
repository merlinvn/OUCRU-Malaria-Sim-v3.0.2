//
// Created by Nguyen Tran on 1/28/2018.
//

#ifndef SPATIAL_SPATIALMODEL_H
#define SPATIAL_SPATIALMODEL_H


#include "../PropertyMacro.h"
#include "../TypeDef.h"

namespace Spatial {
    class SpatialModel {
    DISALLOW_COPY_AND_ASSIGN_(SpatialModel)

    public:
        SpatialModel();

        virtual ~SpatialModel();

        virtual DoubleVector get_v_relative_outmovement_to_destination(const int &from_location,
                                                                       const DoubleVector &relative_distance_vector,
                                                                       const IntVector &v_original_pop_size_by_location) const = 0;;

    };
}

#endif //SPATIAL_SPATIALMODEL_H
