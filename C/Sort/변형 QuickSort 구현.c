#include <stdio.h>
#define arrayLen 10
int quickSort[arrayLen] = {8, 5, 6, 2, 3, 7, 4, 9, 10, 1};
int end;
int left, right;
int top, stack[10];
	top = 0;

int stackPush(int pushData){
	stack[top] = pushData;
	top++;
}
int stackPop(){
	return stack[top];
	top--;
}

int show(int lengthEnd){
	int i;
	
	for(i=0; i<lengthEnd; i++) 
		printf("[%d] ",quickSort[i]);
	printf("\b ");
}

int swap(int *inputA, int *inputB){
	int temp;
	
	temp = *inputA;
	*inputA = *inputB;
	*inputB = temp;
}


int Qsort(int Qleft, int Qright){
	int pivot, i, j;
	pivot = j = Qleft;
	
	
	for(i=Qleft + 1; i<Qright; i++){
		if(quickSort[pivot] > quickSort[i]){
			j++;
			swap(&quickSort[j], &quickSort[i]);
		}
		if(i == Qright-1) {
			Qright = j;
			printf("\nfor문에 안에 있는 변수 J의 값 : %d", j);
			if(Qleft == j) Qleft++;
			swap(&quickSort[pivot], &quickSort[j]);
		}
	}
	
	printf("\n--------------------------------\n");
	show(arrayLen);
	
	printf("Qleft의 값: %d", Qleft);
	if(Qleft == 9) return 0;
	Qsort(Qleft, 10);
}

void main(){
	
	left = 0;
	right = arrayLen;

	show(arrayLen);
	Qsort(left, right);
	
	//pivot 값을 잡는다.
	//Qright는 배열의 끝을 의미한다. 
}
