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
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Model* m = new Model();
    m->set_initial_seed_number(-1);
    m->config_filename() = "input.yml";
    m->initialize();



    //
    //    m->run();
    delete m;
    m = NULL;
    return 0;
}

