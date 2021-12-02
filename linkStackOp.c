#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void linkedListTraversal(struct Node *top){
	struct Node *ptr = top;
	while(ptr!=NULL){
		printf("Element is : %d\n",ptr->data);
		ptr = ptr->next;
	}
}
int isEmpty(struct Node *top){
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(struct Node *top){
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	if(n==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
struct Node * push(struct Node *top, int data){
	if(isFull(top)){
		printf("Stack Overflow");
	}
	else{
		struct Node *n = (struct Node*)malloc(sizeof(struct Node));
		n->data = data;
		n->next = top;
		top = n;
		return top;
	}
}
struct Node *pop(struct Node *top){
	if(isEmpty(top)){
		printf("Stack Underflow");
	}
	else{
		struct Node *n = top;
		top = top->next;
		free(n);
		return top;
	}
}

int peek(struct Node *top,int pos){
	struct Node *ptr = top;
	int i;
    for(i=0;(i<pos-1 && ptr!=NULL);i++){
    	ptr = ptr->next;
    }
    if(ptr!=NULL){
    	return ptr->data;
    }
    else{
    	return -1;
    }
}

int stackTop(struct Node *top){
	return top->data;
}

int stackBottom(struct Node *top){
	struct Node *ptr = top;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	return ptr->data;
}

int main(){
	struct Node *top = NULL;
	top = push(top,2);
	top = push(top,12);
	top = push(top,45);
	top = push(top,90);
	linkedListTraversal(top);
	printf("After peek operation\n");
	printf("%d\n",peek(top,2));
	printf("After stackTop operation\n");
	printf("%d\n",stackTop(top));
		printf("After stackBottom operation\n");
	printf("%d\n",stackBottom(top));
	return 0;
}