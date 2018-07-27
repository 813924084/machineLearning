#include <stdio.h>
#include <stdlib.h>

typedef struct TNode* Tree;
struct TNode{
	int data;
	Tree left,right;
	int flag;
};

Tree CreateHead(int t)
{
	Tree tree;
	tree = (Tree)malloc(sizeof(struct TNode));
	tree->data=t;
	tree->left=tree->right=NULL;
	tree->flag=0;
	return tree;
}

Tree Insert(Tree tree,int t)
{
	if(!tree){
		tree = (Tree)malloc(sizeof(struct TNode));
		tree->data=t;
		tree->left=tree->right=NULL;
		tree->flag=0;
	}
	else {
		if(t<tree->data) tree->left=Insert(tree->left,t);
		else tree->right=Insert(tree->right,t);
	}
	return tree;
}

Tree MakeTree(int N)
{
	int i,t,tmp;
	Tree tree;
	scanf("%d",&t);
	tree = CreateHead(t);
	
	for(i=1;i<N;i++){
		scanf("%d",&tmp);
		tree = Insert(tree,tmp);
	}
	return tree;
}

int check(Tree T,int V)
{
	int K;
	if(T->flag){
		if(V<T->data) return check(T->left,V);
		else if(V>T->data) return check(T->right,V);
		else return 0;
	}
	else{
		if(V==T->data){
			T->flag=1;
			return 1;
		}
		else return 0;
	}
}

int Judge(Tree T,int N)
{
	int i,V,flag=0;
	scanf("%d", &V);
    if ( V!=T->data ) flag = 1;
    else T->flag = 1;
    for (i=1; i<N; i++) {
        scanf("%d", &V);
	    if ( (!flag) && (!check(T, V)) ) flag = 1;
    } 
    if (flag) return 0;
    else return 1;
} 

void ResetT ( Tree T ) /* 清除T中各结点的flag标记 */
{
    if (T->left) ResetT(T->left);
    if (T->right) ResetT(T->right);
    T->flag = 0;
}
void FreeTree ( Tree T ) /* 释放T的空间 */
{
    if (T->left) FreeTree(T->left);
    if (T->right) FreeTree(T->right);
    free(T);
}

int main()
{
	int N,L,i,count=0,count2=0,a[20];
	Tree T;
	scanf("%d",&N);
	for(i=0;i<20;i++){
		a[i]=-1;
	}
	while(N){
		scanf("%d",&L);
		T=MakeTree(N);
		for(i=1;i<=L;i++){
			
			if(Judge(T,N)) a[count]=1;
			else a[count]=0;
			ResetT(T);
			count++;
		}
		FreeTree(T);
		scanf("%d",&N);
	}
	for(i=0;a[i]!=-1;i++){
		if(count2!=0) printf("\n");
		if(a[i]==1) printf("Yes");
		if(a[i]==0) printf("No");
		count2++;
	}
	
	return 0;
}
