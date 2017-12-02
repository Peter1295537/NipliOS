#include <iostream>
#include <fstream>
#include "../include/pagetable.h"
using namespace std;

int main(){
	int frames = 3;
	int pages = 4;
	pagetable table(frames, pages);
	cout << "Enter sequence of pages: " << endl;
	int pageNum;
	cin >> pageNum;
	while(pageNum != -1){
		if (table.isValid(pageNum)){
			table.accessPage(pageNum);
		}
		else{
			table.storePage(pageNum);
			table.accessPage(pageNum);
		}
		cin >> pageNum;
	}	
		
return 0;
}
