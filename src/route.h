#ifndef TSP_ROUTE_H
#define TSP_ROUTE_H

#include <cstring>
#include <cstdlib>
#include <iostream>
//#include <cstdint>
//#define LCG_A  	134775813
//#define LCG_C	1

using namespace std;
typedef float dist;


class route{
public:
	route(int _n,dist **matrix);
	~route();
	void setOrder(const int* arr);
	route neighbor(unsigned int seed1, unsigned int seed2, unsigned int seed3);
	void print();
	void printObj();
	void printOrder();
	void eval();
	route& operator=(const route& rval);
	dist Obj(){return obj;}
	//unsigned int random();
	//static uint32_t seed;
	int n;
	int *order;			//connectivity list order[i]=j means route goes from i to j
	dist obj;			//Objective function
	dist **distances;	//Distance matrix, [i][j] means i to j
};




#endif
