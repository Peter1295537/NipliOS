#include <iostream>
#include <vector>
#include "../include/pagetable.h"
using namespace std;

pagetable::pagetable(int pages, int frames){
	pagesStored = 0;
	vector<pte> table;
	vector<int> freeFrames;
	table.resize(pages); //vector of page entries
	for(int i = frames - 1; i >= 0; i--){
		freeFrames.push_back(i);
	}
}

bool pagetable::isValid(int pageNum){
	return this->table[pageNum].valid;
}

void pagetable::accessPage(int pageNum){
	cout << "Page " << pageNum << " found at frame " << table[pageNum].frameNumber << endl;
}

void pagetable::storePage(int pageNum){ //FIFO page replacement
	int frametmp; //temporary frame var
	if(freeFrames.empty()){
	int swapPage = selectVictim(); //number of page to be swapped
	table[swapPage].valid = false;
	frametmp = table[swapPage].frameNum;
	cout << "Page Fault: Swapping page " << pageNum << " in frame " << frametmp << endl;
	}
	else{
	frametmp = freeFrames.back();
	freeFrames.pop_back();
	cout << "Page Fault: Inserting page " << pageNum << " in frame " << frametmp << endl;
	}
	table[pageNum].frameNum = frametmp;
	table[pageNum].time = pagesStored; //sets time to number of pages stored at time of insertion
	table[pageNum].valid = true;
	pagesStored++;
}

int pagetable::selectVictim(){ //returns number of oldest page in table
	int victimNum;
	int victimTime = pagesStored; 
	for(int i = 0; i<table.size(); i++){
		if(table[i].valid && table[i].time < victimTime){
		victimTime = table[i].time;
		victimNum = i;
		}
	
	}
	return victimNum; 
}

