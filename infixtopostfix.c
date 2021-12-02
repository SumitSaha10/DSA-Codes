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
char stackTop(struct Stack *sp){
	return sp->arr[sp->top];
}

int operator(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/'){
		return 1;
	}
	return 0;
}

int precedence(char a){
	if(a=='*' || a=='/'){
		return 2;
	}
	else if(a=='+' || a=='-'){
		return 1;
	}
	
}

char * infixtoPostfix(char * infix){
	struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
	sp->top = -1;
	sp->size = 100;
	sp->arr = (char*)malloc(sp->size * sizeof(char));
	char * postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
	
	int i = 0;
	int j =0;
	while(infix[i]!='/0'){
		if(!operator(infix[i])){
			postfix[j] = infix[i];
			i++;
			j++;
		} 
		else{
			if(precedence(infix[i]) > precedence(stackTop(sp))){
				push(sp,infix[i]);
				i++;
			}
			else{
				postfix[j] = pop(sp);
				j++;
			}
			
		}
	}
	while(!isEmpty(sp)){
		postfix[j] = pop(sp);
		j++;
	}
	postfix[j] = '/0';
	return postfix;
}

int main()
{
   char * infix = "1*2-5+7/8";
   
   printf("%s",infixtoPostfix(infix));
	
   
	return 0;
}