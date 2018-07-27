#include <stdio.h>
#include <stdlib.h>

#define Tree int
#define Null -1
#define ElementType char
#define maxsize 10

struct TreeNode{
	ElementType element;
	Tree left;
	Tree right;
}T1[maxsize],T2[maxsize];

Tree CreateTree(struct TreeNode T[]);
int tonggou(Tree r1, Tree r2);

int main()
{
	Tree r1,r2;
	r1 = CreateTree(T1);
	r2 = CreateTree(T2);
	if(tonggou(r1,r2)) printf("Yes");
	else printf("No");
	return 0;
}

Tree CreateTree(struct TreeNode T[])
{
	int N,i;
	char l,r,Root=-1,space1,space2;
	scanf("%d",&N);
	int root[N];
	if(N){
		for(i=0;i<N;i++) root[i]=0;
		for(i=0;i<N;i++){
			scanf("\n%c%c%c%c%c",&T[i].element,&space1,&l,&space2,&r);
		    if(l!='-'){
		    	T[i].left=l-'0';
		    	root[T[i].left]=1;
		    }
		    else T[i].left=Null;
		    if(r!='-'){
		    	T[i].right=r-'0';
		        root[T[i].right]=1;
		   	}
		    else T[i].right=Null;
		}
		for(i=0;i<N;i++)
			if(root[i]==0){
				Root = i;
				break;
			} 			
	}
	return Root;
}

int tonggou(Tree r1, Tree r2)
{
	if((r1==Null) && (r2==Null))return 1;
	if(( (r1==Null) && (r2!=Null) )||( (r1!=Null) && (r2==Null) ))return 0;
	if(T1[r1].element!=T2[r2].element)return 0;
	if( (T1[r1].left==Null) && (T2[r2].left==Null) ) return tonggou( T1[r1].right,T2[r2].right );
	if( (T1[T1[r1].left].element==T2[T2[r2].left].element) && ( (T1[r1].left!=Null) && (T2[r2].left!=Null) ) )
	    return (  tonggou( T1[r1].left,T2[r2].left ) && tonggou(T1[r1].right,T2[r2].right ) ) ;
	else 
	    return (  tonggou( T1[r1].left,T2[r2].right ) && tonggou(T1[r1].right,T2[r2].left ) ) ;
	
}
