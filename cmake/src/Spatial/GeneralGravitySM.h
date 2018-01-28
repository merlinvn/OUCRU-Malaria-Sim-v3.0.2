//
// Created by Nguyen Tran on 1/29/2018.
//

#ifndef POMS_GENERALGRAVITYSM_H
#define POMS_GENERALGRAVITYSM_H

#include "../PropertyMacro.h"
#include "SpatialModel.h"

namespace Spatial {

    class GeneralGravitySM : public SpatialModel {
    DISALLOW_COPY_AND_ASSIGN_(GeneralGravitySM)

    public:
        GeneralGravitySM();

        virtual ~GeneralGravitySM();

        DoubleVector get_v_relative_outmovement_to_destination(const int &from_location,
                                                               const DoubleVector &relative_distance_vector,
                                                               const IntVector &v_original_pop_size_by_location) const override;
    };
}

#endif //POMS_GENERALGRAVITYSM_H