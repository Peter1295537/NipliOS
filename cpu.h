#include <stdio>
#include "process_class.h"
using namespace std;

class processor{
	private:
		process current;

	public:
		int load(process);
		int calculate(int);
		process yield(process);
		int io(int);
		int out(string);

}


