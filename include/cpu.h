#include <stdio.h>
//#include "process_class.h"
#include "queue.h"
#include "system.h"
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
		bool preempt;

	public:
		processor();
		int run(int,system*);
		int load(process*);
		int calculate(int);
		process* yield(process*);
		bool isInteruptable();

};


