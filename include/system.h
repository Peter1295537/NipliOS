#include <vector>
#include "../include/process_class.h"
#include "../include/mem_mgmt.h"

using namespace std;

class system{
	private:
		vector<process*> WAIT;
		vector<process*> NEW;
		vector<process*> READY;
		vector<process*> EXIT;

		queue ready_queue;
		queue fore_ground;
		queue back_ground;

		int counter = 0;

		processor processor1;
		memory mainmem;

		rr ready(25);
		rr fore(50);

		int start=0;


	public:
		int spawn(string);
		int kill(process*,string);
		int addReady(process*);
		int requestIO(process*);
		int useIO(process*);
		int freeIO(process*);
		process* next();
		int run(int,system*);
};
