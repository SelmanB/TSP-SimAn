#include "route.h"
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "siman.h"

int main(){
	int n=101;

	dist** d=(dist**)malloc(n*sizeof(dist*));
	for(int i=0;i<n;i++)
	d[i]=(dist*)malloc(n*sizeof(dist));

	ifstream xin("x101.dat"), yin("y101.dat");

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
		bestRoute.obj=999999.0;
	r.setOrder(arr);
	r.printObj();

	int seed=104;
	srand(seed);


	// for(int i=0;i<10000000;i++){
	// 	int r1=random(),r2=random(),r3=random();
	// 	route n=r.neighbor(r1,r2,r3);
	// 	if((i%100000)==0)r.printObj();
	// 	if(n.obj<r.obj){
	// 		r=n;
	// 	}
	// }
	float temp=200;
	for(int i=0;i<160;i++){
		iterate<route>(&r,&bestRoute,400000,temp);
		temp=temp*0.95;
		r.printObj();
	}
	cout<<"Best Objective"<<endl;
	bestRoute.printOrder();
	bestRoute.print();
	cout<<"seed="<<seed<<endl;

	return 0;
}