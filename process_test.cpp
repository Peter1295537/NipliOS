#include "process_class.h"

int main(){
	string filename = "process_template.xml";
	process test(filename,14627);
	cout << "name: " << test.getName() << endl;
	return 0;	
}
