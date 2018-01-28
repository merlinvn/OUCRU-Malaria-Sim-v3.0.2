//
// Created by Nguyen Tran on 1/28/2018.
//

#include "SpatialModelBuilder.h"
#include "GeneralGravitySM.h"

namespace Spatial {
    SpatialModelBuilder::SpatialModelBuilder() = default;

    SpatialModelBuilder::~SpatialModelBuilder() = default;

    SpatialModel *SpatialModelBuilder::Build(const std::string &name) {
        return new GeneralGravitySM();
    }

}