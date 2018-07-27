#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QNode* PtrToQNode;
typedef int Position;
struct QNode{
	int *Data;
	Position Front,Rear;
	int Maxsize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int maxsize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (int*)malloc(sizeof(int)*maxsize);
	Q->Front = Q->Rear = 0;
	Q->Maxsize = maxsize;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->Front==Q->Rear);
}

bool IsFull(Queue Q)
{
	return (((Q->Rear+1) % Q->Maxsize)==Q->Front);
}

bool AddQ(Queue Q,int X)
{
	if(IsFull(Q)) return false;
	else {
		Q->Rear = (Q->Rear+1)%Q->Maxsize;
		Q-Data[Q->Rear] = X;
		return true;
	}
}

int DeleteQ(Queue Q)
{
	if(IsEmpty(Q)) return ERROR;
	else {
		Q->Front = (Q->Front+1)%Q->Maxsize;
		return Q->Data[Q->Front];
	}
}

#------------------------------------------

typedef struct Node* PtrToNode;
struct Node{
	int Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode{
	Position Front,Rear;
};
typedef struct QNode* Queue;

Queue CreateQueue()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode))
	Q->Front = Q->Rear = NULL;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->Front == NULL);
}

bool AddQ(Queue Q,int X)
{
	PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));
	tmp->Data = X;
	tmp->Next = NULL;
	if(IsEmpty(Q)) Q->Front = Q->Rear = tmp;
	else {
		Q->Rear->Next = tmp;
		Q->Rear = tmp;
	}
	return true;
}

int DeleteQ(Queue Q)
{
	PtrToNode tmpCell;
	int tmpData;
	if(IsEmpty(Q)) return ERROR;
	else{
		if(Q->Front==Q->Rear) {
			tmpData = Q->Front->Data;
			Q->Front = Q->Rear = NULL;
			return tmpData;
		}
		else {
			tmpData = Q->Front->Data;
			tmpCell = Q->Front;
			Q->Front = Q->Front->Next;
			free(tmpCell);
			return tmpData;
		}
	}
}
