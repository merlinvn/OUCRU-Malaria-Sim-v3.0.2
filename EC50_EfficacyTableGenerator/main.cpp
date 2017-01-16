/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Merlin
 *
 * Created on January 12, 2017, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "Model.h"
#include "Config.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Model* m = new Model();
    m->set_initial_seed_number(-1);
    m->config_filename() = "input.yml";
    m->initialize();
    std::cout << "start:" << std::endl;
    for (const auto& genotype : Model::CONFIG->genotype_db()->db()) {
        auto g = genotype.second;
        std::cout << *(g) << "\t"
                << Model::CONFIG->drug_db()->get(1)->inferEC50(g)
                << std::endl;
    }

    //
    //    m->run();
    delete m;
    m = NULL;
    return 0;
}

