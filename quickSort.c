#include<stdio.h>

void printArray(int *A, int n){
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

int partition(int A[],int low,int high){
	int pivot = A[low];
	int i = low+1;
	int j = high;
	int temp;
	
	do{
		while(A[i]<=pivot){
			i++;
		}
		while(A[j]>pivot){
			j--;
		}
		if(i<j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i<j);
		temp = A[low];
	    A[low] = A[j];
		A[j] = temp;
		return j;
}
void quickSort(int A[],int low,int high){
	int parIndex;
	
	if(low<high){
		parIndex = partition(A,low,high);
		quickSort(A,low,parIndex-1);
		quickSort(A,parIndex+1,high);
	}
}
int main(){
	int A[] = {6,4,0,2,1,9,3,7};
	int n = 8;
	printArray(A,n);
	quickSort(A,0,n-1);
	printArray(A,n);
	return 0;
}