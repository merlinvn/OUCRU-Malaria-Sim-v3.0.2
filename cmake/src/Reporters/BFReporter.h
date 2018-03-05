//
// Created by Nguyen Tran on 3/5/2018.
//

#ifndef POMS_BFREPORTER_H
#define POMS_BFREPORTER_H


#include "Reporter.h"

class BFReporter : public Reporter {
DISALLOW_COPY_AND_ASSIGN_(BFReporter)

public:
    BFReporter();
    virtual ~BFReporter();

    void initialize() override;

    void before_run() override;

    void after_run() override;

    void begin_time_step() override;

    void after_time_step() override;
};


#endif //POMS_BFREPORTER_H
