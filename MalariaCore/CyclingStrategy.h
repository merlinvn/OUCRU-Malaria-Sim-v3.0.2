/* 
 * File:   CyclingStrategy.h
 * Author: nguyentran
 *
 * Created on June 4, 2013, 11:10 AM
 */

#ifndef CYCLINGSTRATEGY_H
#define	CYCLINGSTRATEGY_H

#include "Strategy.h"
#include "PropertyMacro.h"

class CyclingStrategy : public Strategy {
    DISALLOW_COPY_AND_ASSIGN_(CyclingStrategy)
    VIRTUAL_PROPERTY_REF(int, index)
    VIRTUAL_PROPERTY_REF(int, cycling_time)

public:
    CyclingStrategy();
    //    CyclingStrategy(const CyclingStrategy& orig);
    virtual ~CyclingStrategy();

    virtual bool is_strategy(const std::string& sName);

    virtual void switch_therapy();

    virtual Therapy* get_therapy();

    virtual std::string to_string() const;

    virtual int to_int() const;

    virtual void check_and_switch_therapy() ;
private:

};

#endif	/* CYCLINGSTRATEGY_H */

