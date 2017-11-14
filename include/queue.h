#include<stdlib.h>
#include<iostream>

//Header for queue class for NipliOS

using namespace std;





class queue {
	
        public:
		struct node{
        		int data;
        		struct node *next;
		}*front, *back;

                void insert(int);
                int remove();
                int current();
                queue();

};



