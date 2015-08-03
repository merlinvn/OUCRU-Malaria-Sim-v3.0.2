/* 
 * File:   Reporter.cpp
 * Author: Merlin
 * 
 * Created on August 1, 2013, 12:05 PM
 */

#include "Reporter.h"
#include "ConsoleReporter.h"
#include "GuiReporter.h"
#include "AMUReporter.h"
#include "FarmReporter.h"
#include "MultipleLocationGuiReporter.h"
#include "AgeGroup2To10Reporter.h"

Reporter::Reporter() : model_(NULL) {
}

Reporter::Reporter(const Reporter &orig) {
}

Reporter::~Reporter() {
}

Reporter *Reporter::MakeReport(ReportType report_type) {

    switch (report_type) {
        case CONSOLE:
            return new ConsoleReporter();
        case GUI:
            return new GuiReporter();
        case AMU:
            return new AMUReporter();
        case FARM:
            return new FarmReporter();
        case MULTIPLE_LOCATION:
            return new MultipleLocationGuiReporter();
        case AGE_GROUP_2_TO_10:
            return new AgeGroup2To10Reporter();
        default:
            return new ConsoleReporter();
            break;
    }
    return NULL;
}