#ifndef CPU_H

#ifndef PROCESS_H
#include "process_class.h"
#endif
#ifndef IODEVICE_H
#include "iodevice.h"
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
		int run(int,io_device_mgr*);
		int load(process*);
		int calculate(int,io_device_mgr*);
		process* yield(process*);
		bool isInteruptable();

};
#define CPU_H
#endif
