#include <stdio.h>
#include <stdlib.h>

typedef struct TNode* AVLTree;
struct TNode{
	int data;
	AVLTree left,right;
	int height;
};

int Max(int a,int b)
{
	return (a>b?a:b);
}

int GetHeight(AVLTree T)
{
	int l,r,max;
	if(T){
		l = GetHeight(T->left);
		r = GetHeight(T->right);
		max = Max(l,r);
		return (max+1);
	}
	else return 0;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = Max(GetHeight(A->left),GetHeight(A->right))+1;
	B->height = Max(GetHeight(B->left),GetHeight(B->right))+1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = Max(GetHeight(A->left),GetHeight(A->right))+1;
	B->height = Max(GetHeight(B->left),GetHeight(B->right))+1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->left = SingleRightRotation(A->left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->right = SingleLeftRotation(A->right);
	return SingleRightRotation(A);
}


AVLTree Insert(AVLTree T,int t)
{
	if(!T){
		T=(AVLTree)malloc(sizeof(struct TNode));
		T->left=NULL;
		T->right=NULL;
		T->data=t;
		T->height=1;
	}
	else {
		if(t<T->data){
			T->left = Insert(T->left,t);
			if(GetHeight(T->left)-GetHeight(T->right)==2){
				if(t<T->left->data) T = SingleLeftRotation(T);
				else T = DoubleLeftRightRotation(T);
			}
		} 
		else if(t>T->data){
			T->right = Insert(T->right,t);
			if(GetHeight(T->left)-GetHeight(T->right)==-2){
				if(t>T->right->data) T = SingleRightRotation(T);
				else T = DoubleRightLeftRotation(T);
			}
		}
		
	}
	T->height = Max(GetHeight(T->left),GetHeight(T->right))+1;
	return T;
}

int main()
{
	int N,K,i;
	AVLTree tree=NULL;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&K);
		tree = Insert(tree,K);
	}
	printf("%d",tree->data);
	return 0;
}

