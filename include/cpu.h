#ifndef CPU_H

#ifndef PROCESS_H
#include "process_class.h"
#endif

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
		int run(int);
		int load(process*);
		int calculate(int);
		process* yield(process*);
		bool isInteruptable();

};
#define CPU_H
#endif
