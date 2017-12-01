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
		vector<int>(5) available;
		int** max;
		int** allocation
		int** need;
		int allocateIO(process*);
		int isSafe();
};
#define IODEVICE_H
