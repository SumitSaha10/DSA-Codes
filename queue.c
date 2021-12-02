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

void enqueue(struct queue *q, int val){
	if(isFull(q)){
		printf("Queue is full");
	}
	else{
		q->r++;
		q->arr[q->r] = val;
	}
	
}

int dequeue(struct queue *q){
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

int main(){
	struct queue q;
	q.size = 5;
	q.f = q.r = -1;
	q.arr = (int*) malloc(q.size*sizeof(int));
	
	enqueue(&q,7);
	enqueue(&q,6);
	enqueue(&q,23);
	enqueue(&q,90);
	enqueue(&q,8);
	dequeue(&q);
	
	for(int i = q.f+1; i<q.r+1;i++){
		printf("Element is %d\n",q.arr[i]);
	}
	return 0;
}