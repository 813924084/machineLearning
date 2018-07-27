#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct SNode* PtrToSNode;
struct SNode{
	int Top;
	int Maxsize;
	int *Data;
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (int*)malloc(MaxSize*sizeof(int));
	S->Top=-1;
	S->Maxsize=MaxSize;
	return S;
}

bool IsFull(Stack S)
{
	return (S->Top==S->Maxsize-1);
}

bool IsEmpty(Stack S)
{
	return (S->Top==-1);
}

bool Push(Stack S,int X)
{
	if(IsFull(S))return false;
	else{
		S->Data[++(S->Top)]=X;
		return true;
	}
}

int Pop(Stack S)
{
	if(IsEmpty(S))return 0;
	else{
		return S->Data[(S->Top)--];
	}
}

void Function(int List[],int stack,int number,bool index_of_bool[],int di_ji_ci){
	Stack S; 
	int i,j,tmp,t,z;
	bool SuccessOrNot,IsPush;
	int list[number];
	S = CreateStack(stack);
	t=List[0]-1;
	for(i=1;i<=List[0];i++){
		SuccessOrNot=Push(S,i);
		list[i-1]=i;
		if(!SuccessOrNot){
			index_of_bool[di_ji_ci]=false;
			return;
		}
	}
	tmp=Pop(S);
	if(tmp!=List[0]){
		index_of_bool[di_ji_ci]=false;
		return;
	}
	
	for(i=1;i<number;i++){
		if(List[i]>List[i-1]){
			for(j=List[i-1]+1;j<=List[i];j++){
				IsPush=false;
				for(z=0;z<=t;z++){//哪些元素Push过就不再Push了！ 
					if(j==list[z]){IsPush=true;break;}
				}
				if(IsPush)continue;
				list[t+1]=j;t++;
				SuccessOrNot=Push(S,j);
		        if(!SuccessOrNot){
			        index_of_bool[di_ji_ci]=false;
			        return;
		        }
			}
			tmp=Pop(S);
			if(tmp!=List[i]){
				index_of_bool[di_ji_ci]=false;
				return;
			} 
		}
		else if(List[i]<List[i-1]){
			tmp=Pop(S);
			if(tmp!=List[i]){
				index_of_bool[di_ji_ci]=false;
				return;
			}
		}
	}
	index_of_bool[di_ji_ci]=true;
}

int main()
{
	int stack,number,m,i,j;
	scanf("%d %d %d",&stack,&number,&m);
	int List[number];
	bool SuccessOrNot[m];
	for(j=0;j<m;j++){
		for(i=0;i<number;i++){
			scanf("%d",&List[i]);
		}
		Function(List,stack,number,SuccessOrNot,j);
	}
	for(i=0;i<m;i++){
		if(SuccessOrNot[i]==true) printf("YES");
		else if(SuccessOrNot[i]==false) printf("NO");
		if(i!=(m-1))printf("\n");
	}
	return 0;
}
