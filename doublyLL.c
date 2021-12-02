#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};
//Traversal
void traversal(struct Node *head){
  struct Node *ptr = head;
  while(ptr!=NULL)
  {
  printf("Element is : %d\n", ptr->data);
  ptr = ptr->next;
  }
}


int main(){
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
		struct Node *second = (struct Node*)malloc(sizeof(struct Node));
			struct Node *third = (struct Node*)malloc(sizeof(struct Node));
				struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
				
	head->data = 3;
	head->prev = NULL;
	head->next = second;
	
	second->data = 80;
	second->prev = head;
	second->next = third;
	
	third->data = 53;
	third->prev = second;
	third->next = fourth;
	
	fourth->data = 76;
	fourth->prev = third;
	fourth->next = NULL;
    traversal(head);
   
	return 0;
}
