#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

typedef struct TNode* Bintree;
struct TNode{
	int Data;
	Bintree Left;
	Bintree Right;
};

void InOrderTraversal(Bintree T)
{
	if(T){
		InOrderTraversal(T->Left);
		printf("%d",T->Data);
		InOrderTraversal(T->Right);
	}
}

void LevelOrderTraversal(Bintree T)
{
	Queue Q;
	Bintree tmpNode;
	
	if(!T) return ; ###
	
	Q = CreateQueue();
	AddQ(Q,T);
	if(!IsEmpty(Q)){
		tmpNode = DeleteQ(Q);
		printf("%d",tmpNode->Data);
		if(tmpNode->Left) AddQ(Q,tmpNode->Left);
		if(tmpNode->Right) AddQ(Q,tmpNode->Right);
	}
}

void PrintLeave(Bintree T)
{
	if(T){
		if((!T->Left)&&(!T->Right)) printf("%d",T->Data);
		PrintLeave(T->Left);
		PrintLeave(T->Right);
	}
}

int GetHeight(Bintree T)
{
	int L,R,Height;
	if(T)
	{
		L = GetHeight(T->Left);
		R = GetHeight(T->Right);
		Height = L>R?L:R;
		return Height+1;
	}
	else return 0;
}

//-------------------------¶þ²æËÑË÷Ê÷

Bintree Find(Bintree BST,int X)
{
	//##
	while(BST){
		if(X<BST->Data) BST = BST->Left;
		else if(X>BST->Data) BST = BST->Right;
		else break;    //##
	}
	return BST;		
}

Bintree FindMax(Bintree BST)
{
	if(!BST) return NULL;
	while(BST->Right) BST = BST->Right;
	return BST;
}

Bintree Insert(Bintree BST,int X)
{
	if(!BST){
		BST = (Bintree)malloc(struct Node);
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else{
		if(X<BST->Data) BST->Left = Insert(BST->Left,X);
		else if(X>BST->Data) BST->Right = Insert(BST->Right,X);
	}
	return BST;
}

Bintree Delete(Bintree BST,int X)
{
	Bintree tmpCell;
	
	if(!BST) return NULL;
	else {
		if(X<BST->Data) BST->Left = Delete(BST->Left,X);
		else if(X>BST->Data) BST->Right = Delete(BST->Right,X);
		else {
			if( BST->Left && BST->Right ){
				tmpCell = FindMax(BST->Left);
				BST->Data = tmpCell->Data;
				BST->Left = Delete(BST->Left,BST->Data);
			}
			else{
				tmpCell = BST;
				if(!BST->Right) BST = BST->Left;
				else BST = BST->Right;
				free(tmpCell);
			}
		}
	}
	return BST;
}
