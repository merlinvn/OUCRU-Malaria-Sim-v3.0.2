# POMS - the Penn State OUCRU Malaria Simulation

This malaria simulation was developed at the Oxford University Clinical Research Unit from 2009 to 2016.  Since 2016, development has continued at the Center for Infectious Disease Dynamics (CIDD) at Pennsylvania State University.

The original name for this GitHub project was "OUCRU-Malara-Sim-v3.0.2".  This version of the simulation was used to generate the results published in 

   Optimal population‐level deployment of artemisinin combination therapies.
   Nguyen TD, Olliaro P, Dondorp AM, Baird JK, Lam HM, Farrar J, Thwaites GE, White NJ, Boni MF.
   Lancet Global Heath, 3(12)-e758-e766, 2015.
   
In the individual Figure folders in this repository you will find the raw simulation outputs that were used to generate the figures in this paper.

To see newer versions of the simulation, click on the 'Braches' button on the main repository page and select a newer branch.

POMS is an individual-based microsimulation of malaria transmission developed in C++.  The folders MalariaCore and MalariaSimulation contain the source code and input files that are needed to compile and run the simulation.  The simulation was designed to compare multiple different ways of distributing antimalarial drugs in a human population.

:: Most recent update - Oct 27 2017

The most recent version of the simulation includes transmission between hosts (without explicit implementation of mosquitoes), within-host parasite development, explicit modeling of parasite density and its effects on transmission, multi-clonal infections in hosts, basic pharmacokinetics, basic pharmacodynamics, mutation to multiple types of drug-resistant genotypes, symptomatic and asymptomatic infection, age-dependent immune acquisition, variation in host biting rates (without explicit implementation of mosquitoes), and multiple types of population-level drug deployment strategies. 


Below, you will find instructions for compiling and running the simulation.  Please contact Tran Dang Nguyen (nguyentd@oucru.org) or Maciej Boni (maciej.boni@ndm.ox.ac.uk) if you have any questions about the steps below.


::::::::::

COMPILING

::::::::::


The simulation uses a the cmake library to create make files for Linux, Mac, and Windows.  The instructions below are for Linux compilation and you will need to adjust some things for Windows or Mac compiling.

1. You need to have the system C++ compiler installed.  We recommend the GNU g++ compiler.

2. You will need to install the BOOST libraries (www.boost.org).  We used version 1.57 of the BOOST libraries for development, but there should not be any compatibility issues with future versions.  Please let us know if you find any.

On Linux, if you have the apt tool insalled (Ubuntu has this by default), you can install BOOST by 
 
  sudo apt-get install libboost-dev
  
  or
  
  apt-get install libboost-dev
  
depending on what permissions you have on your system.  If the above doesn't work for some reason, try installing "libboost-all-dev".

On Mac, you can install the BOOST libraries with HomeBrew.

3.  You will need to install the YAML markup language library

On Linux,

  sudo apt-get install libyaml-cpp-dev
  
And on Mac use HomeBrew,

4.  You will need to install the GSL library (www.gnu.org/software/gsl/).  Again, for Linux:

  sudo apt-get install libgsl-dev

and use HomeBrew on Mac.

5.  You will need to install the cmake library.  Again, for Linux:

  sudo apt-get install cmake

and use HomeBrew on Mac.


6.  You should now be able to build the executable with the following steps

6a. After you have cloned or downloaded the source code repository, in the main root folder type


  cd cmake
  mkdir build
  cd build
  cmake ..
  
and this should generate the makefiles that you will need for compilation

6b. Now type

  make -j 1

You can substitute "-j 2" or "-j 3" above if you want to use more than one processor for building the project.  The build should just take a few minutes.  Hopefully, you will not see any error messages.

6c. Now type

  cd bin
  ./MaSim
  
and this should display some messages to the console telling you how the executable file "MaSim" should be used and what options you can place on the command line.





::::::::::

RUNNING

::::::::::


7. If you're a this stage, you're in luck.  Everything should work.

  go into the MalariaSimulation folder (off of the root folder) and choose one of the .yml files.  These are input files that contain all of the simulation's parameters.
  
  copy your chosen input file into the same folder as the "MaSim" executable.
  
  type



6

  ./dist/Release/GNU-Linux-x86/malariasimulation
  
and this will show you a list of usage modes.

Type

  ./dist/Release/GNU-Linux-x86/malariasimulation -c sample_input_file.yml 
  
to run the simulation with the sample input set of parameters provided.  This runs the simulation for two years (after a burn-in stage of 11 years) on a population of 100,000 individuals.  This should take between 1 and 4 minutes, depending on your hardware.

Note that many of the variables are not reported during the burn-in stage (first 4000 days) when the dynamics settle to an endemic equilibrium.  The first line of the output is the random number seed, and the last line is a list of summary statistics.  The remainder of the output is divided into these twenty columns.

1. 	time (day)
2. 	days of Artemisinin Monotherapy Use (AMU) - note that this can be a non-integer; see supplementary materials in 2015 LGH paper
3. 	Number of Treatment Failures (NTF) - discounted
4. 	NTF - non-discounted
5. 	NTF over the last 30 days - discounted
6. 	Clinical episodes over the last 30 days
7. 	Number of drug-resistance mutation events that occured in the last 30 days
8.  	fraction of clonal parasite populations that have exactly one resistance mutation
9.	fraction of clonal parasite populations that have exactly two resistance mutations
10.	fraction of clonal parasite populations that have exactly three resistance mutations
11.	fraction of clonal parasite populations that have exactly four resistance mutations
12.	fraction of clonal parasite populations that have the artemisinin resistance mutation
13.	"total resistance" - a number between zero and one that gives you the probability that a parasite population will be resistant to an individual drug, if the parasite population and the drug are chosen randomly (see supplementary appendix to 2015 LGH paper)

14.	Placeholder text

15.	Blood-slide prevalence, across all ages
16.	Blood-slide prevalence, 2-10 age group
17.	Blood-slide prevalence, 10-15 age group
18.	Blood-slide prevalence, 15-45 age group

19.	EIR over the past 365 days (this will be zero for the first year of the simulation)
20.	Multiplicity of Infection (MOI) - this is the mean MOI over infected hosts


