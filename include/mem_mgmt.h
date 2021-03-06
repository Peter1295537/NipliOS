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
		int findBlock();
		void createProcess(string filename, int x);
		void allocate(int base, int limit);
		void free(int base, int limit);
		void resetProcesses();
		int getNumProcesses();
	private:
		int procmem;
		int freecount;
		process tmp;
		vector<process> processes;
		bitset<SIZE> mem;
};
#endif
