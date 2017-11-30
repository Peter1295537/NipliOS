#include "../include/iodevice.h"
io_device_mgr::io_device_mgr(vector<process*>* queue, vector<string>* buf){
	out=true;
	io_devices = 5;	
	WAIT=queue;
	buffer=buf;
}
int io_device_mgr::requestIO(process* p){
	WAIT->push_back(p);
}
int io_device_mgr::allocateIO(process* p){
	p->hasResources = true;
	io_devices -= p->request;
	
}
int io_device_mgr::freeIO(process* p){
	p->hasResources=false;
	io_devices += p->request;
}
int io_device_mgr::requestOut(process* p){
	*buffer.push_back(p->buff);
}
