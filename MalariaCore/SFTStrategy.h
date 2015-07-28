/* 
 * File:   SFTStrategy.h
 * Author: nguyentran
 *
 * Created on June 3, 2013, 8:00 PM
 */

#ifndef SFTSTRATEGY_H
#define	SFTSTRATEGY_H

#include "PropertyMacro.h"
#include "Strategy.h"

class SFTStrategy : public Strategy {
    DISALLOW_COPY_AND_ASSIGN_(SFTStrategy)

public:
    SFTStrategy();
    //    SFTStrategy(const SFTStrategy& orig);
    virtual ~SFTStrategy();

    virtual bool is_strategy(const std::string& sName);

    virtual void switch_therapy();

    virtual Therapy* get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;

    virtual void check_and_switch_therapy();
private:

};

#endif	/* SFTSTRATEGY_H */

