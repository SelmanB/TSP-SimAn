# TSP-SimAn

## Building
There is a makefile in `/src` directory that includes build information using `g++` compiler. On a Unix compatible system, one can use the command to build the project:

`make`

## Usage
Call the executable named tsp with these parameters as the following:
`./tsp <n> <Xfile> <Yfile> <Tmax> <Tmin> <Iters> [<seed>]`

Description of which are:
* `<n>` number of cities
* `<Xfile>` input file containing x-coordinates of the cities
* `<Yfile>` input file containing y-coordinates of the cities
* `<Tmax>` starting temperature for simulated annealing
* `<Tmin>` ending temperature for simulated annealing
* `<Iters>` total number of iterations
* `<seed>` (optional) input seed for pseudo-random number generator

## Input file format
See the example input files `x10.dat` and `y10.dat` for the format. Note that the cities must be ordered by their tokens in order

## Algorithm
Simulated Annealing using Boltzmann-like hill-climbing probability (`~exp(-dE/T)`) with geometrically decreasing temperature coefficient is employed for a single searching element. Neighbor function for a feasible path is permutation of 3 sub-paths of the loop without reversing individual sub-paths.

## Output
100 intermediate solutions are printed with current temperature at regular intervals. After the execution, information about the optimum solution is printed which includes a connectivity list with cost of each connection, the objective function, and the ordering of cities in the tour. Also, the random seed used is printed to allow reproducible reporting.
