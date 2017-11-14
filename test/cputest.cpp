#include "../include/cpu.h"
using namespace std;

int main(){
	process test("../data/process_template.xml",66589);
	processor cpu;
	cpu.load(&test);
	cout << test.getTimeRemaining() << endl;
	cpu.calculate(50);
	cout << test.getTimeRemaining() << endl;
	return 0;
}
