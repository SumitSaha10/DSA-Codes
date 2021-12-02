#include<stdio.h>
#include<stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
	
struct Node{
	int data;
	struct Node *next;
};

void traversal(struct Node *f){
	struct Node *ptr = f;
	while(ptr!=NULL){
		printf("Element is : %d\n",ptr->data);
		ptr = ptr->next;
	}
}
int isFull(struct Node *n){
	if(n==NULL){
		return 1;
	}
	return 0;
}

int isEmpty(struct Node *f){
	if(f==NULL){
		return 1;
	}
	return 0;
}

void enqueue(int val){
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	if(isFull(n)){
		printf("Queue is full");
	}
	else{
		n->data = val;
		n->next = NULL;
		if(isEmpty(f)){
			f = r = n;
		}
		else{
			r->next = n;
			r = n;
		}
	}
}

int dequeue(){
	int val = -1;
	if(isEmpty(f)){
		printf("Queue is empty");
	}
	else{
		struct Node *ptr = f;
		f = f->next;
		val = ptr->data;
		free(ptr);
	}
	return val;
}
int main(){
	
	enqueue(6);
	enqueue(4);
	enqueue(7);
	enqueue(5);
	traversal(f);
	printf("Dequeue element %d\n",dequeue());
	traversal(f);
	
	return 0;
}