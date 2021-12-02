#include<stdio.h>
#include<stdlib.h>
struct Stack{
	int size;
	int top;
	int *arr;
};

int isEmpty(struct Stack *ptr){
	if(ptr->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(struct Stack *ptr){
	if(ptr->top == ptr->size -1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(struct Stack *ptr, int val){
	if(isFull(ptr)){
	printf("Stack Overflow cannot push value");
	}
	else{
		ptr->top++;
		ptr->arr[ptr->top] = val;
	}
}

int pop(struct Stack *ptr){
	if(isEmpty(ptr)){
	printf("Stack Underflow cannot pop value");
	}
	else{
		int val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}

int peek(struct Stack *sp, int i){
	int arrayInd = sp->top-i+1;
	if(arrayInd<0){
		printf("Stack position not found");
		return -1;
	}
	else{
		return sp->arr[arrayInd];
	}
}
int stackTop(struct Stack *sp){
	return sp->arr[sp->top];
}

int stackBottom(struct Stack *sp){
	return sp->arr[0];
}
int main()
{
	struct Stack * sp;
	sp = (struct Stack*) malloc(sizeof(struct Stack));
	sp->size = 10;
	sp->top = -1;
	sp->arr = (int*) malloc(sp->size*(sizeof(int)));
	
	push(sp,4) ;
	push(sp,2) ;
	push(sp,41) ;
	push(sp,84) ;
	push(sp,90) ;
	push(sp,54) ;
	push(sp,1) ;
	
	pop(sp);
	for(int i =0;i<sp->top+1;i++){
		printf("Element is : %d\n",sp->arr[i]);
	}
	printf("Element : %d\n",peek(sp,3));
	printf("Top Elemnt: %d\n",stackTop(sp));
	printf("Bottom Element : %d\n",stackBottom(sp));
	return 0;
}