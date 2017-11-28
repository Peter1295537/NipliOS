#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

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
		int getPID();
	 	int getTimeElapsed();
		int getTimeRemaining();
		int getMemory();
		int getPriority();
		int getRequests();
		int run(int);
	 	int setState(state_t);
		bool isCritical();
		string getName();
		state_t getState();
		bool hasResources();

	private:
		vector<string> script;
	 	int timeRemaining;
	 	int timeElapsed;
	 	int pid;
	 	int memory;
	 	int priority;
	 	int numrequests;
		string name;
		state_t state;
		string filename;
		bool resources;
		bool critical;
		int critsection_start;
		int critsection_end;



};
#endif
