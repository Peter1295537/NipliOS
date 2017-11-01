#include <iostream>
#include <string>
using namespace std;
class process{

	private:
		enum state_t{
			NEW,
			READY,
			RUN,
			WAIT,
			EXIT
		};
	public:
		process(string filename);
		int getPID();
		int getTimeRemaining();
		int getTimeElapsed();
		int getMemory();
		int getPriority();
		int getNumRequests();
		int * getRequests();
		char * getName();
		state_t getState();
};
//process::process(const char* filename);
