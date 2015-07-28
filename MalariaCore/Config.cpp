/* 
 * File:   Config.cpp
 * Author: nguyentran
 * 
 * Created on March 27, 2013, 10:38 AM
 */

#include "Config.h"
#include <iostream>
#include <boost/foreach.hpp>
#include <gsl/gsl_cdf.h>
#include "SFTStrategy.h"
#include "HelperFunction.h"
#include "Therapy.h"
#include "Strategy.h"
#include "AdaptiveCyclingStrategy.h"
#include "CyclingStrategy.h"
#include "MFTStrategy.h"
#include "Model.h"
#include "Genotype.h"
#include "Random.h"
#include <math.h>
#include <fstream>
#include <boost/algorithm/string.hpp>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        boost::algorithm::trim(item);
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

Config::Config(Model* model) : model_(model), strategy_(NULL), drug_db_(NULL), parasite_db_(NULL), initial_parasite_info_(), importation_parasite_info_(), importation_parasite_periodically_info_(), tme_strategy_(NULL) {
    total_time_ = -1;
    start_treatment_day_ = -1;
    start_collect_data_day_ = -1;

    p_treatment_ = -1;

    number_of_locations_ = -1;
    number_of_age_classes_ = -1;

    p_infection_from_an_infectious_bite_ = -1;

    birth_rate_ = -1;
    number_of_tracking_days_ = -1;

    modified_cost_of_resistance_ = -1;
    modified_mutation_factor_ = -1;
    tf_window_size_ = -1;
    //    initial_parasite_info_.reserve(1);

}

Config::Config(const Config& orig) {
}

Config::~Config() {
    DeletePointer<Strategy>(strategy_);
    DeletePointer<Strategy>(tme_strategy_);
    DeletePointer<DrugDatabase>(drug_db_);
    DeletePointer<ParasiteDatabase>(parasite_db_);
}

void Config::read_from_file(const std::string& config_file_name) {

    YAML::Node config = YAML::LoadFile(config_file_name);
    total_time_ = config["total_time"].as<int>();
    start_treatment_day_ = config["start_treatment_day"].as<int>();
    start_collect_data_day_ = config["start_collect_data_day"].as<int>();

    p_treatment_ = config["p_treatment"].as<double>();

    number_of_locations_ = config["number_of_locations"].as<int>();
    number_of_age_classes_ = config["number_of_age_classes"].as<int>();

    beta_.clear();
    seasonal_beta_.a.clear();
    seasonal_beta_.phi.clear();
    for (int i = 0; i < number_of_locations_; i++) {
        beta_.push_back(config["beta"][i].as<double>());
        seasonal_beta_.a.push_back(config["seasonal_beta"]["a"][i].as<double>());
        seasonal_beta_.phi.push_back(config["seasonal_beta"]["phi"][i].as<double>());

    }


    p_infection_from_an_infectious_bite_ = config["p_infection_from_an_infectious_bite"].as<double>();

    age_structure_.clear();
    for (int i = 0; i < number_of_age_classes_; i++) {
        age_structure_.push_back(config["age_structure"][i].as<int>());
    }

    initial_age_structure_.clear();
    for (int i = 0; i < config["initial_age_structure"].size(); i++) {
        initial_age_structure_.push_back(config["initial_age_structure"][i].as<int>());
    }

    population_size_by_location_.clear();
    for (int i = 0; i < number_of_locations_; i++) {
        population_size_by_location_.push_back(config["population_size_by_location"][i].as<int>());
    }

    age_distribution_by_location_.clear();
    age_distribution_by_location_.assign(number_of_locations_, std::vector<double>());
    for (int loc = 0; loc < number_of_locations_; loc++) {
        for (int i = 0; i < config["age_distribution_by_location"][loc].size(); i++) {
            age_distribution_by_location_[loc].push_back(config["age_distribution_by_location"][loc][i].as<double>());
        }
    }

    birth_rate_ = config["birth_rate"].as<double>();

    death_rate_by_age_.clear();
    for (int i = 0; i < number_of_age_classes_; i++) {
        death_rate_by_age_.push_back(config["death_rate_by_age"][i].as<double>());
    }


    number_of_tracking_days_ = config["number_of_tracking_days"].as<int>();

    mortality_when_treatment_fail_by_age_class_.clear();
    for (int i = 0; i < number_of_age_classes_; i++) {
        mortality_when_treatment_fail_by_age_class_.push_back(config["mortality_when_treatment_fail_by_age"][i].as<double>());
    }

    read_parasite_density_level(config["parasite_density_level"]);

    read_immune_system_information(config["immune_system_information"]);

    read_strategy_therapy_and_drug_information(config);


    read_relative_biting_rate_info(config);
    read_spatial_info(config);
    read_spatial_external_population_info(config);

    read_initial_parasite_info(config);
    read_importation_parasite_info(config);
    read_importation_parasite_periodically_info(config);

    read_relative_infectivity_info(config);

    days_to_clinical_under_five_ = config["days_to_clinical_under_five"].as<int>();
    days_to_clinical_over_five_ = config["days_to_clinical_over_five"].as<int>();
    days_mature_gametocyte_under_five_ = config["days_mature_gametocyte_under_five"].as<int>();
    days_mature_gametocyte_over_five_ = config["days_mature_gametocyte_over_five"].as<int>();

    p_compliance_ = config["p_compliance"].as<double>();
    min_dosing_days_ = config["min_dosing_days"].as<int>();

    gametocyte_level_under_artemisinin_action_ = config["gametocyte_level_under_artemisinin_action"].as<double>();

    p_relapse_ = config["p_relapse"].as<double>();
    relapse_duration_ = config["relapse_duration"].as<int>();

    allow_new_coinfection_to_cause_symtoms_ = config["allow_new_coinfection_to_cause_symtoms"].as<bool>();
    update_frequency_ = config["update_frequency"].as<int>();
    report_frequency_ = config["report_frequency"].as<int>();

    TF_rate_ = config["TF_rate"].as<double>();

    tme_info_.tme_starting_day = config["tme_info"]["tme_starting_day"].as<int>();
    tme_info_.MDA_coverage.clear();
    tme_info_.MDA_duration.clear();
    for (int location = 0; location < number_of_locations_; location++) {
        tme_info_.MDA_coverage.push_back(config["tme_info"]["mda_coverage"][location].as<double>());
        tme_info_.MDA_duration.push_back(config["tme_info"]["mda_duration"][location].as<int>());
    }

    using_free_recombination_ = config["using_free_recombination"].as<bool>();
    tf_window_size_ = config["tf_window_size"].as<int>();
    
    using_age_dependent_bitting_level_ = config["using_age_dependent_bitting_level"].as<bool>();
    using_variable_probability_infectious_bites_cause_infection_ = config["using_variable_probability_infectious_bites_cause_infection"].as<bool>();
}

void Config::read_parasite_density_level(const YAML::Node& config) {

    log_parasite_density_level_.log_parasite_density_cured = config["log_parasite_density_cured"].as<double>();
    log_parasite_density_level_.log_parasite_density_from_liver = config["log_parasite_density_from_liver"].as<double>();
    log_parasite_density_level_.log_parasite_density_asymptomatic = config["log_parasite_density_asymptomatic"].as<double>();
    log_parasite_density_level_.log_parasite_density_clinical = config["log_parasite_density_clinical"].as<double>();
    log_parasite_density_level_.log_parasite_density_detectable = config["log_parasite_density_detectable"].as<double>();
    log_parasite_density_level_.log_parasite_density_pyrogenic = config["log_parasite_density_pyrogenic"].as<double>();
}

void Config::read_immune_system_information(const YAML::Node& config) {

    immune_system_information_.acquire_rate = config["b1"].as<double>();
    immune_system_information_.decay_rate = config["b2"].as<double>();

    immune_system_information_.duration_for_fully_immune = config["duration_for_fully_immune"].as<double>();
    immune_system_information_.duration_for_naive = config["duration_for_naive"].as<double>();

    double mean_initial_condition = config["mean_initial_condition"].as<double>();
    double sd_initial_condition = config["sd_initial_condition"].as<double>();

    if (sd_initial_condition == 0) {
        immune_system_information_.alpha_immune = mean_initial_condition;
        immune_system_information_.beta_immune = 0.0;
    } else {
        immune_system_information_.alpha_immune = mean_initial_condition * mean_initial_condition * (1 - mean_initial_condition) / (sd_initial_condition * sd_initial_condition) - mean_initial_condition;
        immune_system_information_.beta_immune = immune_system_information_.alpha_immune / mean_initial_condition - immune_system_information_.alpha_immune;
    }

    immune_system_information_.immune_inflation_rate = config["immune_inflation_rate"].as<double>();

    immune_system_information_.min_clinical_probability = config["min_clinical_probability"].as<double>();
    immune_system_information_.max_clinical_probability = config["max_clinical_probability"].as<double>();

    immune_system_information_.immune_effect_on_progression_to_clinical = config["immune_effect_on_progression_to_clinical"].as<double>();

    immune_system_information_.c_min = pow(10, -(log_parasite_density_level_.log_parasite_density_asymptomatic - log_parasite_density_level_.log_parasite_density_cured) / immune_system_information_.duration_for_fully_immune);
    immune_system_information_.c_max = pow(10, -(log_parasite_density_level_.log_parasite_density_asymptomatic - log_parasite_density_level_.log_parasite_density_cured) / immune_system_information_.duration_for_naive);


    immune_system_information_.age_mature_immunity = config["age_mature_immunity"].as<double>();
    immune_system_information_.factor_effect_age_mature_immunity = config["factor_effect_age_mature_immunity"].as<double>();

    // implement inlation rate
    double acR = immune_system_information_.acquire_rate;
    immune_system_information_.acquire_rate_by_age.clear();
    for (int age = 0; age <= 80; age++) {
        double factor = 1;
        if (age < immune_system_information().age_mature_immunity) {
            factor = (age == 0) ? 0.5 : age;

            factor = factor / immune_system_information().age_mature_immunity;
            factor = pow(factor, immune_system_information().factor_effect_age_mature_immunity);
        }

        immune_system_information_.acquire_rate_by_age.push_back(factor * acR);

        acR *= (1 + immune_system_information_.immune_inflation_rate);
        //        std::cout << acR << std::endl;
    }

    //       for (int age = 0; age <= 80; age++) {
    //            std::cout <<  immune_system_information_.acquire_rate_by_age[age] << "\t";
    //        }
    //        std::cout << std::endl;

    assert(immune_system_information_.acquire_rate_by_age.size() == 81);

}

void Config::read_strategy_therapy_and_drug_information(const YAML::Node& config) {
    std::string strategyName = config["StrategyInfo"]["strategyName"].as<std::string>();

    strategy_ = read_strategy(config, config["StrategyInfo"], strategyName);

    build_drug_and_parasite_db(config);
}

void Config::build_drug_and_parasite_db(const YAML::Node& config) {
    std::set<int> drug_ids;

    BOOST_FOREACH(Therapy* therapy, strategy_->therapy_list()) {

        BOOST_FOREACH(int drug_id, therapy->drug_ids()) {
            drug_ids.insert(drug_id);
        }
    }
    //tme strategy
    if (config["tme_info"]["tme_starting_day"].as<int>() != 0) {
        if (tme_strategy_ == NULL) {
            std::string tme_strategyName = config["tme_info"]["strategyName"].as<std::string>();
            tme_strategy_ = read_strategy(config, config["tme_info"], tme_strategyName);
        }

        BOOST_FOREACH(Therapy* therapy, tme_strategy_->therapy_list()) {

            BOOST_FOREACH(int drug_id, therapy->drug_ids()) {
                drug_ids.insert(drug_id);
            }
        }
    }
    //find max mutation position
    int max_mutation_position = 0;

    BOOST_FOREACH(int drug_id, drug_ids) {
        std::string drug_id_s = NumberToString<int>(drug_id);
        for (int i = 0; i < config["drugInfo"][drug_id_s]["mutation_position"].size(); i++) {
            if (max_mutation_position < config["drugInfo"][drug_id_s]["mutation_position"][i].as<int>()) {
                max_mutation_position = config["drugInfo"][drug_id_s]["mutation_position"][i].as<int>();
            }
        }
    }
    int gene_length = max_mutation_position + 1;

    //build drug DB
    build_drug_db(config, drug_ids, gene_length);
    // build parasite db
    build_parasite_db(gene_length);
}

void Config::build_drug_db(const YAML::Node& config, const std::set<int>& drug_ids, const int& gene_length) {
    DeletePointer<DrugDatabase>(drug_db_);
    drug_db_ = new DrugDatabase();

    BOOST_FOREACH(int drug_id, drug_ids) {
        DrugType* dt = read_drugtype(config, drug_id, gene_length);
        drug_db_->add(dt);
    }

}

void Config::build_parasite_db(const int &gene_length) {
    DeletePointer<ParasiteDatabase>(parasite_db_);
    parasite_db_ = new ParasiteDatabase();
    for (int i = 0; i < pow(2, gene_length); i++) {
        Genotype* gt = new Genotype(i, gene_length, drug_db_);
        //        std::cout << gt->resistance_bit_string() << "-" << gt->relative_fitness_multiple_infection() << std::endl;
        parasite_db_->add(gt);
    }
    number_of_parasite_types_ = parasite_db_->genotype_db().size();

    parasite_db_->initialize_mating_matrix();

}

Strategy* Config::read_strategy(const YAML::Node& config, const YAML::Node& n, const std::string& strategy_name) {
    Strategy* s;
    if (strategy_name == "CyclingStrategy") {
        s = new CyclingStrategy();
        ((CyclingStrategy*) s)->set_cycling_time(n[strategy_name]["cycling_time"].as<int>());
    } else if (strategy_name == "AdaptiveCyclingStrategy") {
        s = new AdaptiveCyclingStrategy();
        ((AdaptiveCyclingStrategy*) s)->set_trigger_value(n[strategy_name]["trigger_value"].as<double>());
        ((AdaptiveCyclingStrategy*) s)->set_delay_until_actual_trigger(n[strategy_name]["delay_until_actual_trigger"].as<int>());
        ((AdaptiveCyclingStrategy*) s)->set_turn_off_days(n[strategy_name]["turn_off_days"].as<int>());
    } else if (strategy_name == "MFTStrategy") {
        s = new MFTStrategy();
        for (int i = 0; i < n[strategy_name]["distribution"].size(); i++) {
            ((MFTStrategy*) s)->distribution().push_back(n[strategy_name]["distribution"][i].as<double>());
        }
    } else /*  if (strategy_name == "SFTStrategy")*/ {
        s = new SFTStrategy();
    }

    for (int i = 0; i < n[strategy_name]["therapyID"].size(); i++) {
        Therapy* therapy = read_therapy(config, n[strategy_name]["therapyID"][i].as<int>());
        s->add_therapy(therapy);
    }
    return s;
}

Therapy* Config::read_therapy(const YAML::Node& config, const int& therapy_id) {
    const YAML::Node& n = config["TherapyInfo"];

    std::string t_id = NumberToString<int>(therapy_id);
//    std::cout << therapy_id << std::endl;

    Therapy* t = new Therapy();

    for (int i = 0; i < n[t_id]["drug_id"].size(); i++) {
        int drug_id = n[t_id]["drug_id"][i].as<int>();
        //                std::cout<<drug_id << std::endl;
        t->add_drug(drug_id);
    }

    int dosing_days = n[t_id]["dosing_days"].as<int>();
    int testing_day = n[t_id]["testing_day"].as<int>();

    t->set_id(therapy_id);
    t->set_number_of_dosing_days(dosing_days);
    t->set_testing_day(testing_day);

    return t;

}

DrugType* Config::read_drugtype(const YAML::Node& config, const int& drug_id, const int& gene_length) {
    DrugType* dt = new DrugType(gene_length);
    dt->set_id(drug_id);

    std::string drug_id_s = NumberToString<int>(drug_id);
    const YAML::Node& n = config["drugInfo"][drug_id_s];

    dt->set_drug_half_life(n["half_life"].as<double>());
    dt->set_maximum_parasite_killing_rate(n["maximum_parasite_killing_rate"].as<double>());
    dt->set_n(n["n"].as<double>());
    dt->set_EC50(n["EC50"].as<double>());

    //    std::cout <<dt->drug_half_life() << "-" << dt->maximum_parasite_killing_rate() << "-" << dt->n() << "-" << dt->EC50() << std::endl;
    for (int i = 0; i < n["age_specific_drug_concentration_sd"].size(); i++) {
        dt->age_group_specific_drug_concentration_sd().push_back(n["age_specific_drug_concentration_sd"][i].as<double>());
    }
    //    assert(dt->age_group_specific_drug_concentration_sd().size() == 15);

    dt->set_p_mutation(n["mutation_probability"].as<double>());

    for (int i = 0; i < n["mutation_position"].size(); i++) {
        dt->set_resistance_position(n["mutation_position"][i].as<int>());
    }

    dt->set_k(n["k"].as<double>());
    dt->set_resistance_cost_multiple_infection(n["resistance_cost_multiple_infection"].as<double>());
    dt->set_artermisinin_derivative(n["isArtermisininDerivative"].as<int>() == 1 ? true : false);



    return dt;
}

void Config::read_relative_biting_rate_info(const YAML::Node& config) {
    const YAML::Node& n = config["relative_bitting_info"];

    relative_bitting_information_.max_relative_biting_value = n["max_relative_biting_value"].as<double>();

    relative_bitting_information_.number_of_biting_levels = n["number_of_biting_levels"].as<double>();

    relative_bitting_information_.scale = n["biting_level_distribution"]["Exponential"]["scale"].as<double>();

    relative_bitting_information_.mean = n["biting_level_distribution"]["Gamma"]["mean"].as<double>();
    relative_bitting_information_.sd = n["biting_level_distribution"]["Gamma"]["sd"].as<double>();

    //calculate density and level value here
    calculate_relative_biting_density();
}

void Config::calculate_relative_biting_density() {
    double var = relative_bitting_information_.sd * relative_bitting_information_.sd;
    double b = var / (relative_bitting_information_.mean - 1); //theta
    double a = (relative_bitting_information_.mean - 1) / b; //k

    relative_bitting_information_.v_biting_level_density.clear();
    relative_bitting_information_.v_biting_level_value.clear();

    double max = relative_bitting_information_.max_relative_biting_value - 1; //maxRelativeBiting -1
    int numberOfLevel = relative_bitting_information_.number_of_biting_levels;

    double step = max / (double) (numberOfLevel - 1);

    int j = 0;
    double oldP = 0;
    double sum = 0;

    for (double i = 0; i <= max + 0.0001; i += step) {
        double p = gsl_cdf_gamma_P(i + step, a, b);
        double value = 0;
        value = (j == 0) ? p : p - oldP;
        relative_bitting_information_.v_biting_level_density.push_back(value);
        oldP = p;
        relative_bitting_information_.v_biting_level_value.push_back(i + 1);
        sum += value;
        j++;

    }


    //normalized
    double t = 0;
    for (int i = 0; i < relative_bitting_information_.v_biting_level_density.size(); i++) {
        relative_bitting_information_.v_biting_level_density[i] = relative_bitting_information_.v_biting_level_density[i] + (1 - sum) / relative_bitting_information_.v_biting_level_density.size();
        t += relative_bitting_information_.v_biting_level_density[i];
    }


    assert(relative_bitting_information_.number_of_biting_levels == relative_bitting_information_.v_biting_level_density.size());
    assert(relative_bitting_information_.number_of_biting_levels == relative_bitting_information_.v_biting_level_value.size());
    assert(fabs(t - 1) < 0.0001);
    if (Model::RANDOM != NULL) {
        Model::RANDOM->bitting_level_generator().set_level_density(&relative_bitting_information_.v_biting_level_density);
    }


    //    for (int i = 0; i < relative_bitting_information_.v_biting_level_density.size(); i++) {
    //        std::cout << i << "\t" << relative_bitting_information_.v_biting_level_value[i] << "\t"
    //                << relative_bitting_information_.v_biting_level_density[i] << std::endl;
    //    }


}

void Config::read_spatial_info(const YAML::Node& config) {
    const YAML::Node& n = config["spatial_information"];

    spatial_information_.max_relative_moving_value = n["max_relative_moving_value"].as<double>();

    spatial_information_.number_of_moving_levels = n["number_of_moving_levels"].as<double>();

    spatial_information_.scale = n["moving_level_distribution"]["Exponential"]["scale"].as<double>();

    spatial_information_.mean = n["moving_level_distribution"]["Gamma"]["mean"].as<double>();
    spatial_information_.sd = n["moving_level_distribution"]["Gamma"]["sd"].as<double>();

    //calculate density and level value here

    double var = spatial_information_.sd * spatial_information_.sd;

    double b = var / (spatial_information_.mean - 1); //theta
    double a = (spatial_information_.mean - 1) / b; //k

    spatial_information_.v_moving_level_density.clear();
    spatial_information_.v_moving_level_value.clear();

    double max = spatial_information_.max_relative_moving_value - 1; //maxRelativeBiting -1
    int numberOfLevel = spatial_information_.number_of_moving_levels;

    double step = max / (double) (numberOfLevel - 1);

    int j = 0;
    double oldP = 0;
    double sum = 0;

    for (double i = 0; i <= max + 0.0001; i += step) {
        double p = gsl_cdf_gamma_P(i + step, a, b);
        double value = 0;
        value = (j == 0) ? p : p - oldP;
        spatial_information_.v_moving_level_density.push_back(value);
        oldP = p;
        spatial_information_.v_moving_level_value.push_back(i + 1);
        sum += value;
        j++;

    }

    //normalized
    double t = 0;
    for (int i = 0; i < spatial_information_.v_moving_level_density.size(); i++) {
        spatial_information_.v_moving_level_density[i] = spatial_information_.v_moving_level_density[i] + (1 - sum) / spatial_information_.v_moving_level_density.size();
        t += spatial_information_.v_moving_level_density[i];
    }


    assert(spatial_information_.number_of_moving_levels == spatial_information_.v_moving_level_density.size());
    assert(spatial_information_.number_of_moving_levels == spatial_information_.v_moving_level_value.size());
    assert(fabs(t - 1) < 0.0001);

    spatial_information_.circulation_percent = n["circulation_percent"].as<double>();

    double length_of_stay_mean = n["length_of_stay"]["mean"].as<double>();
    double length_of_stay_sd = n["length_of_stay"]["sd"].as<double>();

    double stay_variance = length_of_stay_sd * length_of_stay_sd;
    double k = stay_variance / length_of_stay_mean; //k
    double theta = length_of_stay_mean / k; //theta

    spatial_information_.length_of_stay_theta = theta;
    spatial_information_.length_of_stay_k = k;

    if (Model::RANDOM != NULL) {
        Model::RANDOM->moving_level_generator().set_level_density(&spatial_information_.v_moving_level_density);
    }
}

void Config::read_spatial_external_population_info(const YAML::Node& config) {
    const YAML::Node& n = config["spatial_external_population_information"];

    spatial_external_population_information_.max_relative_moving_value = n["max_relative_moving_value"].as<double>();

    spatial_external_population_information_.number_of_moving_levels = n["number_of_moving_levels"].as<double>();

    spatial_external_population_information_.scale = n["moving_level_distribution"]["Exponential"]["scale"].as<double>();

    spatial_external_population_information_.mean = n["moving_level_distribution"]["Gamma"]["mean"].as<double>();
    spatial_external_population_information_.sd = n["moving_level_distribution"]["Gamma"]["sd"].as<double>();

    //calculate density and level value here

    double var = spatial_external_population_information_.sd * spatial_external_population_information_.sd;

    double b = var / (spatial_external_population_information_.mean - 1); //theta
    double a = (spatial_external_population_information_.mean - 1) / b; //k

    spatial_external_population_information_.v_moving_level_density.clear();
    spatial_external_population_information_.v_moving_level_value.clear();

    double max = spatial_external_population_information_.max_relative_moving_value - 1; //maxRelativeBiting -1
    int numberOfLevel = spatial_external_population_information_.number_of_moving_levels;

    double step = max / (double) (numberOfLevel - 1);

    int j = 0;
    double oldP = 0;
    double sum = 0;

    for (double i = 0; i <= max + 0.0001; i += step) {
        double p = gsl_cdf_gamma_P(i + step, a, b);
        double value = 0;
        value = (j == 0) ? p : p - oldP;
        spatial_external_population_information_.v_moving_level_density.push_back(value);
        oldP = p;
        spatial_external_population_information_.v_moving_level_value.push_back(i + 1);
        sum += value;
        j++;

    }

    //normalized
    double t = 0;
    for (int i = 0; i < spatial_external_population_information_.v_moving_level_density.size(); i++) {
        spatial_external_population_information_.v_moving_level_density[i] = spatial_external_population_information_.v_moving_level_density[i] + (1 - sum) / spatial_information_.v_moving_level_density.size();
        t += spatial_external_population_information_.v_moving_level_density[i];
    }


    assert(spatial_external_population_information_.number_of_moving_levels == spatial_external_population_information_.v_moving_level_density.size());
    assert(spatial_external_population_information_.number_of_moving_levels == spatial_external_population_information_.v_moving_level_value.size());
    assert(fabs(t - 1) < 0.0001);

    for (int i = 0; i < number_of_locations_; i++) {
        spatial_external_population_information_.circulation_percent.push_back(n["circulation_percent"][i].as<double>());
    }
    //    spatial_external_population_information_.circulation_percent = n["circulation_percent"].as<double>();

    double length_of_stay_mean = n["length_of_stay"]["mean"].as<double>();
    double length_of_stay_sd = n["length_of_stay"]["sd"].as<double>();

    double stay_variance = length_of_stay_sd * length_of_stay_sd;
    double k = stay_variance / length_of_stay_mean; //k
    double theta = length_of_stay_mean / k; //theta

    spatial_external_population_information_.length_of_stay_theta = theta;
    spatial_external_population_information_.length_of_stay_k = k;

    if (Model::RANDOM != NULL) {
        Model::RANDOM->external_population_moving_level_generator().set_level_density(&spatial_external_population_information_.v_moving_level_density);
    }

    for (int i = 0; i < number_of_locations_; i++) {
        spatial_external_population_information_.daily_EIR.push_back(n["daily_EIR"][i].as<double>());
        spatial_external_population_information_.seasonal_EIR.a.push_back(n["seasonal_EIR"]["a"][i].as<double>());
        spatial_external_population_information_.seasonal_EIR.phi.push_back(n["seasonal_EIR"]["phi"][i].as<double>());
    }
    //    spatial_external_population_information_.daily_EIR = n["daily_EIR"].as<double>();
}

void Config::read_initial_parasite_info(const YAML::Node& config) {
    const YAML::Node& n = config["initial_parasite_info"];

    for (int i = 0; i < n.size(); i++) {
        int location = n[i]["location_id"].as<int>();
        if (location < number_of_locations_) {
            for (int j = 0; j < n[i]["parasite_info"].size(); j++) {
                //            InitialParasiteInfo ipi;
                //            ipi.location = location;
                int parasite_type_id = n[i]["parasite_info"][j]["parasite_type_id"].as<int>();
                double prevalence = n[i]["parasite_info"][j]["prevalence"].as<double>();
                initial_parasite_info_.push_back(InitialParasiteInfo(location, parasite_type_id, prevalence));
            }
        }
    }
}

void Config::read_importation_parasite_info(const YAML::Node& config) {
    const YAML::Node& n = config["introduce_parasite"];

    for (int i = 0; i < n.size(); i++) {
        int location = n[i]["location"].as<int>();
        if (location < number_of_locations_) {
            for (int j = 0; j < n[i]["parasite_info"].size(); j++) {
                //            InitialParasiteInfo ipi;
                //            ipi.location = location;
                int parasite_type_id = n[i]["parasite_info"][j]["genotype_id"].as<int>();
                int time = n[i]["parasite_info"][j]["time"].as<int>();
                int num = n[i]["parasite_info"][j]["number_of_cases"].as<int>();
                importation_parasite_info_.push_back(ImportationParasiteInfo(location, parasite_type_id, time, num));
            }
        }
    }


}

void Config::read_importation_parasite_periodically_info(const YAML::Node& config) {
    const YAML::Node& n = config["introduce_parasite_periodically"];
    for (int i = 0; i < n.size(); i++) {
        int location = n[i]["location"].as<int>();
        if (location < number_of_locations_) {
            for (int j = 0; j < n[i]["parasite_info"].size(); j++) {
                //            InitialParasiteInfo ipi;
                //            ipi.location = location;
                int parasite_type_id = n[i]["parasite_info"][j]["genotype_id"].as<int>();
                int dur = n[i]["parasite_info"][j]["duration"].as<int>();
                int num = n[i]["parasite_info"][j]["number_of_cases"].as<int>();
                importation_parasite_periodically_info_.push_back(ImportationParasitePeriodicallyInfo(location, parasite_type_id, dur, num));
            }
        }
    }

}

void Config::read_relative_infectivity_info(const YAML::Node& config) {
    const YAML::Node& n = config["relative_infectivity"];

    relative_infectivity_.sigma = n["sigma"].as<double>();
    double ro = n["ro"].as<double>();
    double blood_meal_volume = n["blood_meal_volume"].as<double>();

    double d_star = 1 / blood_meal_volume;

    relative_infectivity_.ro_star = (log(ro) - log(d_star)) / relative_infectivity_.sigma;

    relative_infectivity_.sigma = log(10) / relative_infectivity_.sigma;
    //    std::cout << relative_infectivity_.sigma << "\t" << relative_infectivity_.ro_star<< std::endl;
}

void Config::override_parameters(const std::string& override_file, const int& pos) {
    if (pos == -1) return;
    std::ifstream ifs(override_file.c_str());
    if (!ifs && override_file != "") {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    std::string buf;
    getline(ifs, buf);

    //header of file containt all overrides parameters name    
    std::vector<std::string> override_header = split(buf, '\t');


    //goto the pos line in the file
    for (int i = 0; (i < pos) && getline(ifs, buf); i++) {
    }
    //buff contain the parameters
    std::vector<std::string> override_parameters = split(buf, '\t');

    //override parameter
    for (int i = 0; i < override_parameters.size(); i++) {
        if (override_parameters[i] != "nil") {
            override_1_parameter(override_header[i], override_parameters[i]);
        }
    }
    //re-calculate dependent variables
    //    CalculateDependentVariables();
}

void Config::override_1_parameter(const std::string& parameter_name, const std::string& parameter_value) {
    if (parameter_name == "population_size") {
        population_size_by_location_[0] = atoi(parameter_value.c_str());
    }

    if (parameter_name == "total_time") {
        total_time_ = atoi(parameter_value.c_str());
    }

    if (parameter_name == "beta") {
        beta_[0] = atof(parameter_value.c_str());
    }

    if (parameter_name == "f") {
        p_treatment_ = atof(parameter_value.c_str());
    }

    if (parameter_name == "cost_of_resistance") {
        modified_cost_of_resistance_ = atof(parameter_value.c_str());

        for (DrugTypePtrMap::iterator it = drug_db_->drug_db().begin(); it != drug_db_->drug_db().end(); it++) {
            //            std::cout << it->second->id()<< std::endl;
            it->second->set_resistance_cost_multiple_infection(modified_cost_of_resistance_);
        }

        int gene_length = parasite_db_->genotype_db()[0]->resistance_bit_string().size();
        build_parasite_db(gene_length);

    }

    if (parameter_name == "z") {
        immune_system_information_.immune_effect_on_progression_to_clinical = atof(parameter_value.c_str());
    }

    if (parameter_name == "kappa") {
        immune_system_information_.factor_effect_age_mature_immunity = atof(parameter_value.c_str());

        // implement inlation rate
        double acR = immune_system_information_.acquire_rate;
        immune_system_information_.acquire_rate_by_age.clear();
        for (int age = 0; age <= 80; age++) {
            double factor = 1;
            if (age < immune_system_information().age_mature_immunity) {
                factor = (age == 0) ? 0.5 : age;

                factor = factor / immune_system_information().age_mature_immunity;
                factor = pow(factor, immune_system_information().factor_effect_age_mature_immunity);
            }

            immune_system_information_.acquire_rate_by_age.push_back(factor * acR);

            acR *= (1 + immune_system_information_.immune_inflation_rate);
        }

        assert(immune_system_information_.acquire_rate_by_age.size() == 81);
    }

    if (parameter_name == "relative_bitting_sd") {
        relative_bitting_information_.sd = atof(parameter_value.c_str());
        calculate_relative_biting_density();
    }

    if (parameter_name == "k") {
        modified_mutation_factor_ = atof(parameter_value.c_str());
        for (DrugTypePtrMap::iterator it = drug_db_->drug_db().begin(); it != drug_db_->drug_db().end(); it++) {
            it->second->set_k(modified_mutation_factor_);
        }
    }

    if (parameter_name == "drug_half_life") {
        modified_drug_half_life_ = atof(parameter_value.c_str());
    }


    if (parameter_name == "strategy") {
        YAML::Node config = YAML::LoadFile(Model::MODEL->config_filename());

        int strategy_type = atoi(parameter_value.c_str());

        DeletePointer<Strategy>(strategy_);

        if (strategy_type == Strategy::Cycling) {
            strategy_ = new CyclingStrategy();
            ((CyclingStrategy*) strategy_)->set_cycling_time(1825);
        } else if (strategy_type == Strategy::AdaptiveCycling) {
            strategy_ = new AdaptiveCyclingStrategy();
            ((AdaptiveCyclingStrategy*) strategy_)->set_trigger_value(0.1);
            ((AdaptiveCyclingStrategy*) strategy_)->set_delay_until_actual_trigger(365);
            ((AdaptiveCyclingStrategy*) strategy_)->set_turn_off_days(365);
        } else if (strategy_type == Strategy::MFT) {
            strategy_ = new MFTStrategy();
            ((MFTStrategy*) strategy_)->distribution().push_back(0.333334);
            ((MFTStrategy*) strategy_)->distribution().push_back(0.333333);
            ((MFTStrategy*) strategy_)->distribution().push_back(0.333333);
        } else /*  if (strategy_name == "SFTStrategy")*/ {
            strategy_ = new SFTStrategy();
        }

        std::vector<int> t_ids;
        if (modified_drug_half_life_ == 1) {
            //            std::cout << "Hello" << std::endl;
            t_ids.push_back(1);
            t_ids.push_back(2);
            t_ids.push_back(3);
            // t_id =  1 ,2,3
        } else if (modified_drug_half_life_ == 9) {
            //            std::cout << "Hello" << std::endl;
            t_ids.push_back(4);
            t_ids.push_back(5);
            t_ids.push_back(6);
            // t_id =  4 ,5,6
        } else if (modified_drug_half_life_ == 28) {
            // t_id =  7 ,8,9
            t_ids.push_back(7);
            t_ids.push_back(8);
            t_ids.push_back(9);
        } else if (modified_drug_half_life_ == -1) {
            // t_id =  10 ,11,12
            t_ids.push_back(10);
            t_ids.push_back(11);
            t_ids.push_back(12);
        }

        for (int i = 0; i < t_ids.size(); i++) {
            Therapy* therapy = read_therapy(config, t_ids[i]);
            strategy_->add_therapy(therapy);
        }

        //rebuild database
        build_drug_and_parasite_db(config);

        if (modified_cost_of_resistance_ != -1) {
            for (DrugTypePtrMap::iterator it = drug_db_->drug_db().begin(); it != drug_db_->drug_db().end(); it++) {
                //            std::cout << it->second->id()<< std::endl;
                it->second->set_resistance_cost_multiple_infection(modified_cost_of_resistance_);
            }

            int gene_length = parasite_db_->genotype_db()[0]->resistance_bit_string().size();
            build_parasite_db(gene_length);
        }

        if (modified_mutation_factor_ != -1) {
            for (DrugTypePtrMap::iterator it = drug_db_->drug_db().begin(); it != drug_db_->drug_db().end(); it++) {
                it->second->set_k(modified_mutation_factor_);
            }
        }
    }


}