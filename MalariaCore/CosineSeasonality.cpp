#include "CosineSeasonality.h"
#include "Model.h"
#include "ModelDataCollector.h"

CosineSeasonality::CosineSeasonality() {
    
}

CosineSeasonality::CosineSeasonality(const CosineSeasonality&) {
    
}

CosineSeasonality::~CosineSeasonality() {
    
}

std::string CosineSeasonality::to_string() const {
    return "CosineSeasonality";
}

int CosineSeasonality::to_int() const {
    return SeasonalStructure::CosineSeasonality;
}
double CosineSeasonality::get_seasonality() {
    if (Model::SCHEDULER->current_time() % 365 > (365 / 2)) {
        return ( peak_ * (cos(2 * PI * (Model::SCHEDULER->current_time() + phi_upper_) / 365) + 2) );
    } else {
        return ( trough_ * (cos(2 * PI * (Model::SCHEDULER->current_time() + phi_lower_) / 365) + 2) );
    }
}
