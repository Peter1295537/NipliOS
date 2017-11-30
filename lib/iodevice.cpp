#include "../include/iodevice.h"
io_device_mgr::io_device_mgr(){
	
}
int io_device_mgr::requestIO(process* p){
	WAIT.push_back(p);
}
int io_device_mgr::freeIO(process* p){
	p->hasResources=false;
}
