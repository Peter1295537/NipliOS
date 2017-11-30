#include "../include/iodevice.h"
io_device_mgr::io_device_mgr(vector<process*>* queue, vector<string>* buf){
	WAIT=queue;
	buffer=buf;
	available[0]=2;
	available[1]=3;
	available[2]=4;
	available[3]=5;
	available[4]=7;
}
int io_device_mgr::requestIO(process* p){
	WAIT->push_back(p);
	int s = WAIT->size();
	for(int i=0;i<5;i++){
		allocation[s-1][i]=0;
		max[s-1][i]=p->request[i];
		need[s-1][i]=max[s-1][i] - allocation[s-1][i];
	}
}
int io_device_mgr::allocateIO(process* p){
	p->hasResources = true;
	for(int i=0;i<5;i++){
		available[i]+=p->request[i];
	}
	
}
int io_device_mgr::freeIO(process* p){
	p->hasResources=false;
	io_devices += p->request;
}
int io_device_mgr::requestOut(process* p){
	*buffer.push_back(p->buff);
}
bool isSafe(process* p, int index){
	//make copies of the sets
	vector<int> _available = available;
	int** _allocation = allocation;
	int** _need = need;
	//int s = WAIT->size();
	//allocate resources
	for(int i=0;i<p->request->size();i++){
		_available[i] -= p->request[i];
		_allocation[index][i] = _allocation[index][i] + p->request[i];
		_need[index][i] = _need[index][i] - p->request[i];
	}
	//check if safe
	vector<int> work = available;
	vector<bool> finish(s,false);

	for(int i=0;i<s;i++){
		for(int j=0;j<5;j++){
			if(!finish[i] && need[i][j]<=work[j]){
				for(int k=0;k<5;k++){
					work[k]= work[k]+_allocation[i][k];
				}	
				finish[i]=true;
			}	
		}
	}
	for(int i=0;i<s;i++){
		if(finish[i]==false){
			return false;
		}	
	}
	return true;
}

