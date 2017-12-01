#include "../include/iodevice.h"


io_device_mgr::io_device_mgr(vector<process*>* queue, vector<string>* buf){
	WAIT=queue;
	buffer=buf;
	available.push_back(2);
	available.push_back(3);
	available.push_back(4);
	available.push_back(5);
	available.push_back(7);
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
	if(isSafe(p)){
		
		p->hasResources = true;
		for(int i=0;i<5;i++){
			available[i]-=p->request[i];
		}
		for(int i=0;i<WAIT->size();i++){
			if((*WAIT)[i]==p){
				for(int j=0;j<5;j++){
					allocation[i][j]+=p->request[i];
					need[i][j]-=p->request[i];
				}
			}
		}
		
	return 0;
	}
	return 1;
}
int io_device_mgr::freeIO(process* p){
	p->hasResources=false;
	for(int i=0;i<5;i++){
		available[i]+=p->request[i];
	}
	for(int i=0;i<WAIT->size();i++){
		if((*WAIT)[i]==p){
			WAIT->erase(WAIT->begin()+i);
			free(max[i]);
			free(allocation[i]);
			free(need[i]);
			}
		}
	go=true;
}
int io_device_mgr::requestOut(process* p){
	buffer->push_back(p->buff);
}
bool io_device_mgr::isSafe(process* p){
	int index;
	for(index=0;index<WAIT->size() && (*WAIT)[index]!=p;index++){
		continue;
	}
	//make copies of the sets
	vector<int> _available = available;
	int** _allocation = allocation;
	int** _need = need;
	int s = WAIT->size();
	//allocate resources
	for(int i=0;i<p->request.size();i++){
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
int io_device_mgr::getSize(){
	return WAIT->size();
}
process* io_device_mgr::getProcAtIndex(int i){
	return (*WAIT)[i];
}


