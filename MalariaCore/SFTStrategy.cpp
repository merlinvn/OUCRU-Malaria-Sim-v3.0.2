/* 
 * File:   SFTStrategy.cpp
 * Author: nguyentran
 * 
 * Created on June 3, 2013, 8:00 PM
 */

#include <assert.h>
#include "SFTStrategy.h"

SFTStrategy::SFTStrategy() {
}

SFTStrategy::SFTStrategy(const SFTStrategy& orig) {
}

SFTStrategy::~SFTStrategy() {
}

bool SFTStrategy::is_strategy(const std::string& sName) {
    return ("SFTStrategy" == sName);
}

void SFTStrategy::switch_therapy(){
    assert(false);
}

Therapy* SFTStrategy::get_therapy() {
    return therapy_list()[0];
}

std::string SFTStrategy::to_string() const
{
    return "SFTStrategy";
}

int SFTStrategy::to_int() const
{
    //TODO: convert to enum
    return Strategy::SFT;
}

void SFTStrategy::check_and_switch_therapy() {
    //do nothing here
}