//
// Created by Nguyen Tran on 1/28/2018.
//

#ifndef SPATIAL_SPATIALMODELBUILDER_H
#define SPATIAL_SPATIALMODELBUILDER_H

#include "../PropertyMacro.h"
#include "SpatialModel.h"

namespace Spatial {
    class SpatialModelBuilder {
        DISALLOW_COPY_AND_ASSIGN_(SpatialModelBuilder)
    public:
        SpatialModelBuilder();

        virtual ~SpatialModelBuilder();

        static SpatialModel *Build(const std::string &name);

    };
}

#endif //SPATIAL_SPATIALMODELBUILDER_H
