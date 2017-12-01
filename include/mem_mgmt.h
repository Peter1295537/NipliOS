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
		void createProcess(string filename, int x);
		void resetProcesses(); 
		int getNumProcesses();
	private:
		int procmem;
		process tmp;
		vector<process> processes;
		bitset<SIZE> mem;
};
#endif
