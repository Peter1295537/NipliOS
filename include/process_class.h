#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <errno.h>
#include <cstdlib>
#include <ctime>


using namespace std;
class process{

	public:
		enum state_t{
			NEW,
			READY,
			RUN,
			WAIT,
			EXIT
		};
		process(string,int);
		process();
		vector<int> request;
		string buff;
		int getPID();
	 	int getTimeElapsed();
		int getTimeRemaining();
		int getMemory();
		int getPriority();
		int getRequests();
		int run(int);
	 	int setState(state_t);
		int currentLeft;
		int ioComplete();
		bool isCritical;
		string getName();
		state_t getState();
		bool hasResources;
		string nextInstruction();
		string popInstruction();

	private:
		vector<string> script;
	 	int timeRemaining;
	 	int timeElapsed;
	 	int pid;
	 	int memory;
	 	int priority;
	 	int numrequests;
		int complete;
		static int sem1;
		static int sem2;
		static int sem3;
		static int sem4;
		int sem;
		string name;
		state_t state;
		string filename;



};
#define PROCESS_H
