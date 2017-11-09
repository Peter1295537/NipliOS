#include <stdio.h>
#include "process_class.h"
using namespace std;
enum state_t{
	NEW,
	READY,
	RUN,
	WAIT,
	EXIT
};
class processor{
	private:
		process* current;
		int numcores;

	public:
		processor();
		int load(process);
		int calculate(int);
		process yield(process);
		process io(int);
		int out(string);

};


