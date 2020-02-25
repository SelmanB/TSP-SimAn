#ifndef TSP_ROUTE_H
#define TSP_ROUTE_H

#include <cstring>
#include <cstdlib>
#include <cfloat>
#include <iostream>

using namespace std;
typedef float dist;
#define DIST_MAX FLT_MAX

class route{
public:
	route(int _n,dist **matrix);
	~route();
	void setOrder(const int* arr);
	void greedy(int start);
	route neighbor(unsigned int seed1, unsigned int seed2, unsigned int seed3);
	void print();
	void printObj();
	void printOrder();
	void eval();
	route& operator=(const route& rval);
	dist Obj(){return obj;}
	int n;
	int *order;			//connectivity list order[i]=j means route goes from i to j
	dist obj;			//Objective function
	dist **distances;	//Distance matrix, [i][j] means i to j
};

#endif
