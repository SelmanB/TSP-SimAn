#include "route.h"

	int minDist(const dist *list,const bool *visited,int n){
		dist lim=DIST_MAX;
		register int res=-1;
		for(int i=0;i<n;i++)
			if(list[i]<lim && !visited[i]){
				lim=list[i];
				res=i;
			}
		return res;
	}

	route::route(int _n,dist **matrix){
		distances=matrix;
		this->n=_n;
		order=(int*)malloc(n*sizeof(int));
	}

	route::~route(){
		free(order);
	}

	void route::setOrder(const int* arr){
		memcpy(order,arr,n*sizeof(int));
		eval();

	}

	void route::greedy(int start){
		int index=start;
		bool visited[n]={false};
		visited[start]=true;
		for(int i=1;i<n;i++){
			order[index]=minDist(distances[index],visited,n);
			index=order[index];
			visited[index]=true;
		}
			order[index]=start;
		eval();
	}

	route& route::operator=(const route& rval){
		memcpy(this->order,rval.order,n*sizeof(int));
		this->obj=rval.obj;
	}

	route route::neighbor(unsigned int seed1, unsigned int seed2, unsigned int seed3){
		route res(n,distances);
		unsigned int index1= seed1 % n;
		unsigned int i2= seed2 % n, index2;
		unsigned int i3= seed3 % n, index3;
		memcpy(res.order,this->order,n*sizeof(int));
		res.obj=this->obj;
		if(index1==i2 || i2==i3 || index1==i3)return res;

		bool cw;
		int pos=index1;
		while(true){
			pos=order[pos];
			if(pos==i2){
				cw=true;
				break;
			}
			if(pos==i3){
				cw=false;
				break;
			}
		}

		if(cw){
			index2=i2;
			index3=i3;
		}else{
			index2=i3;
			index3=i2;
		}
		
		
		int t1=order[index1],t2=order[index2],t3=order[index3];
		if(index1==t2 || index2==t3 || index3==t1)return res;//check if the result is permissible
		
		//swap
		res.obj-=this->distances[index1][res.order[index1]];
		res.obj-=this->distances[index2][res.order[index2]];
		res.obj-=this->distances[index3][res.order[index3]];

		res.order[index1]=t2;
		res.order[index2]=t3;
		res.order[index3]=t1;

		res.obj+=this->distances[index1][res.order[index1]];
		res.obj+=this->distances[index2][res.order[index2]];
		res.obj+=this->distances[index3][res.order[index3]];
		return res;
	}

	void route::print(){
		cout<<"CONNECTIVITY:"<<endl;
		for(int i=0;i<n;i++)
			cout<<i<<':'<<order[i]<<"	("<<distances[i][order[i]]<<")"<<endl;
		cout<<endl<<"OBJECTIVE:"<<obj<<endl;
	}
	void route::printObj(){
		cout<<"Objective:"<<obj<<endl;
	}
	void route::printOrder(){
		cout<<"Order: 0";
		int pos=order[0];
		while(pos!=0){
			cout<<"; "<<pos;
			pos=order[pos];
		}
		cout<<endl;

	}
	void route::eval(){
		obj=0;
		int pos=0;
		for(int i=0;i<n;i++){
			obj+=distances[pos][order[pos]];
			pos=order[pos];
		}
	}


