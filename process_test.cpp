#include "process_class.h"

int main(){
	string filename = "process_template.xml";
	process test(filename);
	cout << "name: " << test.getName() << endl;
	cout << "pid: " << test.getPID() << endl;
	return 0;	
}