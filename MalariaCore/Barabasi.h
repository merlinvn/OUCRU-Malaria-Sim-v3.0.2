/* 
 * File:   Barabasi.h
 * Author: giangddh
 *
 * Created on December 16, 2016, 1:31 PM
 */

#ifndef BARABASI_H
#define	BARABASI_H

#include "SpatialStructure.h"
#include "PropertyMacro.h"

class Barabasi : public SpatialStructure {
    DISALLOW_COPY_AND_ASSIGN_(Barabasi)
    VIRTUAL_PROPERTY_REF(int, test)
    
    VIRTUAL_PROPERTY_REF(double, r_g_0)
    VIRTUAL_PROPERTY_REF(double, beta_r)
    VIRTUAL_PROPERTY_REF(double, kappa)
            
public:
    Barabasi();
    
    virtual ~Barabasi();
    
    virtual std::string to_string() const;
    
    virtual int to_int() const;
    
    virtual std::vector<double> get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location);

};

#endif	/* BARABASI_H */

