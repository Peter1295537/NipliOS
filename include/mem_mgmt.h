#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bitset>
#ifndef MEM_H
#define MEM_H
//#ifndef PROCESS_H
#include "process_class.h"
#define SIZE 4096
using namespace std;

class memory{
	public:
		memory();
		int getTotalMemory();
		int getFreeMemory();
		int getUsedMemory();
		process* getProcess(int pid);
<<<<<<< HEAD
		void createProcess(string filename);
		int findBlock(process p);
		void allocate(int base, int limit);
		void free(int base, int limit);
		void resetProcesses();
=======
		void createProcess(string filename, int x);
		void resetProcesses(); 
>>>>>>> 6bc3b2a4efa4b85ce097c932db085092186f24d7
		int getNumProcesses();
	private:
		int procmem;
		process tmp;
		vector<process> processes;
		bitset<SIZE> mem;
};
#endif
