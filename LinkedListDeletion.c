#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
//Traversal
void traversal(struct Node *ptr){
  while(ptr!=NULL)
  {
  printf("Element is : %d\n", ptr->data);
  ptr = ptr->next;
  }
}
//Case 1:Deleting first element from linked List
struct Node * firstIndDelete(struct Node* head){
	struct Node *ptr = head;
	head = head->next;
	free(ptr);
	return head;
}
//Case 2:Deleting  element at a given index from linked List
struct Node * deleteAtIndex(struct Node* head, int index){
	struct Node *p = head;
	struct Node *q = p->next;
	for(int i=0;i<index-1;i++){
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
	return head;
}
//Case 3:Deleting  last element from linked List

struct Node * deleteLastElm(struct Node *head){
	struct Node *p = head;
	struct Node *q = p->next;
	
	while(q->next!=NULL){
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
	return head;
}
//Case 3: Deleting Node at a given value from linked list
struct Node * deleteAtValue(struct Node* head, int value){
	struct Node *p = head;
	struct Node *q = p->next;
	while(q->data!=value && q->next!=NULL){
		p = p->next;
		q = q->next;
	}
	if(q->data == value){
		p->next = q->next;
		free(q);
	}
	return head;
}

int main(){
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
		struct Node *second = (struct Node*)malloc(sizeof(struct Node));
			struct Node *third = (struct Node*)malloc(sizeof(struct Node));
				struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
				
	head->data = 3;
	head->next = second;
	second->data = 80;
	second->next = third;
	third->data = 53;
	third->next = fourth;
	fourth->data = 76;
	fourth->next = NULL;
   printf("Before Deletion\n");
  traversal(head);
   //head = firstIndDelete(head);
  // traversal(head);
  
   printf("After Deletion\n");
   //deleteAtIndex(head,2);
   //deleteLastElm(head);
   deleteAtValue(head,80);
   traversal(head);
	return 0;
}
