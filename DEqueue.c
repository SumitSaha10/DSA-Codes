#include<stdio.h>
#include<stdlib.h>
struct queue{
	int size;
	int f;
	int r;
	int * arr;
};

int isEmpty(struct queue *q){
	if(q->f == q->r){
		return 1;
	}
	return 0;
}

int isFull(struct queue *q){
	if(q->r == q->size-1){
		return 1;
	}
	return 0;
}

void enqueueF(struct queue *q, int val){
	if(q->f==-1){
		printf("Failed to add");
	}
	else{
		q->arr[q->f] = val;
		q->f--;
	}
	
}

void enqueueR(struct queue *q, int val){
	if(isFull(q)){
		printf("Queue is full");
	}
	else{
		q->r++;
		q->arr[q->r] = val;
	}
	
}

int dequeueF(struct queue *q){
	int a = -1;
	if(isEmpty(q)){
		printf("Queue is empty");
	}
	else{
		q->f++;
		a = q->arr[q->f];
	}
	return a;
}

int dequeueR(struct queue *q){
	int a = -1;
	if(isEmpty(q)){
		printf("Queue is empty");
	}
	else{
		a = q->arr[q->r];
		q->r--;
	}
	return a;
}

int main(){
	struct queue q;
	q.size = 15;
	q.f = q.r = -1;
	q.arr = (int*) malloc(q.size*sizeof(int));
	
	enqueueR(&q,7);
	enqueueR(&q,6);
	enqueueR(&q,23);
	enqueueR(&q,90);
	enqueueR(&q,8);
	
	dequeueF(&q);
	dequeueR(&q);
	enqueueF(&q,4);
	//dequeue(&q);
	
	for(int i = q.f+1; i<q.r+1;i++){
		printf("Element is %d\n",q.arr[i]);
	}
	return 0;
}