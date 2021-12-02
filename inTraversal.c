#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data){
	struct node *n;
	n= (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inTraversal(struct node *root){
	if(root!=NULL){
		inTraversal(root->left);
		printf("%d ",root->data);
		inTraversal(root->right);
	}
}
int main(){
	/*
	struct node *p;
	p= (struct node*)malloc(sizeof(struct node));
	p->data = 2;
	p->left = NULL;
	p->right = NULL;
	
	struct node *p1;
	p1= (struct node*)malloc(sizeof(struct node));
	p1->data = 2;
	p1->left = NULL;
	p1->right = NULL;
	
	struct node *p2;
	p2= (struct node*)malloc(sizeof(struct node));
	p2->data = 2;
	p2->left = NULL;
	p2->right = NULL;
	
	p->left = p1;
	p->right = p2;
	*/
	
	struct node *p = createNode(2);
	struct node *p1 = createNode(1);
	struct node *p2 = createNode(4);
	struct node *p3 = createNode(5);
	struct node *p4 = createNode(6);
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;
	inTraversal(p);
	return 0;
}