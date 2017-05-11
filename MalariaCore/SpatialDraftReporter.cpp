#include "SpatialDraftReporter.h"

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
#include "PersonIndexAll.h"
#include "SpatialStructure.h"
#include "Barabasi.h"
#include <iostream>
#include <fstream>

SpatialDraftReporter::SpatialDraftReporter() : last_reported_NTF_(0), last_reported_clinical_episodes_(0), last_reported_mutants_(0) {
}

SpatialDraftReporter::SpatialDraftReporter(const SpatialDraftReporter& orig) {
}

SpatialDraftReporter::~SpatialDraftReporter() {
}

void SpatialDraftReporter::initialize() {
}

void SpatialDraftReporter::before_run() {
    std::cout << Model::RANDOM->seed() << std::endl;
}

void SpatialDraftReporter::after_run() {
    Model::DATA_COLLECTOR->update_after_run();

    //output parameter: initial pop_size and beta
    output_parameters();

    //output others indicators
    // NTF
    print_ntf_by_location();

    // time resistance reaches 1%
    print_resistance_tracker_by_location();
    
    // EIR - 20x
    print_EIR_by_location();

    std::cout << std::endl;

}

void SpatialDraftReporter::begin_time_step() {
}

void SpatialDraftReporter::after_time_step() {

    if (Model::SCHEDULER->current_time() % Model::CONFIG->report_frequency() == 0) {
//        Model::DATA_COLLECTOR->perform_population_statistic();

        std::cout << Model::SCHEDULER->current_time() << "\t";
        
//        print_NTF_in_60_days_window();
        
//        print_prevalence_by_location();
        
//        std::cout << "-1111" << "\t";
        
        for (int from_loc = 0; from_loc < Model::CONFIG->number_of_locations(); from_loc++) {
            for (int to_loc = 0; to_loc < Model::CONFIG->number_of_locations(); to_loc++) {
                std::cout << Model::CONFIG->v_distance_by_location()[from_loc][to_loc] << "\t";
            }
        }
        
        std::cout << "-1111" << "\t";
        
        std::cout << "-1111" << "\t";
        
        for (int loc = 0; loc < Model::CONFIG->number_of_locations(); loc++) {
            std::cout << Model::DATA_COLLECTOR->incidence_by_location()[loc] << "\t";
        }
        
        std::cout << std::endl;
    }
}

void SpatialDraftReporter::output_parameters() {
//    std::cout << boost::format("%1%\t%2%\t")
//            % Model::RANDOM->seed()
//            % Model::CONFIG->number_of_locations();

//    //initial population size
//    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
//        std::cout << Model::CONFIG->population_size_by_location()[location] << "\t";
//    }
//    std::cout << "-1111" << "\t";
//    
//    // final population size
//    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
//        std::cout << Model::DATA_COLLECTOR->popsize_by_location()[location] << "\t";
//    }
//    std::cout << "-1111" << "\t";
    
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::CONFIG->beta()[location] << "\t";
    }
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_ntf_by_location() {
    double total_time_in_years = (Model::SCHEDULER->current_time() - Model::CONFIG->start_collect_data_day()) / 365.0;
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        double location_discounted_NTF = Model::DATA_COLLECTOR->cumulative_discounted_NTF_by_location()[location] * 100 / (double) Model::DATA_COLLECTOR->popsize_by_location()[location];
        double NTF = Model::DATA_COLLECTOR->cumulative_NTF_by_location()[location] * 100 / (double) Model::DATA_COLLECTOR->popsize_by_location()[location];
        location_discounted_NTF /= total_time_in_years;
        NTF /= total_time_in_years;
//        std::cout << location_discounted_NTF << "\t";
        std::cout << NTF << "\t";
    }
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_EIR_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->EIR_by_location()[location] << "\t";
    }
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_20x_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->percentage_bites_on_top_20_by_location()[location] * 100 << "\t";
    }
}

void SpatialDraftReporter::print_EAMU() {
    std::cout << Model::DATA_COLLECTOR->AMU_per_parasite_pop() << "\t";
    std::cout << Model::DATA_COLLECTOR->AMU_per_person() << "\t";
    std::cout << Model::DATA_COLLECTOR->AMU_for_clinical_caused_parasite() << "\t";
    std::cout << Model::DATA_COLLECTOR->AFU() << "\t";
}

void SpatialDraftReporter::print_prevalence_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        double prevalence = 0.0;
        for (int i = 0; i < 10; i++) {
            prevalence += Model::DATA_COLLECTOR->last_10_blood_slide_prevalence_by_location()[location][i];
        }
        std::cout << prevalence / 10.0 << "\t";
    }
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_fraction_of_positive_that_are_clinical_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        double f_clinical = 0.0;
        for (int i = 0; i < 10; i++) {
            f_clinical += Model::DATA_COLLECTOR->last_10_fraction_positive_that_are_clinical_by_location()[location][i];
        }
        std::cout << f_clinical / 10.0 << "\t";
    }

}

void SpatialDraftReporter::print_mean_immune_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->total_immune_by_location()[location] / Model::DATA_COLLECTOR->popsize_by_location()[location] << "\t";
    }
}

void SpatialDraftReporter::print_mean_number_of_clones_per_positive_individual() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        unsigned long totalClones = Model::DATA_COLLECTOR->total_parasite_population_by_location()[location];
        int count = Model::DATA_COLLECTOR->number_of_positive_by_location()[location];
        double r = (count == 0) ? 0 : (totalClones / (double) count);
        std::cout << r << "\t";
    }

}

void SpatialDraftReporter::print_mean_number_of_clones_per_positive_individual_by_age_group() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            unsigned long totalClones = Model::DATA_COLLECTOR->total_parasite_population_by_location_age_group()[location][ac];
            int count = Model::DATA_COLLECTOR->number_of_positive_by_location_age_group()[location][ac];
            double r = (count == 0) ? 0 : (totalClones / (double) count);
            std::cout << r << "\t";
        }
    }
}

void SpatialDraftReporter::print_death_by_age_group() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {

            std::cout << Model::DATA_COLLECTOR->number_of_death_by_location_age_group()[location][ac] << "\t";
        }
    }
}

void SpatialDraftReporter::print_number_of_clinical_episode_by_age_class() {
    double total_time_in_years = (Model::SCHEDULER->current_time() - Model::CONFIG->start_collect_data_day()) / 365.0;
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << (Model::DATA_COLLECTOR->cumulative_clinical_episodes_by_location_age_group()[location][ac] / (double) Model::DATA_COLLECTOR->popsize_by_location_age_class()[location][ac]) / total_time_in_years << "\t";
        }
    }
}

void SpatialDraftReporter::print_prevalence_by_age_class() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << Model::DATA_COLLECTOR->blood_slide_prevalence_by_location_age_group()[location][ac] << "\t";
        }
    }
}

void SpatialDraftReporter::print_fraction_of_positive_that_are_clinical_by_location_age_class() {
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

void SpatialDraftReporter::print_fraction_of_positive_that_are_clinical_by_location_age_class_by_5() {
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

void SpatialDraftReporter::print_resistance_tracker() {
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().any_double_tracking_time()[i] << "\t";
//    }
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().all_double_tracking_time()[i] << "\t";
//    }
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().any_triple_tracking_time()[i] << "\t";
//    }
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().all_triple_tracking_time()[i] << "\t";
//    }
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().any_quadruple_tracking_time()[i] << "\t";
//    }
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().all_quadruple_tracking_time()[i] << "\t";
//    }
    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->resistance_tracker().total_tracking_time()[i] << "\t";
    }
//    for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().tracking_values().size(); i++) {
//        std::cout << Model::DATA_COLLECTOR->resistance_tracker().artemisinin_tracking_time()[i] << "\t";
//    }
    
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_resistance_tracker_by_location() {
    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); loc++) {
            for (int i = 0; i < Model::DATA_COLLECTOR->resistance_tracker().total_tracking_time_by_location()[loc].size(); i++) {
                std::cout << Model::DATA_COLLECTOR->resistance_tracker().total_tracking_time_by_location()[loc][i] << "\t";
            }
        }
        std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_treatments_by_therapy() {
    for (int i = 0; i < Model::CONFIG->strategy()->therapy_list().size(); i++) {
        int t_id = Model::CONFIG->strategy()->therapy_list()[i]->id();
        int nTreaments = Model::DATA_COLLECTOR->number_of_treatments_with_therapy_ID()[t_id];
        int nSuccess = Model::DATA_COLLECTOR->number_of_treatments_success_with_therapy_ID()[t_id];
        int nFail = Model::DATA_COLLECTOR->number_of_treatments_fail_with_therapy_ID()[t_id];
        double pSuccess = (nTreaments == 0) ? 0 : nSuccess * 100.0 / nTreaments;

        std::cout << t_id << "\t" << nTreaments << "\t" << nFail + nSuccess << "\t" << pSuccess << "\t";

    }
}

void SpatialDraftReporter::print_total_utl() {
    std::cout << Model::DATA_COLLECTOR->current_utl_duration() << "\t";
}

void SpatialDraftReporter::print_utl() {
    for (int i = 0; i < Model::DATA_COLLECTOR->UTL_duration().size(); i++) {
        std::cout << Model::DATA_COLLECTOR->UTL_duration()[i] << "\t";
    }
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_LOI() {
    std::cout << Model::CONFIG->immune_system_information().duration_for_naive << "\t";
    std::cout << Model::CONFIG->immune_system_information().duration_for_fully_immune << "\t";
}

void SpatialDraftReporter::print_moi_distribution() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int i = 0; i < Model::DATA_COLLECTOR->multiple_of_infection_by_location()[location].size(); i++) {
            std::cout << Model::DATA_COLLECTOR->multiple_of_infection_by_location()[location][i] << "\t";
        }
    }

}

void SpatialDraftReporter::print_mean_immune_by_location_age_class() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        for (int ac = 0; ac < Model::CONFIG->number_of_age_classes(); ac++) {
            std::cout << Model::DATA_COLLECTOR->total_immune_by_location_age_class()[location][ac] / Model::DATA_COLLECTOR->popsize_by_location_age_class()[location][ac] << "\t";
        }
    }
}

void SpatialDraftReporter::print_popsize_by_age_class() {

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

// Giang's addition
void SpatialDraftReporter::print_pop_size_by_location() {
    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); loc++) {
        std::cout << Model::POPULATION->size(loc, -1) << "\t";
    }
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_total_parasite_population_count() {
    std::cout << Model::DATA_COLLECTOR->resistance_tracker().total() << "\t";
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_NTF_in_60_days_window() {
    double total_TF_60_all_locs = 0;
    for (int loc = 0; loc < Model::CONFIG->number_of_locations(); loc++) {
        total_TF_60_all_locs += Model::DATA_COLLECTOR->total_TF_60_all_locations()[loc];
    }
    std::cout << total_TF_60_all_locs << "\t";

    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_blood_slide_prevalence_all_locations() {
    double blood_slide_prevalence = 0;
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        blood_slide_prevalence += Model::DATA_COLLECTOR->number_of_positive_blood_slide_by_location()[location];
    }
    std::cout << blood_slide_prevalence / Model::POPULATION->all_persons()->vPerson().size() << "\t";
    std::cout << "-1111" << "\t";
}

void SpatialDraftReporter::print_blood_slide_prevalence_by_location() {
    for (int location = 0; location < Model::CONFIG->number_of_locations(); location++) {
        std::cout << Model::DATA_COLLECTOR->number_of_positive_blood_slide_by_location()[location] / Model::DATA_COLLECTOR->popsize_by_location()[location] << "\t";
    }
    std::cout << "-1111" << "\t";
}
