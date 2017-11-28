#include <vector>
#include "../include/process_class.h"

using namespace std;

class system{
	private:
		vector<process*> blocked;
		int size;
		int cycle;
		int resource_instances;


	public:
		int requestIO(process*,int);
		int useIO(process*,int);
		int freeIO(process*,int);
		process* nextProcess();
		int getWaitSize();
		int getCycle();
		int run(int);
};
