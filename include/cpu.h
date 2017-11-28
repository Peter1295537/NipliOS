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
		int load(process*);
		int calculate(int);
		process* yield(process*);
		process* io(int);
		int out(string);
		bool isInteruptable();

};


