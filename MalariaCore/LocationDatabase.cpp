#include <boost/foreach.hpp>

#include "LocationDatabase.h"

LocationDatabase::LocationDatabase() : location_db_() {
}

LocationDatabase::LocationDatabase(const LocationDatabase& orig) {
}

LocationDatabase::~LocationDatabase() {

    BOOST_FOREACH(LocationInfoPtrMap::value_type &i, location_db_) {
        delete i.second;
    }
    location_db_.clear();
}

void LocationDatabase::add(LocationInfo* loc_info) {
    location_db_[loc_info->id()] = loc_info;
}

LocationInfo* LocationDatabase::get(const int& id) {
    return location_db_.at(id);
}
