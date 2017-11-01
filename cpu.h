#include <stdio>
#include "process_class.h"
using namespace std;

class processor{
	private:
		int cores;
		int cache[];
		int registers[];
		int uptime;

	public:
		int getNumCores();
		int dumpCache();
		int dumpRegisters();
		int getUpTime();
		
		int Process(process,int,int[]);
		int swap(process,process,int); //integer for interrupt signal
		int schedule(process);

}


int getNumCores(){

};
int dumpCache(){

}
int dumpRegisters(){

}
int getUpTime(){

}
		
int Process(process,int,int[]){

}
int swap(process,process,int){ //integer for interrupt signal

}
int schedule(process);{

}
