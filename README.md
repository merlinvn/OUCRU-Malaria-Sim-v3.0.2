# OUCRU Malaria Sim v3.0.2

"OUCRU Malaria Sim" is an individual-based microsimulation of malaria transmission developed in C++.  The folders MalariaCore and MalariaSimulation contain the source code and input files that are needed to compile and run the simulation.  The simulation was designed to compare multiple different ways of distributing antimalarial drugs in a human population.

This version of the simulation includes transmission between hosts (without explicit implementation of mosquitoes), within-host parasite development, explicit modeling of parasite density and its effects on transmission, multi-clonal infections in hosts, pharmacokinetics, pharmacodynamics, mutation to multiple types of drug-resistant genotypes, symptomatic and asymptomatic infection, age-dependent immune acquisition, variation in host biting rates (without explicit implementation of mosquitoes), and multiple types of population-level drug deployment strategies. 

This version of the simulation was used to generate the results published in 

   Optimal population‐level deployment of artemisinin combination therapies.
   Nguyen TD, Olliaro P, Dondorp AM, Baird JK, Lam HM, Farrar J, Thwaites GE, White NJ, Boni MF.
   Lancet Global Heath, in press, 2015.
   
In the individual Figure folders in this repository you will find the raw simulation outputs that were used to generate the figures in this paper.
