/* 
 * File:   ResistanceTracker.h
 * Author: Merlin
 *
 * Created on September 24, 2013, 10:00 AM
 */

#ifndef RESISTANCETRACKER_H
#define	RESISTANCETRACKER_H
#include "PropertyMacro.h"
#include "TypeDef.h"

class ResistanceTracker {
    DISALLOW_COPY_AND_ASSIGN_(ResistanceTracker)

    PROPERTY_REF(LongVector, parasite_population_count);
    PROPERTY_REF(double, total_resistance_frequency);
    PROPERTY_REF(unsigned long, total);

    PROPERTY_REF(IntVector, single_resistance_ids);
    PROPERTY_REF(IntVector, double_resistance_ids);
    PROPERTY_REF(IntVector, tripple_resistance_ids);
    PROPERTY_REF(IntVector, quadruple_resistance_ids);
    PROPERTY_REF(IntVector, quintuple_resistance_ids);
    PROPERTY_REF(IntVectorPtrVector, total_resistance_ids);
    PROPERTY_REF(int, all_resistance_id);

    PROPERTY_REF(DoubleVector, tracking_values);
    PROPERTY_REF(IntVector, any_single_tracking_time);
    PROPERTY_REF(IntVector, all_single_tracking_time);
    PROPERTY_REF(IntVector, any_double_tracking_time);
    PROPERTY_REF(IntVector, all_double_tracking_time);
    PROPERTY_REF(IntVector, any_triple_tracking_time); 
    PROPERTY_REF(IntVector, all_triple_tracking_time);
    PROPERTY_REF(IntVector, any_quadruple_tracking_time);
    PROPERTY_REF(IntVector, all_quadruple_tracking_time);
    PROPERTY_REF(IntVector, any_quintuple_tracking_time);
    PROPERTY_REF(IntVector, all_quintuple_tracking_time);
    PROPERTY_REF(IntVector, total_tracking_time);
    PROPERTY_REF(IntVector, artemisinin_tracking_time);


    PROPERTY_REF(IntVector, artemisinin_ids);

public:
    ResistanceTracker();
    //    ResistanceTracker(const ResistanceTracker& orig);
    virtual ~ResistanceTracker();

    void initialize();

    void update_resistance_tracker();


    void increase(const int& id);
    void decrease(const int& id);
    void change(const int& from, const int& to);

    double max_fraction_resistance(const IntVector& resitance_ids);
    double min_fraction_resistance(const IntVector& resitance_ids);
    double sum_fraction_resistance(const IntVector& resitance_ids);
    void update_time_value(int& tracking_time, const double& value, const double& check_value);
    void make_resistance_profile(std::vector<int>& vResistanceID, const int& size);
    void make_arterminsinin_resistance_profile(std::vector<int>& vResistanceID);
    
    void calculate_total_resistance_frequency();
private:

};

#endif	/* RESISTANCETRACKER_H */

