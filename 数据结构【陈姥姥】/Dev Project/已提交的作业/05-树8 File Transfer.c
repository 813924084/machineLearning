#include <stdio.h>
#include <stdlib.h>

#define max 10000
typedef int SetType[max];
typedef int Root;

void Init(SetType S,SetType A,int K)
{
	int i;
	for(i=0;i<K;i++){
		S[i]=-1;
		A[i]=0;
	}
}

Root Find(SetType S,int m)
{
	for( ;S[m]>=0;m=S[m]);  //这里的分号很关键！！！ 
	return m;
}

void Union(SetType S,Root Root1,Root Root2)
{
	if ( S[Root2] < S[Root1] ) S[Root1] = Root2;
    else {
        if ( S[Root1]==S[Root2] ) S[Root1]--;
        S[Root2] = Root1;
	}
}
void  Check(SetType S,SetType A,int count)
{
	int m,n;
	Root root1,root2;
	scanf("%d %d",&m,&n);
	root1 = Find(S,m-1); //printf("root1=%d ",root1);
	root2 = Find(S,n-1); //printf(" root2=%d ",root2);
	if(root1!=root2) A[count]=-1;
	else A[count]=1;
}

void Connect(SetType S)
{
	int m,n;
	Root root1,root2;
	scanf("%d %d",&m,&n);
	root1 = Find(S,m-1);
	root2 = Find(S,n-1);
	if(root1!=root2) Union(S,root1,root2);
}

void Judge(SetType S,int K,SetType A,int counter)
{
	int count =0;
	int i;
	for(i=0;i<K;i++)	if(S[i]<0) count++;
	if(count==1) A[counter]=-999;
	else if(count>1) A[counter]=count;
}

void Print(SetType A,int count)
{
	int i,counter;
	counter=0;
	for(i=0;i<=count;i++){
		if(A[i]==1){
			if(counter!=0) printf("\n");
			printf("yes");
			counter++;
		} 
		else if(A[i]==-1){
			if(counter!=0) printf("\n");
			printf("no");
			counter++;
		}
		else if(A[i]==-999){
			if(counter!=0) printf("\n");
			printf("The network is connected.");
			counter++;
		}
		else if(A[i]>1){
		  if(counter!=0) printf("\n");
			printf("There are %d components.",A[i]);
			counter++;
		}
	}
}

int main()
{
	int K,count=0;
	SetType S,A;
	char in;
	scanf("%d",&K);
	Init(S,A,K);
	//for(i=0;i<K;i++) printf("%d ",A[i]);
	do{
		scanf("\n%c",&in);
		switch(in){
			case 'C': Check(S,A,count);  count++; break;
			case 'I': Connect(S); break;
			case 'S': Judge(S,K,A,count); count++; break;
		}
	}while(in!='S');
	count--;
	//for(i=0;i<count;i++) printf("A[%d] %d ",i,A[i]);
	Print(A,count);
	return 0;
}
