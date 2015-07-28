/* 
 * File:   Genotype.h
 * Author: nguyentran
 *
 * Created on May 15, 2013, 1:22 PM
 */

#ifndef GENOTYPE_H
#define	GENOTYPE_H

#include "TypeDef.h"
#include "PropertyMacro.h"

#include <boost/dynamic_bitset.hpp>
/**
 * This class will have a bit string or gene expression string to represent
 * the genome of the parasite
 * i.e.: 
 * - 000000000 means naive strain 
 * - 000000001 means mutate at the first position
 * - 000000011 means mutate ate the first and second position
 */
class DrugDatabase;
class DrugType;
class Therapy;

class Genotype {
    DISALLOW_COPY_AND_ASSIGN_(Genotype)
    PROPERTY_REF(int, genotype_id);
    PROPERTY_REF(int, number_of_resistance_position);
    PROPERTY_REF(boost::dynamic_bitset<>, resistance_bit_string);
    PROPERTY_REF(double, relative_fitness_multiple_infection);
    POINTER_PROPERTY(DrugDatabase, drug_db )
public:
    Genotype(const int& id = 0, const int& gene_length = 0 , DrugDatabase* drug_db = NULL);
//    Genotype(const Genotype& orig);
    virtual ~Genotype();
    
    bool resistant_to(DrugType* dt); 
    bool resistant_to(const boost::dynamic_bitset<> &mask);
    bool resistant_to(Therapy* therapy);
    
    Genotype* combine_mutation_to(DrugType* dt);
    
//    int number_of_resistance_position();
    
    
    
private:

};

#endif	/* GENOTYPE_H */

