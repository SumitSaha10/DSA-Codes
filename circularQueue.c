#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
	int size;
	int f;
	int r;
	int * arr;
};

int isEmpty(struct circularQueue *q){
	if(q->f == q->r){
		return 1;
	}
	return 0;
}

int isFull(struct circularQueue *q){
	if((q->r+1)%q->size== q->f){
		return 1;
	}
	return 0;
}

void enqueue(struct circularQueue *q, int val){
	if(isFull(q)){
		printf("Queue is full\n");
	}
	else{
		q->r = (q->r+1)%q->size;
		q->arr[q->r] = val;
	}
	
}

int dequeue(struct circularQueue *q){
	int a = -1;
	if(isEmpty(q)){
		printf("Queue is empty\n");
	}
	else{
		q->f = (q->f+1)%q->size;
		a = q->arr[q->f];
	}
	return a;
}

int main(){
	struct circularQueue q;
	q.size = 6;
	q.f = q.r = 0;
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