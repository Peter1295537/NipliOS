#include <vector>
using namespace std;
#ifndef PROCESS_H
#include "process_class.h"
#endif

class io_device_mgr{
	public:
		io_device_mgr(vector<process*>*,vector<string>*);
		int requestIO(process*);
		int freeIO(process*);
		int requestOut(process*);

	private:
		vector<process*>* WAIT;
		vector<string>* buffer;
		bool out;
		int io_devices;
		int allocateIO(process*);
};
#define IODEVICE_H
