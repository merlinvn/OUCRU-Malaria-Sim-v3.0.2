#ifndef SPATIALSTRUCTURE_H
#define	SPATIALSTRUCTURE_H
#include <string>
#include <vector>
#include "PropertyMacro.h"
#include "Config.h"

class SpatialStructure {
public:
    enum SpatialStructureType {
        GeneralGravity = 0,
        MMC_Zambia = 1,
        Barabasi = 2,
        Wesolowski = 3
    };

    DISALLOW_COPY_AND_ASSIGN_(SpatialStructure)
    POINTER_PROPERTY(Config, config)
    VIRTUAL_PROPERTY_REF(int, test)

public:
    SpatialStructure();
    //    Strategy(const Strategy& orig);
    virtual ~SpatialStructure();
    
    virtual std::string to_string() const = 0;
    
    virtual int to_int() const = 0;
    
    virtual std::vector<double> get_v_relative_outmovement_to_destination(const int &from_location, const std::vector<double> &relative_distance_vector, const std::vector<double> &v_original_pop_size_by_location);

private:

};

#endif	/* STRATEGY_H */