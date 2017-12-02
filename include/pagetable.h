#include <vector>
using namespace std;

class pagetable{
	public:
	pagetable(int pages, int frames);
	bool isValid(int pageNum);
	void accessPage(int pageNum);
	void storePage(int pageNum);
	int selectVictim();
	private:
	int pagesStored; //number of pages stored
	class pte{ //page table entry
		public:
		int frameNum;
		int time;
		bool valid;
		pte(){valid = false;}
	vector<pte> table;
	vector<int> freeFrames;
	//int selectVictim();
	};
};
