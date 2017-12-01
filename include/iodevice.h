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
		bool go;
		bool isSafe(process*);
		int allocateIO(process*);
		int getSize();
		process* getProcAtIndex(int);

	private:
		vector<process*>* WAIT;
		vector<string>* buffer;
		vector<int> available;
		int** max;
		int** allocation;
		int** need;
};
#define IODEVICE_H
