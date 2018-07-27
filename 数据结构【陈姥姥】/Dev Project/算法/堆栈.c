#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode* PtrToSNode;
typedef int Position;
struct SNode{
	int* Data;
	Position Top;
	int Maxsize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int Maxsize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (int*)malloc(Maxsize*sizeof(int));
	S->Maxsize = Maxsize;
	S->Top = -1;
	return S;
}

bool IsEmpty(Stack S)
{
	return (S->Top==-1);
}

bool IsFull(Stack S)
{
	return (S->Top+1==S->Maxsize);
}

bool Push(Stack S,int X)
{
	if (IsFull(S)) return false;
	else {
		S->Data[++(S->Top)]=X;
		return true;
	}
	
}

int Pop(Stack S)
{
	if(IsEmpty()) return ERROR;##
	else {
		return S->Data[(S->Top)--];
	}
}

##------------------------

typedef struct SNode* PtrToSNode;
struct SNode{
	int Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

bool IsEmpty(Stack S)  ##
{
	return (S->Next==NULL);
}

bool Push(Stack S,int X)
{
	PtrToSNode tmp = (PtrToSNode)malloc(sizeof(struct SNode));
	tmp->Data = X;
	tmp->Next = S->Next;
	S->Next = tmp;
	return true; ##
}

int Pop(Stack S)
{
	int tmpData;
	PtrToSNode tmp;         ##
	if(IsEmpty()) return ERROR;
	else {
		tmp = S->Next;
		S->Next = tmp->Next;
		tmpData = tmp->Data;
		free(tmp);
		return tmpData;
	}
}
