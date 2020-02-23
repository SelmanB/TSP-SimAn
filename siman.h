#include "route.h"
#include <cstdlib>
#define err 1.0

template <typename Soln>
void iterate(Soln *sol, Soln *best,int count, float temperature){
	for(int i=0;i<count;i++){
		unsigned int x=random(),y=random(),z=random();
		Soln n=sol->neighbor(x,y,z);
		if (n.Obj() < err) continue;
		if(n.Obj()<sol->Obj()){
			if(n.Obj()<best->Obj()) *best=n;
			*sol=n;
		}else{ 
			float ran=((float)random())/((float)RAND_MAX);
			float prob=exp((sol->Obj()-n.Obj())/temperature);
			if(ran<prob) {
				//cout<<"entered:"<<ran<<" "<<prob<<endl;
				*sol=n;
			}
		}
	}
}

