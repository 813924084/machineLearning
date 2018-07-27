#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

typedef struct HNode* MaxHeap;
struct HNode{
	int *Data;
	int Capacity;
	int Size;
};

MaxHeap CreateHeap(int capacity)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (int*)malloc(sizeof(int)*(capacity+1));
	H->Capacity = capacity;
	H->Size = 0;
	H->Data[0] = 99999;
	return H;
}

bool IsEmpty(MaxHeap H)
{
	return (H->Size==0);
}

bool IsFull(MaxHeap H)
{
	return (H->Capacity == H->Size);
}

bool Insert(MaxHeap H,int X)
{
	int i;
	if(IsFull(H)) return false;
	else {
		i = ++H->Size;  //###
		for(i;H->Data[i/2]<=X;i/=2){
			H->Data[i] = H->Data[i/2];
		}
		H->Data[i] = X;
		return true;
	}
}

int Delete(MaxHeap H)
{
	int MaxData,Child,Parent,LastData;
	if(IsEmpty(H)) return ERROR;
	else {
		MaxData = H->Data[1];
		LastData = H->Data[(H->Size)--];
		
		for(Parent=1;Parent*2<=H->Size; Parent=Child){
			Child = Parent*2;
			if( (Child<H->Size) && (H->Data[Child+1]>H->Data[Child]) ) Child = Child+1;
			if(H->Data[Child]<=LastData) break;
			else H->Data[Parent] = H->Data[Child];
		}
		H->Data[Parent] = LastData;
		
		return MaxData;
	}
}

void PercDown(MaxHeap H,int Parent)
{
	int Child;
	LastData = H->Data[Parent];
		
	for(Parent;Parent*2<=H->Size; Parent=Child){
		Child = Parent*2;
		if( Child<H->Size && H->Data[Child+1]>H->Data[Child]) Child = Child+1;
		if(H->Data[Child]<=LastData) break;
		else H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = LastData;
}

void BuildHeap(MaxHeap H)
{
	int i = H->Size/2;
	for(i;i>=1;i--) PercDown(H,i);
}
