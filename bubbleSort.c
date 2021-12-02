#include<stdio.h>

void printArray(int *A, int n){
	for(int i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
}
void bubbleSort(int *A,int n){
	for(int i=0;i<n-1;i++){
		 printf("%d pass\n",i+1);
		for(int j=0;j<n-1-i;j++){
		  if(A[j]>A[j+1]){
		  	int temp = A[j];
		  	A[j]  = A[j+1];
		  	A[j+1] = temp;
		  }
	
	}
	}
	
}
void bubbleSortAdaptive(int *A,int n){
	int isSorted = 0;
	for(int i=0;i<n-1;i++){
	 	isSorted = 1;
		 printf("%d pass\n",i+1);
		for(int j=0;j<n-1-i;j++){
		  if(A[j]>A[j+1]){
		  	int temp = A[j];
		  	A[j]  = A[j+1];
		  	A[j+1] = temp;
		  	isSorted = 0;
		  }
	
	}
		if(isSorted){
			return;
		}
	}
	
}

int main(){
	int A[] = {1,7,6,7,8,6};
	//int A[] = {1,2,3,4,5,6};
	printArray(A,6);
	printf("After sorting algorithm\n");
	bubbleSort(A,6);
	printArray(A,6);
	return 0;
}