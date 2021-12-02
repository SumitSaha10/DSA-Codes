#include<stdio.h>

void printArray(int *A, int n){
	for(int i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	printf("\n");
}

void insertionSort(int *A,int n){
	int key,j;
	for(int i=1;i<n;i++){
		key = A[i];
		j = i-1;
		
		while(j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
	
		A[j+1] = key;
	}
}
int main(){
	int A[] = {1,17,6,0,8,6};
		printArray(A,6);
	printf("After sorting algorithm\n");
	insertionSort(A,6);
	printArray(A,6);
	return 0;
}