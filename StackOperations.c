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
int main()
{
	struct Stack * sp;
	sp = (struct Stack*) malloc(sizeof(struct Stack));
	sp->size = 10;
	sp->top = -1;
	sp->arr = (int*) malloc(sp->size*(sizeof(int)));
	printf("Before  pushing Full : %d\n",isFull(sp));       printf("Before  poping Empty : %d\n",isEmpty(sp));   
	push(sp,4) ;
	pop(sp);
	printf("After pushing Full : %d\n",isFull(sp));       printf("After  poping Empty : %d\n",isEmpty(sp));   
return(0);
}