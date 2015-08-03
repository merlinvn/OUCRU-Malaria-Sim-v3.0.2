#include <iostream>
#include <fakeit.hpp>

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"


using namespace std;

int main(int argc, char **argv) {
    // global setup...

    int result = Catch::Session().run(argc, argv);

    // global clean-up...


    return result;
}