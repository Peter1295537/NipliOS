#include "../include/process_class.h"


using namespace std;
process::process(){
	state = state_t(NEW);
	pid=0;
	timeElapsed=0;

}
process::process(string filename, int process_id){
	state = state_t(NEW);
	pid=process_id;
	timeElapsed=0;
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
		else if(nodename.compare("memory_requirement")==0){
			xmlChar* content = xmlNodeGetContent(node);
			memory = atoi((char*)content);
		}
		else if(nodename.compare("cycles_remaining")==0){
			xmlChar* content = xmlNodeGetContent(node);
			timeRemaining=atoi((char*)content);
		}
		else if(nodename.compare("io_reqs")==0){
			xmlChar* content = xmlNodeGetContent(node);
			numrequests=atoi((char*)content);
		}
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
 int process::getRequests(){
	return numrequests;
}
 string process::getName(){
	return name;
}
process::state_t process::getState(){
	return state;
}

int process::run(int cycles){
	while(timeRemaining>0 && cycles>0){
		--timeRemaining;
		++timeElapsed;
		--cycles;
	}
		return timeRemaining;
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
