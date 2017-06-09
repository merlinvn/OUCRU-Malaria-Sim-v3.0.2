/* 
 * File:   Config.h
 * Author: nguyentran
 *
 * Created on March 27, 2013, 10:38 AM
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "PropertyMacro.h"
#include <string>
#include <vector>
#include <set>
#include <yaml-cpp/yaml.h>
#include "TypeDef.h"
#include "LocationInfo.h"
#include "DrugDatabase.h"
#include "IntGenotypeDatabase.h"

#include <math.h>
#include <boost/math/constants/constants.hpp>
class Strategy;
class SeasonalStructure;
class SpatialStructure;
class Therapy;
class Model;
const double PI = boost::math::constants::pi<double>();

typedef std::map<int, Therapy *> TherapyPtrMap;
typedef std::map<int, Strategy *> StrategyPtrMap;
typedef std::map<int, SeasonalStructure *> SeasonalStructurePtrMap;
typedef std::map<int, SpatialStructure *> SpatialStructurePtrMap;

class Config {
    DISALLOW_COPY_AND_ASSIGN_(Config)

    POINTER_PROPERTY(Model, model)

    VIRTUAL_PROPERTY_REF(int, total_time)
    VIRTUAL_PROPERTY_REF(int, start_treatment_day)
    VIRTUAL_PROPERTY_REF(int, start_collect_data_day)

    VIRTUAL_PROPERTY_REF(double, p_treatment)

    VIRTUAL_PROPERTY_REF(int, number_of_locations)
    VIRTUAL_PROPERTY_REF(IntVector2, low_transmission_locations_index)
    VIRTUAL_PROPERTY_REF(IntVector2, high_transmission_locations_index)
    VIRTUAL_PROPERTY_REF(int, number_of_provinces)
    VIRTUAL_PROPERTY_REF(int, number_of_age_classes)
    VIRTUAL_PROPERTY_REF(int, number_of_parasite_types)
    VIRTUAL_PROPERTY_REF(DoubleVector2, fake_efficacy_table)
    VIRTUAL_PROPERTY_REF(DoubleVector2, EC50_power_n_table)

    VIRTUAL_PROPERTY_REF(int, using_coordinate)

    POINTER_PROPERTY(LocationInfo, location_db)

    VIRTUAL_PROPERTY_REF(DoubleVector2, coordinates_by_location)
    VIRTUAL_PROPERTY_REF(DoubleVector2, v_distance_by_location)

    VIRTUAL_PROPERTY_REF(std::vector<double>, beta)
    VIRTUAL_PROPERTY_REF(Seasonality, seasonal_beta)
    VIRTUAL_PROPERTY_REF(double, mean_beta_lognormal)

    VIRTUAL_PROPERTY_REF(double, p_infection_from_an_infectious_bite)

    VIRTUAL_PROPERTY_REF(IntVector, age_structure)
    VIRTUAL_PROPERTY_REF(IntVector, initial_age_structure)

    VIRTUAL_PROPERTY_REF(IntVector, population_size_by_location)

    VIRTUAL_PROPERTY_REF(DoubleVector2, age_distribution_by_location)

    VIRTUAL_PROPERTY_REF(double, birth_rate)
    VIRTUAL_PROPERTY_REF(DoubleVector, death_rate_by_age);

    VIRTUAL_PROPERTY_REF(int, number_of_tracking_days);

    VIRTUAL_PROPERTY_REF(DoubleVector, mortality_when_treatment_fail_by_age_class);

    VIRTUAL_PROPERTY_REF(ParasiteDensityLevel, log_parasite_density_level);

    VIRTUAL_PROPERTY_REF(ImmuneSystemInformation, immune_system_information);

    VIRTUAL_PROPERTY_REF(RelativeBittingInformation, relative_bitting_information);
    VIRTUAL_PROPERTY_REF(RelativeInfectivity, relative_infectivity);

    POINTER_PROPERTY(Strategy, strategy);
    POINTER_PROPERTY(SeasonalStructure, seasonal_structure);
    POINTER_PROPERTY(SpatialStructure, spatial_structure);
    POINTER_PROPERTY(DrugDatabase, drug_db);
    POINTER_PROPERTY(IntGenotypeDatabase, genotype_db);
    VIRTUAL_PROPERTY_REF(GenotypeInfo, genotype_info);
    VIRTUAL_PROPERTY_REF(TherapyPtrMap, therapy_db);
    VIRTUAL_PROPERTY_REF(StrategyPtrMap, strategy_db);
    VIRTUAL_PROPERTY_REF(SeasonalStructurePtrMap, seasonal_structure_db);
    VIRTUAL_PROPERTY_REF(SpatialStructurePtrMap, spatial_structure_db);

    VIRTUAL_PROPERTY_REF(std::vector<InitialParasiteInfo>, initial_parasite_info)
    VIRTUAL_PROPERTY_REF(std::vector<ImportationParasiteInfo>, importation_parasite_info)
    VIRTUAL_PROPERTY_REF(std::vector<ImportationParasitePeriodicallyInfo>, importation_parasite_periodically_info)

    VIRTUAL_PROPERTY_REF(int, days_to_clinical_under_five);
    VIRTUAL_PROPERTY_REF(int, days_to_clinical_over_five);
    VIRTUAL_PROPERTY_REF(int, days_mature_gametocyte_under_five);
    VIRTUAL_PROPERTY_REF(int, days_mature_gametocyte_over_five);

    VIRTUAL_PROPERTY_REF(double, p_compliance);
    VIRTUAL_PROPERTY_REF(int, min_dosing_days);

    VIRTUAL_PROPERTY_REF(double, gametocyte_level_under_artemisinin_action);
    VIRTUAL_PROPERTY_REF(double, gametocyte_level_full);

    VIRTUAL_PROPERTY_REF(double, p_relapse);
    VIRTUAL_PROPERTY_REF(int, relapse_duration);

    VIRTUAL_PROPERTY_REF(bool, allow_new_coinfection_to_cause_symtoms);
    VIRTUAL_PROPERTY_REF(int, update_frequency);
    VIRTUAL_PROPERTY_REF(int, report_frequency);

    VIRTUAL_PROPERTY_REF(RelativeMovingInformation, spatial_information);
    VIRTUAL_PROPERTY_REF(ExternalPopulationInformation, spatial_external_population_information);

    VIRTUAL_PROPERTY_REF(double, TF_rate)

    VIRTUAL_PROPERTY_REF(TMEInfo, tme_info)
    POINTER_PROPERTY(Strategy, tme_strategy);
    VIRTUAL_PROPERTY_REF(double, modified_mutation_factor)
    VIRTUAL_PROPERTY_REF(double, modified_drug_half_life)

    VIRTUAL_PROPERTY_REF(bool, using_free_recombination)
    VIRTUAL_PROPERTY_REF(int, tf_testing_day)
    VIRTUAL_PROPERTY_REF(int, tf_window_size)
    VIRTUAL_PROPERTY_REF(bool, using_age_dependent_bitting_level)
    VIRTUAL_PROPERTY_REF(bool, using_variable_probability_infectious_bites_cause_infection)
    VIRTUAL_PROPERTY_REF(double, fraction_mosquitoes_interrupted_feeding)

    VIRTUAL_PROPERTY_REF(int, number_of_column_in_grid)
    VIRTUAL_PROPERTY_REF(double, grid_unit_in_km)

    VIRTUAL_PROPERTY_REF(int, non_artemisinin_switching_day)
    VIRTUAL_PROPERTY_REF(int, non_art_therapy_id)
    VIRTUAL_PROPERTY_REF(double, fraction_non_art_replacement)

    VIRTUAL_PROPERTY_REF(double, modified_daily_cost_of_resistance)
    VIRTUAL_PROPERTY_REF(double, modified_mutation_probability)

public:
    Config(Model *model = NULL);
    virtual ~Config();

    void read_from_file(const std::string &config_file_name = "config.yml");
    void read_from_file_after_overriding_parameters(const std::string &config_file_name = "config.yml");

    void build_location_db(const YAML::Node &config);
    void read_location_db_using_normal_info(const YAML::Node &config);
    void read_location_db_using_coordinate_info(const YAML::Node &config);

    void read_immune_system_information(const YAML::Node &config);
    void read_parasite_density_level(const YAML::Node &config);
    void read_strategy_therapy_and_drug_information(const YAML::Node &config);
    void read_relative_biting_rate_info(const YAML::Node &config);
    void calculate_relative_biting_density();
    void read_seasonal_info(const YAML::Node &config);
    void read_spatial_info(const YAML::Node &config);
    void read_spatial_external_population_info(const YAML::Node &config);

    void read_initial_parasite_info(const YAML::Node &config);
    void read_importation_parasite_info(const YAML::Node &config);
    void read_importation_parasite_periodically_info(const YAML::Node &config);

    void read_relative_infectivity_info(const YAML::Node &config);

    Strategy *read_strategy(const YAML::Node &config, const YAML::Node &n, const std::string &strategy_name);
    Therapy *read_therapy(const YAML::Node &config, const int &therapy_id);

    DrugType *read_drugtype(const YAML::Node &config, const int &drug_id);

    void override_parameters(const std::string &override_file, const int &pos);
    void override_1_parameter(const std::string &parameter_name, const std::string &parameter_value);

    void build_drug_db(const YAML::Node &config);
    void build_parasite_db();
    void build_drug_and_parasite_db(const YAML::Node &config);
    void read_genotype_info(const YAML::Node &config);

    double seasonality(const int &current_time, const double &amplitude, const double &phi_upper, const double &phi_lower) {
        return (((current_time % 365) > (365 / 2))) ? amplitude * (cos(2 * PI * (current_time + phi_upper) / 365) + 2) : (cos(2 * PI * (current_time + phi_lower) / 365) + 2);
        //        return amplitude * cos(2 * PI * (current_time + phi) / 365) + 2;
    };

    SeasonalStructure *read_seasonal_structure(const YAML::Node &config, const YAML::Node &n, const std::string &structure_name);
    SpatialStructure *read_spatial_structure(const YAML::Node &config, const YAML::Node &n, const std::string &structure_name);

    void evaluate_next_strategy(int sim_id);
    void fix_pop_size_and_beta(IntVector pop_size, std::vector<double> beta);

private:
};

#endif /* CONFIG_H */
