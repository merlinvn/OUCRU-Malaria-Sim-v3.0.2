#include "LocationInfo.h"
#include <math.h>
#include <sys/types.h>
#include "Model.h"
#include "Config.h"
#include "Random.h"

LocationInfo::LocationInfo() : id_(0), pop_size_(0), coordinates_(), beta_(0), pop_proportion_by_districts_(), beta_by_districts_(), coordinates_by_districts_() {
    
}

LocationInfo::LocationInfo(const LocationInfo& orig) {
    
}

LocationInfo::~LocationInfo() {
    
}


