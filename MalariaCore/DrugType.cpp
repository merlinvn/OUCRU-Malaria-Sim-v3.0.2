/* 
 * File:   DrugType.cpp
 * Author: nguyentran
 * 
 * Created on June 3, 2013, 10:59 AM
 */

#include "DrugType.h"
#include <math.h>
#include <sys/types.h>
#include "IntGenotype.h"
#include "Drug.h"
#include "Model.h"
#include "Config.h"
#include "Random.h"

#ifndef LOG2_10
#define LOG2_10 3.32192809489
#endif

DrugType::DrugType() : id_(0), n_(1), drug_family_(Other), affecting_loci_() {


}

DrugType::DrugType(const DrugType& orig) {
}

DrugType::~DrugType() {
}

void DrugType::reset(int length) {
    //    gene_expression_.resize(length);
    //    gene_expression_.reset();
}

//void DrugType::set_resistance_position(int pos) {

//
//    gene_expression_.set(pos);
//    mutation_positions_.push_back(pos);
//    //    id_ = gene_expression_.to_ulong();
//
//}
//
//double DrugType::get_parasite_killing_rate_by_concentration(const double& concentration) {
//    double conPowerN = pow(concentration, n_);
//    return maximum_parasite_killing_rate_ * conPowerN / (conPowerN + EC50_power_n_);
//}

double DrugType::get_parasite_killing_rate_by_concentration(const double& concentration, IntGenotype* genotype) {
    double conPowerN = pow(concentration, n_);
    return maximum_parasite_killing_rate_ * conPowerN / (conPowerN + Model::CONFIG->EC50_power_n_table()[genotype->genotype_id()][id_]);
}

double DrugType::n() {
    return n_;
}

void DrugType::set_n(const double& n) {
    n_ = n;
//    set_EC50_power_n(pow(EC50_, n_));
}
//
//double DrugType::EC50() {
//    return EC50_;
//}

//void DrugType::set_EC50(const double& EC50) {
//    EC50_ = EC50;
//    set_EC50_power_n(pow(EC50_, n_));
//}

int DrugType::get_total_duration_of_drug_activity(const int &dosing_days) {
    //CutOffPercent is 10
    //log2(100.0 / 10.0) = 3.32192809489
    return dosing_days + ceil(drug_half_life_ * LOG2_10);
}

bool DrugType::is_artemisinin() {
    return drug_family_ == Artemisinin;
}

bool DrugType::is_lumefantrine() {
    return drug_family_ == Lumefantrine;
}

int DrugType::select_mutation_locus() {
    double P = Model::RANDOM->random_flat(0.0, 1.0);
    //    double t = 1.0 / affecting_loci_.size();

    return affecting_loci_[(int) floor(P * affecting_loci_.size())];


}