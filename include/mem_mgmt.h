#ifndef MEM_MGMT_H
#define MEM_MGMT_H
#include<stdlib.h>
#include<iostream>
#include<vector>
#include "process_class.h"
using namespace std;

class memory{
	public:
		memory();
		int getTotalMemory();
		int getFreeMemory();
		int getMemory();
		int getPidCounter();
		//process listProcesses()?
		process* getProcess(int pid);
		void createProcess(string filename);
		void resetProcesses(); 
		//void allocateProcess();
	private:
		int used;
		int pidCounter;
		process tmp;
		vector<process> processes;
		bool mainmem[];
};
#endif
