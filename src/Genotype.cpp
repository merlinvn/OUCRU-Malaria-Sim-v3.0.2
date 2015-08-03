/* 
 * File:   Genotype.cpp
 * Author: nguyentran
 * 
 * Created on May 15, 2013, 1:22 PM
 */



#include <boost/foreach.hpp>
#include "Model.h"
#include "Genotype.h"
#include "DrugDatabase.h"
#include "Therapy.h"
#include "Config.h"

Genotype::Genotype(const int &id, const int &gene_length, DrugDatabase *drug_db) : genotype_id_(id),
                                                                                   relative_fitness_multiple_infection_(
                                                                                           1), drug_db_(drug_db) {
    resistance_bit_string_ = boost::dynamic_bitset<>(gene_length, (unsigned long) id);
    relative_fitness_multiple_infection_ = 1;
    if (drug_db != NULL) {

        BOOST_FOREACH(const DrugTypePtrMap::value_type &pair, drug_db->drug_db()) {
                        DrugType *dt = pair.second;
                        if (resistant_to(dt)) {
                            //            std::cout << resistance_bit_string_ << "-" << dt->resistance_bit_string()<< std::endl;
                            relative_fitness_multiple_infection_ *= (1 - dt->resistance_cost_multiple_infection());
                        }
                    }
    }
    number_of_resistance_position_ = resistance_bit_string_.count();
    //    std::cout << resistance_bit_string_ << "-" << relative_fitness_multiple_infection_ << std::endl;
}

Genotype::Genotype(const Genotype &orig) {
}

Genotype::~Genotype() {
}

bool Genotype::resistant_to(DrugType *dt) {
    //    !((id ^ drugTypeID) & drugTypeID);
    boost::dynamic_bitset<> mask = dt->loci_that_confer_resistance();
    return resistant_to(mask);
}

bool Genotype::resistant_to(Therapy *therapy) {
    boost::dynamic_bitset<> mask = drug_db()->drug_db()[therapy->drug_ids()[0]]->loci_that_confer_resistance();

    BOOST_FOREACH(int id, therapy->drug_ids()) {
                    mask |= drug_db()->drug_db()[id]->loci_that_confer_resistance();
                }

    return resistant_to(mask);
}

bool Genotype::resistant_to(const boost::dynamic_bitset<> &mask) {
    return (((resistance_bit_string_ ^ mask) & mask) == boost::dynamic_bitset<>(resistance_bit_string_.size(), 0ul));
}

Genotype *Genotype::combine_mutation_to(DrugType *dt) {
    boost::dynamic_bitset<> mask = resistance_bit_string_ | dt->loci_that_confer_resistance();
    return Model::CONFIG->parasite_db()->get((int) mask.to_ulong());
}

