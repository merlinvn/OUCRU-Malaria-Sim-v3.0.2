/* 
 * File:   Strategy.cpp
 * Author: nguyentran
 * 
 * Created on June 3, 2013, 7:50 PM
 */

#include "Strategy.h"
#include "Therapy.h"
#include <boost/foreach.hpp>

Strategy::Strategy(): therapy_list_() {
}

Strategy::Strategy(const Strategy& orig) {
}

Strategy::~Strategy() {

//    BOOST_FOREACH(Therapy* therapy, therapy_list_) {
//        delete therapy;
//    }
    
    //therapies are managed by therapy_db_, so no need to delete pointer
    therapy_list_.clear();
}

void Strategy::add_therapy(Therapy* therapy) {
    therapy_list_.push_back(therapy);
}