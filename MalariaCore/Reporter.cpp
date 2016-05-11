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
#include "YearlyReporterV1.h"
#include "Model.h"
#include "Random.h"
#include "MonthlyReporter.h"
#include <boost/format.hpp>
#include <string>

Reporter::Reporter() : model_(NULL) {
}

Reporter::Reporter(const Reporter& orig) {
}

Reporter::~Reporter() {
}

Reporter* Reporter::MakeReport(ReportType report_type) {
    std::string file_name1 = boost::str(boost::format("yearly_data_%1%_%2%.txt")
            % Model::RANDOM->seed()
            % Model::MODEL->override_parameter_line_number());
    
    std::string file_name2 = boost::str(boost::format("monthly_data.txt"));
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
        case YEARLY_REPORTER_V1:
            return new YearlyReporterV1(file_name1);
        case MONTHLY_REPORTER:
            return new MonthlyReporter(file_name2);
        default:
            return new ConsoleReporter();
            break;
    }
    return NULL;
}