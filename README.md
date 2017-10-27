### POMS - Penn State OUCRU Malaria Simulation

This malaria simulation was developed at the Oxford University Clinical Research Unit from 2009 to 2016.  Since 2016, development has continued at the Center for Infectious Disease Dynamics (CIDD) at Pennsylvania State University.

The original name for this GitHub project was "OUCRU-Malara-Sim-v3.0.2".  This version of the simulation was used to generate the results published in 

   Optimal population‐level deployment of artemisinin combination therapies.
   Nguyen TD, Olliaro P, Dondorp AM, Baird JK, Lam HM, Farrar J, Thwaites GE, White NJ, Boni MF.
   _Lancet Global Heath_, 3(12)-e758-e766, 2015.
   
In the individual Figure folders in this repository you will find the raw simulation outputs that were used to generate the figures in this paper.

To see newer versions of the simulation, click on the 'Braches' button on the main repository page and select a newer branch.

POMS is an individual-based microsimulation of malaria transmission developed in C++.  The folders MalariaCore and MalariaSimulation contain the source code and input files that are needed to compile and run the simulation.  The simulation was designed to compare multiple different ways of distributing antimalarial drugs in a human population.

#### Most recent update to this file - Oct 27 2017

The most recent version of the simulation includes transmission between hosts (without explicit implementation of mosquitoes), within-host parasite development, explicit modeling of parasite density and its effects on transmission, multi-clonal infections in hosts, basic pharmacokinetics, basic pharmacodynamics, mutation to multiple types of drug-resistant genotypes, symptomatic and asymptomatic infection, age-dependent immune acquisition, variation in host biting rates (without explicit implementation of mosquitoes), and multiple types of population-level drug deployment strategies. 

Below, you will find instructions for compiling and running the simulation.  Please contact Tran Dang Nguyen (nguyentd@oucru.org) or Maciej Boni (mfb9@psu.edu) if you have any questions about the steps below.



#### ::::::::::

### COMPILING

#### ::::::::::



The simulation uses a the cmake library to create make files for Linux, Mac, and Windows.  The instructions below are for Linux compilation and you will need to adjust some things for Windows or Mac compiling.

#### 1. C++ compiler

You need to have a C++ compiler installed.  We recommend the GNU g++ compiler.

#### 2. Install BOOST libraries

You will need to install the BOOST libraries (www.boost.org).  We used version 1.57 of the BOOST libraries for development, but there should not be any compatibility issues with future versions.  Please let us know if you find any.

On Linux, if you have the apt tool insalled (Ubuntu has this by default), you can install BOOST by 
 
`sudo apt-get install libboost-dev`
  
or
  
`apt-get install libboost-dev`
  
depending on what permissions you have on your system.  If the above doesn't work for some reason, try installing `libboost-all-dev`.

On Mac, you can install the BOOST libraries with HomeBrew.

#### 3. Install YAML library 

You will need to install the YAML markup language library

On Linux,

`sudo apt-get install libyaml-cpp-dev`
  
And on Mac use HomeBrew.

#### 4. Install GSL library 

You will need to install the GSL library (www.gnu.org/software/gsl/).  Again, for Linux:

`sudo apt-get install libgsl-dev`

and use HomeBrew on Mac.

#### 5.  Install cmake Library

`sudo apt-get install cmake`

and use HomeBrew on Mac.

#### 6.  You should now be able to build the executable with the following steps

**6a.** After you have cloned or downloaded the source code repository, in the main root folder type

  `cd cmake`
  
  `mkdir build`
  
  `cd build`
  
  `cmake ..`
  
and this should generate the makefiles that you will need for compilation

**6b.** Now type

`make -j 1`

You can substitute `-j 2` or `-j 3` above if you want to use more than one processor for building the project.  The build should just take a few minutes.  Hopefully, you will not see any error messages.

**6c.** Now type

  `cd bin`
  
  `./MaSim`
  
and this should display some messages to the console telling you how the executable file `MaSim` should be used and what options you can place on the command line.



#### ::::::::::

### RUNNING

#### ::::::::::


#### 7. If you're at this stage, you're in luck.  Everything should work.

Go into the MalariaSimulation folder (off of the root folder) and choose one of the .yml files.  These are input files that contain all of the simulation's parameters.
  
Copy your chosen input file into the same folder as the `MaSim` executable.
  
Type

`./MaSim -c input_file.yml > output.txt`

And this will write the output of the simulation to the file `output.txt`.

The first line of the output is the random number seed, and the last line is a list of summary statistics.  You should delete these lines if you plan on using this file to plot trajectories.

Column 1 in the output is the day of the simulation.  By default, output is recorded every 30 days.

Some columns show `-1111`.  These are divider columns.

After the first divider column, you will have two easy-to-plot columns: the blood-slide prevalence (percentage of the population, across all age groups, that are blood-slide positive for malaria) and the treatment failure rate (the fraction of all individuals over the past 60 days that have been recorded as a "treatment failure" 28 days after being treated for malaria).

We will be updating many branches over the next few months.  Please contact us if you are using any of these versions and need help with the output, compilation, or anything else.


