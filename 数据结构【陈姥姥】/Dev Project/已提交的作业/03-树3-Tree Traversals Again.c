#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int In[30],Pre[30],Post[30];

typedef struct StackNode* PtrToNode;
struct StackNode{
	int Data;
	PtrToNode Next;
};
typedef PtrToNode Stack;

Stack CreateStack()
{
	Stack s = (Stack)malloc(sizeof(struct StackNode));
	s->Next = NULL;
	return s;
}

bool IsEmpty(Stack s)
{
	return (s->Next==NULL);
}

bool Push(Stack s,int a)
{
	PtrToNode tmp;
	tmp = (PtrToNode)malloc(sizeof(struct StackNode));
	tmp->Data = a;
	tmp->Next = s->Next;
	s->Next = tmp;
	return true;
}

int Pop(Stack s)
{
	
	int a;
	PtrToNode tmp = s->Next;
	s->Next = tmp->Next;
	a = tmp->Data;
	free(tmp);
	return a;
}

void PostOrder( int prePos,int inPos,int postPos,int length )
{
	int i,L,R,root;
	if( length==0 ) return;
	if( length==1 ) {
		Post[postPos]=Pre[prePos];
		return;
	}
	root = Pre[prePos];
	Post[postPos+length-1] = root;
	for(i=0;i<length;i++ ) if( In[inPos+i]==Pre[prePos] ) break;
	L=i;R=length-L-1;
	PostOrder ( prePos+1,inPos,postPos,L );
	PostOrder ( prePos+1+L,inPos+L+1,postPos+L,R);
}


int main()
{
	int K,i,n,count2=0,count1=0,count=0;
	char *p;
	scanf("%d",&K);
	Stack stack = CreateStack();
	
	p = (char*)malloc(sizeof(char));
	for(i=0;i<2*K;i++){
		scanf("%s",p);
		if( !strcmp("Push",p) ){
			scanf("%d",&n);
			Pre[count1]=n;
			count1++;
			Push(stack,n);
		} 
		else if( !strcmp("Pop",p) ){
			In[count2]=Pop(stack);
			count2++;
		} 
    }
    /*
    for(i=0;i<K;i++)
    	printf("Pre[%d]=%d\n",i,Pre[i]);
    for(i=0;i<K;i++)
    	printf("In[%d]=%d\n",i,In[i]); */
    PostOrder(0,0,0,K);
	for(i=0;i<K;i++){
		if(count==0) printf("%d",Post[i]);
		else printf(" %d",Post[i]);
		count++;
	}
	return 0;
}
