#include "route.h"
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cfloat>
#include <ctime>
#include "siman.h"

int main(int argc, char** argv){
	if(argc!= 7 && argc!=8){
		cerr<<"Corrrect use: ./tsp <n> <Xfile> <Yfile> <Tmax> <Tmin> <Iters> [<seed>]"<<endl;
		exit(0);
	}
	int n=atoi(argv[1]);
	float tmax=atof(argv[4]);
	float tmin=atof(argv[5]);
	int iters=atoi(argv[6]);
	int seed;
	if(argc==8){
		seed=atoi(argv[7]);
	}else{
		seed=time(NULL);
	}

	dist** d=(dist**)malloc(n*sizeof(dist*));
	for(int i=0;i<n;i++)
	d[i]=(dist*)malloc(n*sizeof(dist));

	ifstream xin(argv[2]), yin(argv[3]);

	if(!xin){
		cerr<<"File \""<<argv[2]<<"\" could not be found."<<endl;
		exit(1);
	}
	if(!yin){
		cerr<<"File \""<<argv[3]<<"\" could not be found."<<endl;
		exit(1);
	}

	{//new scope for data input
		dist x[n], y[n], a; 
		for(int i=0;i<n;i++){
			xin>>a>>x[i];
			yin>>a>>y[i];
		}
		for(int f=0;f<n;f++)
			for(int t=0;t<n;t++)
				d[f][t]=sqrt((x[f]-x[t])*(x[f]-x[t]) + (y[f]-y[t])*(y[f]-y[t]));
	}


	int arr[n];
	for(int i=0;i<n-1;i++)
		arr[i]=i+1;
	arr[n-1]=0;
	route r(n,d);
	route bestRoute(n,d);
		bestRoute.obj=FLT_MAX;
	r.setOrder(arr);
	r.printObj();

	srand(seed);


	float temp=tmax;
	int count=iters/100;
	float k= (float) pow((double)tmin/(double)tmax,(double)1/100);
	for(int i=0;i<100;i++){
		iterate<route>(&r,&bestRoute,count,temp);
		cout<<"Objective:"<<r.Obj()<<"\tTemperature:"<<temp<<endl;
				temp=temp*k;
	}
	cout<<endl<<endl;
	cout<<"---BEST SOLUTION---"<<endl;
	bestRoute.print();
	cout<<endl;
	bestRoute.printOrder();
	cout<<"seed="<<seed<<endl;

	return 0;
}
