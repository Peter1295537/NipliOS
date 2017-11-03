#include<stdlib.h>
#include<iostream>

//Header for queue class for NipliOS

using namespace std;


//Node structure for queue
//struct node
//{
//        int data;
//        struct node *next;
//}*front, *back;



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



