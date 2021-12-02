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
//Case : 1
struct Node* firstInsertion(struct Node *head){
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		p->data = 2;
		p->next = head;
		return p;
}
//Case : 2
struct Node* insertAtIndex(struct Node *head, int data, int index){
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		struct Node *ptr = head;
		int i =0;
		while(i!=index-1){
			ptr = ptr->next;
			i++;
		}
		p->next = ptr->next;
		ptr->next = p;
		p->data = data;
	
		return head;
}
//Case : 3
struct Node* lastInsertion(struct Node *head, int data){
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		struct Node *ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		p->data = data;
		ptr->next = p;
		p->next = NULL;
		
		return p;
}
//Case : 4
struct Node* insertAfterNode(struct Node *head, struct Node *prevNode, int data){
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = prevNode->next,
	prevNode->next = ptr;
	
	return 0;
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
	traversal(head);
	//printf("Before insertion\n");
//	head = firstInsertion(head);
//	traversal(head);
	//printf("After insertion\n");
	//insertAtIndex(head,78,2);
//	traversal(head);
	//struct Node *last;
	 //astInsertion(head,190);
	//printf("Element is : %d", last->data);
//	traversal(head);
	printf("After insertion\n");
	insertAfterNode(head,second,6);
	traversal(head);
	return 0;
}
