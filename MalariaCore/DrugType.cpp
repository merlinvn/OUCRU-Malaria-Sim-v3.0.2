/* 
 * File:   DrugType.cpp
 * Author: nguyentran
 * 
 * Created on June 3, 2013, 10:59 AM
 */

#include "DrugType.h"
#include <math.h>
#include <sys/types.h>

#ifndef LOG2_10
#define LOG2_10 3.32192809489
#endif

DrugType::DrugType(int length) : id_(0), loci_that_confer_resistance_(length, 0ul), artermisinin_derivative_(false), n_(1), EC50_(0) {


}

DrugType::DrugType(const DrugType& orig) {
}

DrugType::~DrugType() {
}

void DrugType::reset(int length) {
    loci_that_confer_resistance_.resize(length);
    loci_that_confer_resistance_.reset();
}

void DrugType::set_resistance_position(int pos) {
    //TODO: throw exception if pos > size

    loci_that_confer_resistance_.set(pos);
    //    id_ = resistance_bit_string_.to_ulong();

}

double DrugType::get_parasite_killing_rate_by_concentration(const double& concentration) {
    double conPowerN = pow(concentration, n_);
    return maximum_parasite_killing_rate_ * conPowerN / (conPowerN + EC50_power_n_);
}

double DrugType::n() {
    return n_;
}

void DrugType::set_n(const double& n) {
    n_ = n;
    set_EC50_power_n(pow(EC50_, n_));
}

double DrugType::EC50() {
    return EC50_;
}

void DrugType::set_EC50(const double& EC50) {
    EC50_ = EC50;
    set_EC50_power_n(pow(EC50_, n_));
}

int DrugType::get_total_duration_of_drug_activity(int dosing_days) {
    //CutOffPercent is 10
    //log2(100.0 / 10.0) = 3.32192809489
    return dosing_days + ceil(drug_half_life_ * LOG2_10);
}

bool DrugType::is_artemisinin() {
    return artermisinin_derivative_;
}