#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=UnitTest
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ACTIncreaseStrategy.o \
	${OBJECTDIR}/AMUReporter.o \
	${OBJECTDIR}/AdaptiveCyclingStrategy.o \
	${OBJECTDIR}/Barabasi.o \
	${OBJECTDIR}/BirthdayEvent.o \
	${OBJECTDIR}/BittingLevelGenerator.o \
	${OBJECTDIR}/BurninFarmReporter.o \
	${OBJECTDIR}/BurninMonthlyReporter.o \
	${OBJECTDIR}/CSVRow.o \
	${OBJECTDIR}/CirculateToTargetLocationNextDayEvent.o \
	${OBJECTDIR}/ClinicalUpdateFunction.o \
	${OBJECTDIR}/ClonalParasitePopulation.o \
	${OBJECTDIR}/Config.o \
	${OBJECTDIR}/ConsoleReporter.o \
	${OBJECTDIR}/CyclingStrategy.o \
	${OBJECTDIR}/Dispatcher.o \
	${OBJECTDIR}/Drug.o \
	${OBJECTDIR}/DrugDatabase.o \
	${OBJECTDIR}/DrugType.o \
	${OBJECTDIR}/DrugsInBlood.o \
	${OBJECTDIR}/EndClinicalByNoTreatmentEvent.o \
	${OBJECTDIR}/EndClinicalDueToDrugResistanceEvent.o \
	${OBJECTDIR}/EndClinicalEvent.o \
	${OBJECTDIR}/Event.o \
	${OBJECTDIR}/ExternalPopulation.o \
	${OBJECTDIR}/FarmReporter.o \
	${OBJECTDIR}/GeneralGravity.o \
	${OBJECTDIR}/GuiReporter.o \
	${OBJECTDIR}/ImmuneComponent.o \
	${OBJECTDIR}/ImmuneSystem.o \
	${OBJECTDIR}/ImmunityClearanceUpdateFunction.o \
	${OBJECTDIR}/ImportationEvent.o \
	${OBJECTDIR}/ImportationPeriodicallyEvent.o \
	${OBJECTDIR}/IndexHandler.o \
	${OBJECTDIR}/InfantImmuneComponent.o \
	${OBJECTDIR}/IntGenotype.o \
	${OBJECTDIR}/IntGenotypeDatabase.o \
	${OBJECTDIR}/MACTherapy.o \
	${OBJECTDIR}/MDAAction.o \
	${OBJECTDIR}/MFTStrategy.o \
	${OBJECTDIR}/MMC_Zambia.o \
	${OBJECTDIR}/MatureGametocyteEvent.o \
	${OBJECTDIR}/Model.o \
	${OBJECTDIR}/ModelDataCollector.o \
	${OBJECTDIR}/MonthlyReporter.o \
	${OBJECTDIR}/MonthlyReporterConsole.o \
	${OBJECTDIR}/MoveParasiteToBloodEvent.o \
	${OBJECTDIR}/MoveToExternalPopulationEvent.o \
	${OBJECTDIR}/MultipleLocationGuiReporter.o \
	${OBJECTDIR}/NonInfantImmuneComponent.o \
	${OBJECTDIR}/ParasiteDensityUpdateFunction.o \
	${OBJECTDIR}/Person.o \
	${OBJECTDIR}/PersonIndex.o \
	${OBJECTDIR}/PersonIndexAll.o \
	${OBJECTDIR}/PersonIndexAllHandler.o \
	${OBJECTDIR}/PersonIndexByLocationBittingLevel.o \
	${OBJECTDIR}/PersonIndexByLocationBittingLevelHandler.o \
	${OBJECTDIR}/PersonIndexByLocationExternalPopulationMovingLevel.o \
	${OBJECTDIR}/PersonIndexByLocationExternalPopulationMovingLevelHandler.o \
	${OBJECTDIR}/PersonIndexByLocationMovingLevel.o \
	${OBJECTDIR}/PersonIndexByLocationMovingLevelHandler.o \
	${OBJECTDIR}/PersonIndexByLocationStateAgeClass.o \
	${OBJECTDIR}/PersonIndexByLocationStateAgeClassHandler.o \
	${OBJECTDIR}/Phenotype.o \
	${OBJECTDIR}/Population.o \
	${OBJECTDIR}/ProgressToClinicalEvent.o \
	${OBJECTDIR}/Random.o \
	${OBJECTDIR}/ReceiveMDADrugEvent.o \
	${OBJECTDIR}/ReceiveTherapyEvent.o \
	${OBJECTDIR}/Reporter.o \
	${OBJECTDIR}/ResistanceTracker.o \
	${OBJECTDIR}/ReturnToNormalPopulationEvent.o \
	${OBJECTDIR}/ReturnToResidenceEvent.o \
	${OBJECTDIR}/SCTherapy.o \
	${OBJECTDIR}/SFTStrategy.o \
	${OBJECTDIR}/STCAction.o \
	${OBJECTDIR}/Scheduler.o \
	${OBJECTDIR}/SingleHostClonalParasitePopulations.o \
	${OBJECTDIR}/SpatialCombinedMFTCyclingStrategy.o \
	${OBJECTDIR}/SpatialDraftReporter.o \
	${OBJECTDIR}/SpatialMFTStrategy.o \
	${OBJECTDIR}/SpatialStructure.o \
	${OBJECTDIR}/Strategy.o \
	${OBJECTDIR}/SwitchImmuneComponentEvent.o \
	${OBJECTDIR}/TMEAction.o \
	${OBJECTDIR}/TMEActionFactory.o \
	${OBJECTDIR}/TMEScheduler.o \
	${OBJECTDIR}/TestTreatmentFailureEvent.o \
	${OBJECTDIR}/Therapy.o \
	${OBJECTDIR}/UpdateEveryKDaysEvent.o \
	${OBJECTDIR}/UpdateWhenDrugIsPresentEvent.o \
	${OBJECTDIR}/YearlyReporterV1.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmalariacore.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmalariacore.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmalariacore.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmalariacore.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmalariacore.a

${OBJECTDIR}/ACTIncreaseStrategy.o: ACTIncreaseStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ACTIncreaseStrategy.o ACTIncreaseStrategy.cpp

${OBJECTDIR}/AMUReporter.o: AMUReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AMUReporter.o AMUReporter.cpp

${OBJECTDIR}/AdaptiveCyclingStrategy.o: AdaptiveCyclingStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AdaptiveCyclingStrategy.o AdaptiveCyclingStrategy.cpp


${OBJECTDIR}/Barabasi.o: Barabasi.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Barabasi.o Barabasi.cpp
${OBJECTDIR}/BirthdayEvent.o: BirthdayEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BirthdayEvent.o BirthdayEvent.cpp

${OBJECTDIR}/BittingLevelGenerator.o: BittingLevelGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BittingLevelGenerator.o BittingLevelGenerator.cpp

${OBJECTDIR}/BurninFarmReporter.o: BurninFarmReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BurninFarmReporter.o BurninFarmReporter.cpp

${OBJECTDIR}/BurninMonthlyReporter.o: BurninMonthlyReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BurninMonthlyReporter.o BurninMonthlyReporter.cpp

${OBJECTDIR}/CSVRow.o: CSVRow.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CSVRow.o CSVRow.cpp

${OBJECTDIR}/CirculateToTargetLocationNextDayEvent.o: CirculateToTargetLocationNextDayEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CirculateToTargetLocationNextDayEvent.o CirculateToTargetLocationNextDayEvent.cpp

${OBJECTDIR}/ClinicalUpdateFunction.o: ClinicalUpdateFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClinicalUpdateFunction.o ClinicalUpdateFunction.cpp

${OBJECTDIR}/ClonalParasitePopulation.o: ClonalParasitePopulation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClonalParasitePopulation.o ClonalParasitePopulation.cpp

${OBJECTDIR}/Config.o: Config.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Config.o Config.cpp

${OBJECTDIR}/ConsoleReporter.o: ConsoleReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConsoleReporter.o ConsoleReporter.cpp

${OBJECTDIR}/CyclingStrategy.o: CyclingStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CyclingStrategy.o CyclingStrategy.cpp

${OBJECTDIR}/Dispatcher.o: Dispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dispatcher.o Dispatcher.cpp

${OBJECTDIR}/Drug.o: Drug.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drug.o Drug.cpp

${OBJECTDIR}/DrugDatabase.o: DrugDatabase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DrugDatabase.o DrugDatabase.cpp

${OBJECTDIR}/DrugType.o: DrugType.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DrugType.o DrugType.cpp

${OBJECTDIR}/DrugsInBlood.o: DrugsInBlood.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DrugsInBlood.o DrugsInBlood.cpp

${OBJECTDIR}/EndClinicalByNoTreatmentEvent.o: EndClinicalByNoTreatmentEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EndClinicalByNoTreatmentEvent.o EndClinicalByNoTreatmentEvent.cpp

${OBJECTDIR}/EndClinicalDueToDrugResistanceEvent.o: EndClinicalDueToDrugResistanceEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EndClinicalDueToDrugResistanceEvent.o EndClinicalDueToDrugResistanceEvent.cpp

${OBJECTDIR}/EndClinicalEvent.o: EndClinicalEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EndClinicalEvent.o EndClinicalEvent.cpp

${OBJECTDIR}/Event.o: Event.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Event.o Event.cpp

${OBJECTDIR}/ExternalPopulation.o: ExternalPopulation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExternalPopulation.o ExternalPopulation.cpp

${OBJECTDIR}/FarmReporter.o: FarmReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FarmReporter.o FarmReporter.cpp

${OBJECTDIR}/GeneralGravity.o: GeneralGravity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GeneralGravity.o GeneralGravity.cpp

${OBJECTDIR}/GuiReporter.o: GuiReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GuiReporter.o GuiReporter.cpp

${OBJECTDIR}/ImmuneComponent.o: ImmuneComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ImmuneComponent.o ImmuneComponent.cpp

${OBJECTDIR}/ImmuneSystem.o: ImmuneSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ImmuneSystem.o ImmuneSystem.cpp

${OBJECTDIR}/ImmunityClearanceUpdateFunction.o: ImmunityClearanceUpdateFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ImmunityClearanceUpdateFunction.o ImmunityClearanceUpdateFunction.cpp

${OBJECTDIR}/ImportationEvent.o: ImportationEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ImportationEvent.o ImportationEvent.cpp

${OBJECTDIR}/ImportationPeriodicallyEvent.o: ImportationPeriodicallyEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ImportationPeriodicallyEvent.o ImportationPeriodicallyEvent.cpp

${OBJECTDIR}/IndexHandler.o: IndexHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IndexHandler.o IndexHandler.cpp

${OBJECTDIR}/InfantImmuneComponent.o: InfantImmuneComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InfantImmuneComponent.o InfantImmuneComponent.cpp

${OBJECTDIR}/IntGenotype.o: IntGenotype.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IntGenotype.o IntGenotype.cpp

${OBJECTDIR}/IntGenotypeDatabase.o: IntGenotypeDatabase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IntGenotypeDatabase.o IntGenotypeDatabase.cpp

${OBJECTDIR}/MACTherapy.o: MACTherapy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MACTherapy.o MACTherapy.cpp

${OBJECTDIR}/MDAAction.o: MDAAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MDAAction.o MDAAction.cpp

${OBJECTDIR}/MFTStrategy.o: MFTStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MFTStrategy.o MFTStrategy.cpp

${OBJECTDIR}/MMC_Zambia.o: MMC_Zambia.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MMC_Zambia.o MMC_Zambia.cpp

${OBJECTDIR}/MatureGametocyteEvent.o: MatureGametocyteEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MatureGametocyteEvent.o MatureGametocyteEvent.cpp

${OBJECTDIR}/Model.o: Model.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Model.o Model.cpp

${OBJECTDIR}/ModelDataCollector.o: ModelDataCollector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModelDataCollector.o ModelDataCollector.cpp

${OBJECTDIR}/MonthlyReporter.o: MonthlyReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MonthlyReporter.o MonthlyReporter.cpp

${OBJECTDIR}/MonthlyReporterConsole.o: MonthlyReporterConsole.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MonthlyReporterConsole.o MonthlyReporterConsole.cpp

${OBJECTDIR}/MoveParasiteToBloodEvent.o: MoveParasiteToBloodEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MoveParasiteToBloodEvent.o MoveParasiteToBloodEvent.cpp

${OBJECTDIR}/MoveToExternalPopulationEvent.o: MoveToExternalPopulationEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MoveToExternalPopulationEvent.o MoveToExternalPopulationEvent.cpp

${OBJECTDIR}/MultipleLocationGuiReporter.o: MultipleLocationGuiReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MultipleLocationGuiReporter.o MultipleLocationGuiReporter.cpp

${OBJECTDIR}/NonInfantImmuneComponent.o: NonInfantImmuneComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NonInfantImmuneComponent.o NonInfantImmuneComponent.cpp

${OBJECTDIR}/ParasiteDensityUpdateFunction.o: ParasiteDensityUpdateFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ParasiteDensityUpdateFunction.o ParasiteDensityUpdateFunction.cpp

${OBJECTDIR}/Person.o: Person.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Person.o Person.cpp

${OBJECTDIR}/PersonIndex.o: PersonIndex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndex.o PersonIndex.cpp

${OBJECTDIR}/PersonIndexAll.o: PersonIndexAll.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexAll.o PersonIndexAll.cpp

${OBJECTDIR}/PersonIndexAllHandler.o: PersonIndexAllHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexAllHandler.o PersonIndexAllHandler.cpp

${OBJECTDIR}/PersonIndexByLocationBittingLevel.o: PersonIndexByLocationBittingLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationBittingLevel.o PersonIndexByLocationBittingLevel.cpp

${OBJECTDIR}/PersonIndexByLocationBittingLevelHandler.o: PersonIndexByLocationBittingLevelHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationBittingLevelHandler.o PersonIndexByLocationBittingLevelHandler.cpp

${OBJECTDIR}/PersonIndexByLocationExternalPopulationMovingLevel.o: PersonIndexByLocationExternalPopulationMovingLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationExternalPopulationMovingLevel.o PersonIndexByLocationExternalPopulationMovingLevel.cpp

${OBJECTDIR}/PersonIndexByLocationExternalPopulationMovingLevelHandler.o: PersonIndexByLocationExternalPopulationMovingLevelHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationExternalPopulationMovingLevelHandler.o PersonIndexByLocationExternalPopulationMovingLevelHandler.cpp

${OBJECTDIR}/PersonIndexByLocationMovingLevel.o: PersonIndexByLocationMovingLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationMovingLevel.o PersonIndexByLocationMovingLevel.cpp

${OBJECTDIR}/PersonIndexByLocationMovingLevelHandler.o: PersonIndexByLocationMovingLevelHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationMovingLevelHandler.o PersonIndexByLocationMovingLevelHandler.cpp

${OBJECTDIR}/PersonIndexByLocationStateAgeClass.o: PersonIndexByLocationStateAgeClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationStateAgeClass.o PersonIndexByLocationStateAgeClass.cpp

${OBJECTDIR}/PersonIndexByLocationStateAgeClassHandler.o: PersonIndexByLocationStateAgeClassHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PersonIndexByLocationStateAgeClassHandler.o PersonIndexByLocationStateAgeClassHandler.cpp

${OBJECTDIR}/Phenotype.o: Phenotype.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Phenotype.o Phenotype.cpp

${OBJECTDIR}/Population.o: Population.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Population.o Population.cpp

${OBJECTDIR}/ProgressToClinicalEvent.o: ProgressToClinicalEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProgressToClinicalEvent.o ProgressToClinicalEvent.cpp

${OBJECTDIR}/Random.o: Random.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Random.o Random.cpp

${OBJECTDIR}/ReceiveMDADrugEvent.o: ReceiveMDADrugEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReceiveMDADrugEvent.o ReceiveMDADrugEvent.cpp

${OBJECTDIR}/ReceiveTherapyEvent.o: ReceiveTherapyEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReceiveTherapyEvent.o ReceiveTherapyEvent.cpp

${OBJECTDIR}/Reporter.o: Reporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Reporter.o Reporter.cpp

${OBJECTDIR}/ResistanceTracker.o: ResistanceTracker.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ResistanceTracker.o ResistanceTracker.cpp

${OBJECTDIR}/ReturnToNormalPopulationEvent.o: ReturnToNormalPopulationEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReturnToNormalPopulationEvent.o ReturnToNormalPopulationEvent.cpp

${OBJECTDIR}/ReturnToResidenceEvent.o: ReturnToResidenceEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ReturnToResidenceEvent.o ReturnToResidenceEvent.cpp

${OBJECTDIR}/SCTherapy.o: SCTherapy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SCTherapy.o SCTherapy.cpp

${OBJECTDIR}/SFTStrategy.o: SFTStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SFTStrategy.o SFTStrategy.cpp

${OBJECTDIR}/STCAction.o: STCAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/STCAction.o STCAction.cpp

${OBJECTDIR}/Scheduler.o: Scheduler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Scheduler.o Scheduler.cpp

${OBJECTDIR}/SingleHostClonalParasitePopulations.o: SingleHostClonalParasitePopulations.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SingleHostClonalParasitePopulations.o SingleHostClonalParasitePopulations.cpp

${OBJECTDIR}/SpatialCombinedMFTCyclingStrategy.o: SpatialCombinedMFTCyclingStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpatialCombinedMFTCyclingStrategy.o SpatialCombinedMFTCyclingStrategy.cpp

${OBJECTDIR}/SpatialDraftReporter.o: SpatialDraftReporter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpatialDraftReporter.o SpatialDraftReporter.cpp

${OBJECTDIR}/SpatialMFTStrategy.o: SpatialMFTStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpatialMFTStrategy.o SpatialMFTStrategy.cpp

${OBJECTDIR}/SpatialStructure.o: SpatialStructure.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpatialStructure.o SpatialStructure.cpp

${OBJECTDIR}/Strategy.o: Strategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Strategy.o Strategy.cpp

${OBJECTDIR}/SwitchImmuneComponentEvent.o: SwitchImmuneComponentEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SwitchImmuneComponentEvent.o SwitchImmuneComponentEvent.cpp

${OBJECTDIR}/TMEAction.o: TMEAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TMEAction.o TMEAction.cpp

${OBJECTDIR}/TMEActionFactory.o: TMEActionFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TMEActionFactory.o TMEActionFactory.cpp

${OBJECTDIR}/TMEScheduler.o: TMEScheduler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TMEScheduler.o TMEScheduler.cpp

${OBJECTDIR}/TestTreatmentFailureEvent.o: TestTreatmentFailureEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestTreatmentFailureEvent.o TestTreatmentFailureEvent.cpp

${OBJECTDIR}/Therapy.o: Therapy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Therapy.o Therapy.cpp

${OBJECTDIR}/UpdateEveryKDaysEvent.o: UpdateEveryKDaysEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/UpdateEveryKDaysEvent.o UpdateEveryKDaysEvent.cpp

${OBJECTDIR}/UpdateWhenDrugIsPresentEvent.o: UpdateWhenDrugIsPresentEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/UpdateWhenDrugIsPresentEvent.o UpdateWhenDrugIsPresentEvent.cpp

${OBJECTDIR}/YearlyReporterV1.o: YearlyReporterV1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DUNITTEST=\"True\" -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/YearlyReporterV1.o YearlyReporterV1.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmalariacore.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
