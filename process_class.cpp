#include "process_class.h"


using namespace std;
process::process(string filename){
	state = state_t(NEW);
	doc=xmlParseFile(filename.c_str());
	if(doc==NULL){
		cout << "document parsing failed";
	}

	root = xmlDocGetRootElement(doc);

	node = root->children;

	do{
		string nodename = (char*)node->name;
		if(nodename.compare("process_name")==0){
			xmlChar* content = xmlNodeGetContent(node);
			name = (char*)content;
		}
		else if(nodename.compare("pid")==0){
			xmlChar* content = xmlNodeGetContent(node);
			pid = atoi((const char*)content);
		}
		else if(nodename.compare("memory_requirement")==0){
			xmlChar* content = xmlNodeGetContent(node);
			memory = atoi((char*)content);
		}
		else if(nodename.compare("cycles_remaining")==0){
			xmlChar* content = xmlNodeGetContent(node);
			timeRemaining=atoi((char*)content);
		}
		else if(nodename.compare("io")==0){
			int numreqs = atoi((char*)xmlGetProp(node, (xmlChar*)"numrequests"));
			int reqs[numreqs];

			xmlNodePtr ioreq = node->children;
			for(int i=0;i<numreqs;i++){
				ioreq=ioreq->next;
				reqs[i]=atoi((char*)xmlNodeGetContent(ioreq));
			}

			numrequests=numreqs;
			requests=reqs;
		}
		/*else if(node->name==(xmlChar*)"process_state"){
			state= state_t((const char*)content);
		}*/
		else if(nodename.compare("priority")==0){
			xmlChar* content = xmlNodeGetContent(node);
			priority=atoi((char*)content);
		}
		else{
			continue;
		}

				
		}while(node=node->next);
	xmlFreeDoc(doc);
}
int process::getPID(){
	return pid;
}
int process::getTimeRemaining(){
	return timeRemaining;
}
 int process::getTimeElapsed(){
	return timeElapsed;
}
 int process::getMemory(){
	return memory;
}
 int process::getPriority(){
	return priority;
}
 int process::getNumRequests(){
	return numrequests;
}
int * process::getRequests(){
	return requests;
}
 string process::getName(){
	return name;
}
process::state_t process::getState(){
	return state;
}

int process::run(int cycles){
	if(timeRemaining>0){
		timeRemaining-=cycles;
		timeElapsed+=cycles;
		return 0;
	}
		return 1;
}
int process::setState(state_t newstate){
	return state=newstate;
}
	
		
/*process::~process(){
	cout << "deconstructing";
	free(requests);
	free((void*)name);
	free(&timeRemaining);
	free(&timeElapsed);
	free(&pid);
	free(&memory);
	free(&priority);
	free(&numrequests);
	free(&state);
}
*/
