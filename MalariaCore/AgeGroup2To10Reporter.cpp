/* 
 * File:   AgeGroup2To10Reporter.cpp
 * Author: Merlin
 * 
 * Created on September 15, 2014, 10:18 AM
 */

#include "AgeGroup2To10Reporter.h"

#include "Random.h"

#include "Model.h"
#include "Random.h"
#include "ModelDataCollector.h"
#include "Config.h"
#include "Strategy.h"
#include "SCTherapy.h"
#include "Population.h"
#include <boost/format.hpp>
#include "ResistanceTracker.h"
#include "PersonIndexByLocationStateAgeClass.h"

AgeGroup2To10Reporter::AgeGroup2To10Reporter() : last_reported_NTF_(0), last_reported_clinical_episodes_(0), last_reported_mutants_(0) {
}

AgeGroup2To10Reporter::AgeGroup2To10Reporter(const AgeGroup2To10Reporter& orig) {
}

AgeGroup2To10Reporter::~AgeGroup2To10Reporter() {
}

void AgeGroup2To10Reporter::initialize() {
}

void AgeGroup2To10Reporter::before_run() {
    std::cout << Model::RANDOM->seed() << std::endl;
}

void AgeGroup2To10Reporter::after_run() {
    Model::DATA_COLLECTOR->update_after_run();

    //output parameter
    output_parameters();

    //output others indicators
    // NTF
    print_ntf_by_location();
    // EIR - 20x
    print_EIR_by_location();

    print_20x_by_location();

    // EAMU
    print_EAMU();

    // prevalance
    print_prevalence_by_location();

    // fraction of positive that are clinical
    print_fraction_of_positive_that_are_clinical_by_location();

    // mean immune
    print_mean_immune_by_location();

    // mean number of clones per positive Individual
    print_mean_number_of_clones_per_positive_individual();
    // LOI
    print_LOI();

    // mean number of clones per positive Individual by age group
    print_mean_number_of_clones_per_positive_individual_by_age_group();

    // death by age class
    print_death_by_age_group();

    // number of clinical episode by age class
    print_number_of_clinical_episode_by_age_class();

    // prevalance by age class
    print_prevalence_by_age_class();
    // clinical percentage by age class
    print_fraction_of_positive_that_are_clinical_by_location_age_class();

    print_mean_immune_by_location_age_class();

    //print moi distribution
    print_moi_distribution();

    // resistance tracker
    print_resistance_tracker();

    // number of treatment by therapy
    print_treatments_by_therapy();

    // current time
    std::cout << Model::SCHEDULER->current_time() << "\t";
    // utl
    print_total_utl();

    std::cout << Model::DATA_COLLECTOR->popsize_by_location()[0] << "\t";

    //
    //    print_popsize_by_age_class();

    //print phi value by 5-age-group
    print_fraction_of_positive_that_are_clinical_by_location_age_class_by_5();


    print_utl();

    std::cout << std::endl;

}

void AgeGroup2To10Reporter::begin_time_step() {
}

void AgeGroup2To10Reporter::after_time_step() {

    if (Model::SCHEDULER->current_time() % Model::CONFIG->report_frequency() == 0) {
//        Model::DATA_COLLECTOR->perform_population_statistic();

        std::cout << Model::SCHEDULER->current_time() << "\t";
        std::cout << Model::DATA_COLLECTOR->AMU_per_parasite_pop() << "\t";
        //        std::cout << std::setw(COLUMN_WIDTH) << Model::STATISTIC->AFU() << "\t";

        //        double total_time_in_years = (Model::SCHEDULER->current_time() - Model::CONFIG->start_collect_data_day()) / 365.0;
        for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
            double location_discounted_NTF = Model::DATA_COLLECTOR->cumulative_discounted_NTF_by_location()[location];
            double NTF = Model::DATA_COLLECTOR->cumulative_NTF_by_location()[location];
            double change_in_NTF = Model::DATA_COLLECTOR->cumulative_discounted_NTF_by_location()[location] - last_reported_NTF_;
            int change_in_clinical_episodes = Model::DATA_COLLECTOR->cumulative_clinical_episodes_by_location()[location] - last_reported_clinical_episodes_;
            int change_in_mutants = Model::DATA_COLLECTOR->cumulative_mutants_by_location()[location] - last_reported_mutants_;

            last_reported_mutants_ = Model::DATA_COLLECTOR->cumulative_mutants_by_location()[location];
            last_reported_clinical_episodes_ = Model::DATA_COLLECTOR->cumulative_clinical_episodes_by_location()[location];
            last_reported_NTF_ = Model::DATA_COLLECTOR->cumulative_discounted_NTF_by_location()[location];

            //            location_discounted_NTF /= total_time_in_years;

            std::cout << location_discounted_NTF << "\t";
            std::cout << NTF << "\t";
            std::cout << change_in_NTF << "\t";

            //            std::cout << Model::STATISTIC->cumulative_clinical_episodes_by_location()[location] << "\t";
            std::cout << change_in_clinical_episodes << "\t";

            //            std::cout << Model::STATISTIC->cumulative_mutants_by_location()[location] << "\t";
            std::cout << change_in_mutants << "\t";



        }
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().sum_fraction_resistance(Model::DATA_COLLECTOR->resistance_tracker().single_resistance_ids()) << "\t";
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().sum_fraction_resistance(Model::DATA_COLLECTOR->resistance_tracker().double_resistance_ids()) << "\t";
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().sum_fraction_resistance(Model::DATA_COLLECTOR->resistance_tracker().tripple_resistance_ids()) << "\t";
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().sum_fraction_resistance(Model::DATA_COLLECTOR->resistance_tracker().quadruple_resistance_ids()) << "\t";
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().sum_fraction_resistance(Model::DATA_COLLECTOR->resistance_tracker().artemisinin_ids()) << "\t";
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().total_resistance_frequency() << "\t";

        for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
            std::cout << "-1111\t";
            //            report_number_by_state(location, pi);
            std::cout << Model::DATA_COLLECTOR->blood_slide_prevalence_by_location()[location]*100 << "\t";
            std::cout << Model::DATA_COLLECTOR->get_blood_slide_prevalence(location, 2, 10)*100 << "\t";
            std::cout << Model::DATA_COLLECTOR->get_blood_slide_prevalence(location, 10, 15)*100 << "\t";
            std::cout << Model::DATA_COLLECTOR->get_blood_slide_prevalence(location, 15, 45)*100 << "\t";
            if (Model::DATA_COLLECTOR->EIR_by_location_year()[location].empty()) {
                std::cout << 0 << "\t";
            } else {
                std::cout << Model::DATA_COLLECTOR->EIR_by_location_year()[location].back() << "\t";
            }

        }

        std::cout << boost::accumulators::mean(Model::DATA_COLLECTOR->acc) << "\t";

        std::cout << std::endl;
    }
}

void AgeGroup2To10Reporter::output_parameters() {
    std::cout << boost::format("%1%\t%2%\t")
            % Model::RANDOM->seed()
            % Model::CONFIG->number_of_locations();

    //intial population size
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::CONFIG->population_size_by_location()[location] << "\t";
    }
    //beta
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::CONFIG->beta()[location] << "\t";
    }

    std::cout << Model::CONFIG->p_treatment() << "\t";
    std::cout << Model::CONFIG->genotype_info().loci_vector[0].cost_of_resistance << "\t";
    std::cout << Model::CONFIG->immune_system_information().factor_effect_age_mature_immunity << "\t";
    std::cout << Model::CONFIG->immune_system_information().immune_effect_on_progression_to_clinical << "\t";
    std::cout << Model::CONFIG->relative_bitting_information().max_relative_biting_value << "\t";
    std::cout << Model::CONFIG->relative_bitting_information().mean << "\t";
    std::cout << Model::CONFIG->relative_bitting_information().sd << "\t";
    std::cout << Model::CONFIG->drug_db()->drug_db().begin()->second->k() << "\t";
    std::cout << Model::CONFIG->strategy()->to_int() << "\t";
    std::cout << Model::CONFIG->tf_window_size() << "\t";

    SCTherapy* scTherapy = dynamic_cast<SCTherapy*> (Model::CONFIG->strategy()->get_therapy());
    if (scTherapy != NULL) {
        std::cout << scTherapy->dosing_day() << "\t";
    } else {
        std::cout << 0 << "\t";
}
}

void AgeGroup2To10Reporter::print_ntf_by_location() {
    double total_time_in_years = (Model::SCHEDULER->current_time() - Model::CONFIG->start_collect_data_day()) / 365.0;
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        double location_discounted_NTF = Model::DATA_COLLECTOR->cumulative_discounted_NTF_by_location()[location] * 100 / (double) Model::DATA_COLLECTOR->popsize_by_location()[location];
        double NTF = Model::DATA_COLLECTOR->cumulative_NTF_by_location()[location] * 100 / (double) Model::DATA_COLLECTOR->popsize_by_location()[location];
        location_discounted_NTF /= total_time_in_years;
        NTF /= total_time_in_years;
        std::cout << location_discounted_NTF << "\t";
        std::cout << NTF << "\t";
    }
}

void AgeGroup2To10Reporter::print_EIR_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->EIR_by_location()[location] << "\t";
    }
}

void AgeGroup2To10Reporter::print_20x_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->percentage_bites_on_top_20_by_location()[location] * 100 << "\t";
    }
}

void AgeGroup2To10Reporter::print_EAMU() {
    std::cout << Model::DATA_COLLECTOR->AMU_per_parasite_pop() << "\t";
    std::cout << Model::DATA_COLLECTOR->AMU_per_person() << "\t";
    std::cout << Model::DATA_COLLECTOR->AMU_for_clinical_caused_parasite() << "\t";
    std::cout << Model::DATA_COLLECTOR->AFU() << "\t";
}

void AgeGroup2To10Reporter::print_prevalence_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        double prevalence = 0.0;
        for (int i = 0; i < 10; i++) {
            prevalence += Model::DATA_COLLECTOR->last_10_blood_slide_prevalence_by_location()[location][i];
        }
        std::cout << prevalence / 10.0 << "\t";
    }
}

void AgeGroup2To10Reporter::print_fraction_of_positive_that_are_clinical_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        double f_clinical = 0.0;
        for (int i = 0; i < 10; i++) {
            f_clinical += Model::DATA_COLLECTOR->last_10_fraction_positive_that_are_clinical_by_location()[location][i];
        }
        std::cout << f_clinical / 10.0 << "\t";
    }

}

void AgeGroup2To10Reporter::print_mean_immune_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->total_immune_by_location()[location] / Model::DATA_COLLECTOR->popsize_by_location()[location] << "\t";
    }
}

void AgeGroup2To10Reporter::print_mean_number_of_clones_per_positive_individual() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        unsigned long totalClones = Model::DATA_COLLECTOR->total_parasite_population_by_location()[location];
        int count = Model::DATA_COLLECTOR->number_of_positive_by_location()[location];
        double r = (count == 0) ? 0 : (totalClones / (double) count);
        std::cout << r << "\t";
    }

}

void AgeGroup2To10Reporter::print_mean_number_of_clones_per_positive_individual_by_age_group() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            unsigned long totalClones = Model::DATA_COLLECTOR->total_parasite_population_by_location_age_group()[location][ac];
            int count = Model::DATA_COLLECTOR->number_of_positive_by_location_age_group()[location][ac];
            double r = (count == 0) ? 0 : (totalClones / (double) count);
            std::cout << r << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_death_by_age_group() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {

            std::cout << Model::DATA_COLLECTOR->number_of_death_by_location_age_group()[location][ac] << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_number_of_clinical_episode_by_age_class() {
    double total_time_in_years = (Model::SCHEDULER->current_time() - Model::CONFIG->start_collect_data_day()) / 365.0;
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << (Model::DATA_COLLECTOR->cumulative_clinical_episodes_by_location_age_group()[location][ac] / (double) Model::DATA_COLLECTOR->popsize_by_location_age_class()[location][ac]) / total_time_in_years << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_prevalence_by_age_class() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << Model::DATA_COLLECTOR->blood_slide_prevalence_by_location_age_group()[location][ac] << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_fraction_of_positive_that_are_clinical_by_location_age_class() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {

            double s = 0;
            for (int i = 0; i < 10; i++) {
                s += Model::DATA_COLLECTOR->last_10_fraction_positive_that_are_clinical_by_location_age_class()[location][ac][i];
            }
            std::cout << s / 10 << "\t";

            //            std::cout << Model::STATISTIC->number_of_clinical_by_location_age_group()[location][ac] / (double) Model::STATISTIC->number_of_positive_by_location_age_group()[location][ac] << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_fraction_of_positive_that_are_clinical_by_location_age_class_by_5() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {

            double s = 0;
            for (int i = 0; i < 10; i++) {
                s += Model::DATA_COLLECTOR->last_10_fraction_positive_that_are_clinical_by_location_age_class_by_5()[location][ac][i];
            }
            std::cout << s / 10 << "\t";

            //            std::cout << Model::STATISTIC->number_of_clinical_by_location_age_group()[location][ac] / (double) Model::STATISTIC->number_of_positive_by_location_age_group()[location][ac] << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_resistance_tracker() {
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().any_double_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().all_double_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().any_triple_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().all_triple_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().any_quadruple_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().all_quadruple_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().total_tracking_time()[i] << "\t";
    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().artemisinin_tracking_time()[i] << "\t";
    }
}

void AgeGroup2To10Reporter::print_treatments_by_therapy() {
    for (int i = 0; i < Model::CONFIG->strategy()->therapy_list().size(); i++) {
        int t_id = Model::CONFIG->strategy()->therapy_list()[i]->id();
        int nTreaments = Model::DATA_COLLECTOR->number_of_treatments_with_therapy_ID()[t_id];
        int nSuccess = Model::DATA_COLLECTOR->number_of_treatments_success_with_therapy_ID()[t_id];
        int nFail = Model::DATA_COLLECTOR->number_of_treatments_fail_with_therapy_ID()[t_id];
        double pSuccess = (nTreaments == 0) ? 0 : nSuccess * 100.0 / nTreaments;

        std::cout << t_id << "\t" << nTreaments << "\t" << nFail + nSuccess << "\t" << pSuccess << "\t";

    }
}

void AgeGroup2To10Reporter::print_total_utl() {
    std::cout << Model::DATA_COLLECTOR->current_utl_duration() << "\t";
}

void AgeGroup2To10Reporter::print_utl() {
    for (int i = 0; i < Model::DATA_COLLECTOR->UTL_duration().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->UTL_duration()[i] << "\t";
    }

}

void AgeGroup2To10Reporter::print_LOI() {
    std::cout << Model::CONFIG->immune_system_information().duration_for_naive << "\t";
    std::cout << Model::CONFIG->immune_system_information().duration_for_fully_immune << "\t";
}

void AgeGroup2To10Reporter::print_moi_distribution() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int i = 0; i < Model::DATA_COLLECTOR->multiple_of_infection_by_location()[location].size(); i++) {
            std::cout << Model::DATA_COLLECTOR->multiple_of_infection_by_location()[location][i] << "\t";
        }
    }

}

void AgeGroup2To10Reporter::print_mean_immune_by_location_age_class() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << Model::DATA_COLLECTOR->total_immune_by_location_age_class()[location][ac] / Model::DATA_COLLECTOR->popsize_by_location_age_class()[location][ac] << "\t";
        }
    }
}

void AgeGroup2To10Reporter::print_popsize_by_age_class() {

    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << Model::DATA_COLLECTOR->popsize_by_location_age_class()[location][ac] << "\t";
        }
    }

    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < 99; ac++) {
            std::cout << Model::DATA_COLLECTOR->cumulative_clinical_episodes_by_location_age()[location][ac] << "\t";
        }
    }



}