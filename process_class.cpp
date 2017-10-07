#include <string>
#include <iostream>

using namespace std

class process{

	private int timeRemaining;
	private int timeElapsed=0;
	private int pid;
	private int memory;
	private int priority;
	private int numrequests;
	requests = new int[numrequests];
	private enum string{
		"NEW"
		"READY"
		"RUN"
		"WAIT"
		"EXIT"
	}state;
	private string name;

	public int getPID(){
		return pid;
	}
	public int getTimeRemaining(){
		return timeRemaining;
	}
	public int getTimeElapsed(){
		return timeElapsed;
	}
	public int getMemory(){
		return memory;
	}
	public int getPriority(){
		return priority;
	}
	public int getNumRequests(){
		return numrequests;
	}
	public int[] getRequests(){
		return requests;
	}
	public string getName(){
		return name;
	}
	public string getState(){
		return state;
	}

	public int run(int cycles){
		if(timeRemaining>0){
			timeRemaining-=cycles;
			timeElapsed+=cycles;
			return 0;
		}
			return 1;
	}
	public int setState(string state){
		return string=state;
	}


}

process::process(char* filename){
	xmlDocPtr doc;
	xmlNodePtr root;
	xmlNodePtr node;

	doc=xmlParseFile(filename);
	if(!doc){
		cout << "document parsing failed"
			
	}

	root = xmlDocGetRootElement(doc);

	node = root.children;

	while(node=node.next){
		char* content = xmlNodeGetContent(node);
		switch(node.name){
			case "process_name":
				name = (const char*)content;
				break;
			case "pid":
				pid = (int)content;
				break;
			case "memory_requirement":
				memory = (int)content;
				break;
			case "cycles_remaining":
				timeRemaining=(int)content;
				break;
			case "io":
				xmlNodePtr ioreqs = node.children;
				int numreqs=0;
				break;
			case "process_state":
				state=(const char*)node;
				break;
			case "priority":
				priority=(int)content;
				break;
			default:
				break;

				
		}
	}
	
		
}


