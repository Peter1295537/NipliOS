#include<stdlib.h>
#include<iostream>

using namespace std;

class memory{
	public:
		memory();
		int getTotalMemory();
		int getFreeMemory();
		int getMemory();
		//void allocateProcess(process);
	private:
		int used;
		bool mainmem[];
};
