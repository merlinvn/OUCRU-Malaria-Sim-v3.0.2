/* 
 * File:   DrugType.h
 * Author: nguyentran
 *
 * Created on June 3, 2013, 10:59 AM
 */

#ifndef DRUGTYPE_H
#define	DRUGTYPE_H
#include "TypeDef.h"
#include "PropertyMacro.h"
#include <boost/dynamic_bitset.hpp>

class DrugType {
    DISALLOW_COPY_AND_ASSIGN_(DrugType)
    VIRTUAL_PROPERTY_REF(int, id)
    VIRTUAL_PROPERTY_REF(boost::dynamic_bitset<>, loci_that_confer_resistance)
    VIRTUAL_PROPERTY_REF(bool, artermisinin_derivative)
    VIRTUAL_PROPERTY_REF(double, drug_half_life)
    VIRTUAL_PROPERTY_REF(double, resistance_cost_multiple_infection)
//    VIRTUAL_PROPERTY_REF(double, n)
//    VIRTUAL_PROPERTY_REF(double, EC50)
    VIRTUAL_PROPERTY_REF(double, EC50_power_n)
    VIRTUAL_PROPERTY_REF(double, maximum_parasite_killing_rate)
    
    VIRTUAL_PROPERTY_REF(DoubleVector, age_group_specific_drug_concentration_sd);
    
    VIRTUAL_PROPERTY_REF(double, p_mutation)
    VIRTUAL_PROPERTY_REF(double, k)
    VIRTUAL_PROPERTY_REF(double, cut_off_percent)
    

public:
    DrugType(int length);
    //    DrugType(const DrugType& orig);
    virtual ~DrugType();

    void reset(int length);
    
    void set_resistance_position(int pos);
    
    virtual double get_parasite_killing_rate_by_concentration(const double &concentration);    
    
    virtual double n();
    virtual void set_n(const double& n);
    
    double EC50();
    void set_EC50(const double& EC50);
    
    int get_total_duration_of_drug_activity(int dosing_days);
    
    bool is_artemisinin();    
       
private:
    double n_;
    double EC50_;
};

#endif	/* DRUGTYPE_H */

