/* 
 * File:   ParasiteDatabase.cpp
 * Author: Merlin
 * 
 * Created on June 20, 2013, 1:53 AM
 */

#include "ParasiteDatabase.h"
#include "Genotype.h"
#include "boost/foreach.hpp"
#include "Model.h"
#include "Config.h"
#include <math.h>

ParasiteDatabase::ParasiteDatabase() : genotype_db_() {
}

ParasiteDatabase::ParasiteDatabase(const ParasiteDatabase &orig) {
}

ParasiteDatabase::~ParasiteDatabase() {

    BOOST_FOREACH(GenotypePtrMap::value_type & i, genotype_db_) {
                    delete i.second;
                }
    genotype_db_.clear();
}

void ParasiteDatabase::add(Genotype *genotype) {
    if (genotype_db_.find(genotype->genotype_id()) != genotype_db_.end()) {
        delete genotype_db_[genotype->genotype_id()];
    }
    genotype_db_[genotype->genotype_id()] = genotype;
}

Genotype *ParasiteDatabase::get(const int &id) {
    return genotype_db_.at(id);
}

void ParasiteDatabase::initialize_mating_matrix() { // TODO:single t in mating
    int size = genotype_db_.size();
    mating_matrix_ = MatingMatrix(size, std::vector<std::vector<double> >(size, std::vector<double>()));

    for (int m = 0; m < size; m++) {
        for (int f = 0; f < size; f++) {
            mating_matrix_[m][f] = generate_offspring_parasite_density(genotype_db_[m]->resistance_bit_string(),
                                                                       genotype_db_[f]->resistance_bit_string());
        }
    }

}

std::vector<double> ParasiteDatabase::generate_offspring_parasite_density(const boost::dynamic_bitset<> &m,
                                                                          const boost::dynamic_bitset<> &f) {
    std::vector<boost::dynamic_bitset<> > results;
    //add first one
    boost::dynamic_bitset<> ge(m.size(), 0ul);
    results.push_back(ge);


    for (int i = 0; i < m.size(); i++) {
        if (m[i] == f[i]) {

            int old_size = results.size();
            for (int j = 0; j < old_size; j++) {
                results.push_back(results[j]);
                results[j][i] = f[i];
                results[results.size() - 1][i] = f[i];
            }
        } else {
            int old_size = results.size();
            for (int j = 0; j < old_size; j++) {
                results.push_back(results[j]);
                results[j][i] = 0;
                results[results.size() - 1][i] = 1;
            }
        }
    }

    //    std::map<int, int > result_map;
    std::vector<double> recombination_parasite_density(pow(2, m.size()), 0);

    BOOST_FOREACH(boost::dynamic_bitset<> &ge_i, results) {
                    //        std::cout << ge_i << std::endl;
                    recombination_parasite_density[ge_i.to_ulong()] += 1;
                }

    for (int i = 0; i < recombination_parasite_density.size(); i++) {
        if (recombination_parasite_density[i] != 0) {
            recombination_parasite_density[i] /= pow(2, m.size());
        }
//        std::cout << m << "-" << f << "-" << i << " - " << recombination_parasite_density[i] << std::endl;
    }
    return recombination_parasite_density;
}