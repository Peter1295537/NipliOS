#include "../include/queue.h"



queue::queue(){
        front= NULL;
        back= NULL;
	size=0;
}

void queue::insert(int input) {
	node *tmp;
	tmp= new (struct node);
	if (input>=0) {
		tmp->data=input;
		tmp->next=NULL;
		if (front==NULL) {
			front=tmp;
		}
		else {
			back->next=tmp;
		}
		back=tmp;
		size++;
	}
}

int queue::remove() {
	node *tmp;
	int output;
	if (front == NULL) {
		return -1;			
	}
	else {
		size--;	
		tmp=front;
		if (front==back) {
			front=NULL;
			back=NULL;
			return tmp->data;
		}
		else {
			front=tmp->next;
			output=tmp->data;
			free(tmp);
			return output;
		}
	}
	
}
int queue::current() {
	node *tmp;
	int output;
	if (front ==NULL) {
		return -1;
	}
	else {
		tmp=front;
		output=tmp->data;
		return(output);
	}
}

int queue::getSize() {
	return size;
}

 
