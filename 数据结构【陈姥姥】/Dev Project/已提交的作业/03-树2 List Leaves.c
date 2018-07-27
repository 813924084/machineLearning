#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 10

typedef struct Node* BinTree;
struct Node{
  int index;
  BinTree left,right;
};

typedef struct QNode* PtrToQNode;
struct QNode{
  BinTree Tree;
  PtrToQNode Next;
};
typedef PtrToQNode Position;

typedef struct List* Queue;
struct List{
  Position front,rear;
};

struct Array{
  int left; 
  int right;
}T1[Max];

BinTree CreateTree(BinTree BT,int root)
{
  if(root==-1) BT=NULL;
  else {
    BT = (BinTree)malloc(sizeof(struct Node));
    BT->index = root;
    BT->left=CreateTree(BT->left,T1[root].left);
    BT->right=CreateTree(BT->right,T1[root].right);
  }
  return BT;
}

Queue CreateQueue()
{
  Queue q;
  q = (Queue)malloc(sizeof(struct List));
  q->front=q->rear=NULL;
  return q;
}

bool IsEmpty(Queue q)
{
  return (q->front==NULL);
}

bool Add(Queue q,BinTree ind)
{
  PtrToQNode tmp = (PtrToQNode)malloc(sizeof(struct QNode));
  tmp->Tree = ind;
  tmp->Next = NULL;
  if(q->front==NULL) q->rear=q->front=tmp;
  else {
    q->rear->Next=tmp;
    q->rear = tmp;
  }
  return true;
}

BinTree Delete(Queue q)
{
  Position tmp;
  BinTree tmp2;
  if(IsEmpty(q)) return NULL;
  else {
    tmp = q->front;
    if(q->front==q->rear) q->front=q->rear=NULL;
    else q->front=tmp->Next;
    tmp2=tmp->Tree;
    free(tmp);
    return tmp2;
  }
}

void LevelOrderTraversal(BinTree BT)
{
  BinTree T;
  Queue Q;
  int t=0;
  Q=CreateQueue();
  if(!BT)return;
  Add(Q,BT);
  while(!IsEmpty(Q)){
    T=Delete(Q);
    if(T->left)Add(Q,T->left);
    if(T->right)Add(Q,T->right);
    if((!T->left)&&(!T->right)){
    	if(t!=0)printf(" ");
        t++;
    	printf("%d",T->index);	
	}
  }
}

int main()
{
  int N,i,root;
  char l,r,enter,space;
  BinTree T;
  scanf("%d",&N);
  int check[N];
  
  for(i=0;i<N;i++){
    scanf("%c%c%c%c",&enter,&l,&space,&r);
    if(l!='-')T1[i].left=l-'0';
    else T1[i].left=-1;
    if(r!='-')T1[i].right=r-'0';
    else T1[i].right=-1;
    check[i]=0;
  }
  
  for(i=0;i<N;i++){
    if(T1[i].left!=-1)check[ T1[i].left ]=1;
    if(T1[i].right!=-1)check[ T1[i].right ]=1;
  }
  
  for(i=0;i<N;i++){
    if(check[i]==0){
    	root=i;
    	break;
	}
  }
  T=CreateTree(T,root);
  LevelOrderTraversal(T);
  return 0;
}
