/* 
 * File:   ParasiteDatabase.h
 * Author: Merlin
 *
 * Created on June 20, 2013, 1:53 AM
 */

#ifndef PARASITEDATABASE_H
#define    PARASITEDATABASE_H

#include "PropertyMacro.h"
#include "TypeDef.h"
#include <boost/dynamic_bitset.hpp>
#include <map>

class Genotype;

typedef std::map<int, Genotype *> GenotypePtrMap;
typedef std::vector<std::vector<std::vector<double> > > MatingMatrix;

class ParasiteDatabase {
DISALLOW_COPY_AND_ASSIGN_(ParasiteDatabase)

VIRTUAL_PROPERTY_REF(GenotypePtrMap, genotype_db);

VIRTUAL_PROPERTY_REF(MatingMatrix, mating_matrix);

public:
    ParasiteDatabase();

    //    ParasiteDatabase(const ParasiteDatabase& orig);
    virtual ~ParasiteDatabase();

    void add(Genotype *genotype);

    Genotype *get(const int &id);

    void initialize_mating_matrix();

    std::vector<double> generate_offspring_parasite_density(const boost::dynamic_bitset<> &m,
                                                            const boost::dynamic_bitset<> &f);

private:

};

#endif	/* PARASITEDATABASE_H */

