#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
	int size;
	int top;
	char *arr;
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

void push(struct Stack *ptr, char val){
	if(isFull(ptr)){
	printf("Stack Overflow cannot push value");
	}
	else{
		ptr->top++;
		ptr->arr[ptr->top] = val;
	}
}

char pop(struct Stack *ptr){
	if(isEmpty(ptr)){
	printf("Stack Underflow cannot pop value\n");
	return '1';
	}
	else{
		char val = ptr->arr[ptr->top];
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
int parenthesisMatching(char * exp){
	struct Stack * sp;
sp = (struct Stack*) malloc(sizeof(struct Stack));
	sp->size = 100;
	sp->top = -1;
	sp->arr = (char*) malloc(sp->size*(sizeof(char)));
	
	
	for(int i=0;i<strlen(exp);i++){
		if(exp[i] == '('){
			push(sp,exp[i]);
		}
		else if(exp[i] == ')'){
			if(isEmpty(sp)){
				return 0;
			}
			pop(sp);
		}

	}
	
	if(isEmpty(sp)){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
   char exp[] = "1*2(5+7(8)";
	
	//Checking stack empty or not
	if(parenthesisMatching(exp)){
		printf("Expression matched");
	}
	else{
		printf("Expression does not matched");
	}
	return 0;
}