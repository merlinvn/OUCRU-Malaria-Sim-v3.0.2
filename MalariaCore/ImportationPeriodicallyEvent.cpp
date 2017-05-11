/* 
 * File:   ImportationEvent.cpp
 * Author: Merlin
 * 
 * Created on February 21, 2014, 2:42 PM
 */

#include "ImportationPeriodicallyEvent.h"
#include "Model.h"
#include "Population.h"
#include "ImmuneSystem.h"
#include "ClonalParasitePopulation.h"
#include "Config.h"
#include "PersonIndexAll.h"
#include "Random.h"
#include "ModelDataCollector.h"
#include "PersonIndexByLocationStateAgeClass.h"

OBJECTPOOL_IMPL(ImportationPeriodicallyEvent)

ImportationPeriodicallyEvent::ImportationPeriodicallyEvent(const int& location, const int& duration, const int& genotype_id, const int& number_of_cases) : location_(location), duration_(duration), genotype_id_(genotype_id), number_of_cases_(number_of_cases) {

}

ImportationPeriodicallyEvent::ImportationPeriodicallyEvent(const ImportationPeriodicallyEvent& orig) {
}

ImportationPeriodicallyEvent::~ImportationPeriodicallyEvent() {
}

void ImportationPeriodicallyEvent::schedule_event(Scheduler* scheduler, const int& location, const int& duration, const int& genotype_id, const int& number_of_cases) {
    if (scheduler != NULL) {
        ImportationPeriodicallyEvent* e = new ImportationPeriodicallyEvent(location, duration, genotype_id, number_of_cases);
        //        e->set_dispatcher(p);
        e->set_dispatcher(NULL);
        e->set_executable(true);
        e->set_time(Model::SCHEDULER->current_time() + duration);

        //        p->add(e);
        scheduler->schedule(e);

    }

}

void ImportationPeriodicallyEvent::execute() {
    schedule_event(Model::SCHEDULER, location_, duration_, genotype_id_, number_of_cases_);
    if (Model::DATA_COLLECTOR->popsize_by_location_hoststate()[0][0] < 10) {
        return;
    }

    int number_of_importation_cases = Model::RANDOM->random_poisson(number_of_cases_);
//    std::cout << number_of_cases_ << std::endl;
    PersonIndexByLocationStateAgeClass* pi = Model::POPULATION->get_person_index<PersonIndexByLocationStateAgeClass>();

    for (int i = 0; i < number_of_importation_cases; i++) {

        int ind_ac = Model::RANDOM->random_uniform(pi->vPerson()[0][0].size());
        if (pi->vPerson()[0][0][ind_ac].size() == 0) {
            continue;
        }
        int index = Model::RANDOM->random_uniform(pi->vPerson()[0][0][ind_ac].size());
        Person* p = pi->vPerson()[0][0][ind_ac][index];

        p->immune_system()->set_increase(true);
        p->set_host_state(Person::ASYMPTOMATIC);

        ClonalParasitePopulation* blood_parasite = p->add_new_parasite_to_blood(Model::CONFIG->genotype_db()->get(genotype_id_));
        //    std::cout << "hello"<< std::endl;

        double size = Model::CONFIG->log_parasite_density_level().log_parasite_density_asymptomatic;

        blood_parasite->set_gametocyte_level(Model::CONFIG->gametocyte_level_full());
        blood_parasite->set_last_update_log10_parasite_density(size);
        blood_parasite->set_update_function(Model::MODEL->immunity_clearance_update_function());

        //        Model::POPULATION->initial_infection(pi->vPerson()[0][0][ind_ac][index], Model::CONFIG->parasite_db()->get(0));
    }

}