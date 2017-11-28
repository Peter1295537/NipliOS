#include "../include/process_class.h"

int main(){
	string filename = "data/process_template";
	process test(filename,14627);
	//cout << "name: " << test.getName() << endl;
	cout << "timeRemaining: " << test.getTimeRemaining() << endl;
	cout << "memory usage: " << test.getMemory() << endl;
	return 0;	
}
