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
		process(string,int);
		process();
		int getPID();
	 	int getTimeRemaining();
	 	int getTimeElapsed();
		int getMemory();
		int getPriority();
		int getRequests();
		int run(int);
	 	int setState(state_t);
		string getName();
		state_t getState();

	private:
	 	int timeRemaining;
	 	int timeElapsed;
	 	int pid;
	 	int memory;
	 	int priority;
	 	int numrequests;
		string name;
		state_t state;
		xmlDocPtr doc;
		xmlNodePtr root;
		xmlNodePtr node;
		string filename;



};

