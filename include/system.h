#include "../include/process_class.h"
#include "../include/queue.h"

using namespace std;

class system{
	private:
		queue blocked;
		int size;
		int cycle;


	public:
		int blockInsert(process*);
		int blockRemove(process*);
		int getSize();
		int getCycle();
		int run(int);
};
