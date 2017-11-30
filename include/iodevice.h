#include <vector>
using namespace std;

class io_device_mgr{
	public:
		io_device_mgr();
		int requestIO(process*);
		int allocateIO(process*);
		int freeIO(process*);

	private:
		vector<process*> WAIT;
		int io_devices;
};
