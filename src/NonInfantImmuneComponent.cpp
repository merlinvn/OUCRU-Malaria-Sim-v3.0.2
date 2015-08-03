/* 
 * File:   NormalImmuneComponent.cpp
 * Author: nguyentran
 * 
 * Created on May 28, 2013, 11:06 AM
 */

#include "NonInfantImmuneComponent.h"
#include "Model.h"
#include "Config.h"


OBJECTPOOL_IMPL(NonInfantImmuneComponent)

NonInfantImmuneComponent::NonInfantImmuneComponent() : ImmuneComponent() {
}

NonInfantImmuneComponent::NonInfantImmuneComponent(const NonInfantImmuneComponent &orig) {
}

NonInfantImmuneComponent::~NonInfantImmuneComponent() {
}

double NonInfantImmuneComponent::get_acquire_rate(const int &age) const {
    //    return FastImmuneComponent::acquireRate;

    return (age > 80) ? Model::CONFIG->immune_system_information().acquire_rate_by_age[80]
                      : Model::CONFIG->immune_system_information().acquire_rate_by_age[age];

}

double NonInfantImmuneComponent::get_decay_rate(const int &age) const {
    return Model::CONFIG->immune_system_information().decay_rate;
}