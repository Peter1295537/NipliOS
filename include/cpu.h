#ifndef CPU_H
#ifndef PROCESS_H
#include "process_class.h"
#endif

//#ifndef SYSTEM_H
//#endif
class system;

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
		system* sys;

	public:
		processor();
		int run(int, system*);
		int load(process*);
		int calculate(int);
		process* yield(process*);
		bool isInteruptable();

};
#define CPU_H
//#include "system.h"
#endif
