/* 
 * File:   MFTStrategy.h
 * Author: nguyentran
 *
 * Created on June 4, 2013, 11:09 AM
 */

#ifndef MFTSTRATEGY_H
#define	MFTSTRATEGY_H

#include "Strategy.h"
#include "PropertyMacro.h"

class Random;

class MFTStrategy : public Strategy {
    DISALLOW_COPY_AND_ASSIGN_(MFTStrategy)
    VIRTUAL_PROPERTY_REF(std::vector<double>, distribution)
    POINTER_PROPERTY(Random, random)
public:
    MFTStrategy();
    //    MFTStrategy(const MFTStrategy& orig);
    virtual ~MFTStrategy();

    virtual bool is_strategy(const std::string& sName);

    virtual void switch_therapy();

    virtual Therapy* get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;
    
    virtual void check_and_switch_therapy() ;
    
private:

};

#endif	/* MFTSTRATEGY_H */

