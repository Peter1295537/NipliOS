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
		int getPidCounter();
		process* getProcess(int pid);
		void createProcess(string filename);
		void resetProcesses(); 
		int getNumProcesses();
	private:
		int pidCounter;
		int procmem;
		process tmp;
		vector<process> processes;
		bitset<SIZE> mem;
};
#endif
