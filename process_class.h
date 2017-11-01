#include <string>
#include <iostream>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>


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
		process(string);
		process();
		//~process();
		int getPID();
	 	int getTimeRemaining();
	 	int getTimeElapsed();
		int getMemory();
		int getPriority();
		int getNumRequests();
		int * getRequests();
		string getName();
		state_t getState();
		int run(int cycles);
	 	int setState(state_t newstate);

	private:
	 	int timeRemaining;
	 	int timeElapsed = 0;
	 	int pid;
	 	int memory;
	 	int priority;
	 	int numrequests;
	 	int* requests;
		string name;
		state_t state = state_t(NEW);;
		xmlDocPtr doc;
		xmlNodePtr root;
		xmlNodePtr node;
		string filename;



};

