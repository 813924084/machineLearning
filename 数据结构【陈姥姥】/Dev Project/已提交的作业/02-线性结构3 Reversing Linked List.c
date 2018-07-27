#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define maxsize 20

struct List {
	char* Front;
	int Data;
	char* End;
}T1[maxsize],T2[maxsize],T3[maxsize];

void Print(struct List T[],int K)
{
	int i,count=1;
	for(i=0;i<K;i++){
		if(count<K){
			printf("%s %d %s\n",T[i].Front,T[i].Data,T[i].End);
		}
		else printf("%s %d %d",T[i].Front,T[i].Data,-1);
		count++;
	}
}

int main()
{
	int fir=0,K,k,N,i,j,part,t,rest;
	char *first;
	char y[]="-1";
	first = (char*)malloc(sizeof(5));
	
	scanf("%s %d %d",first,&K,&N);
	
	for(i=0;i<K;i++){
		T1[i].Front=(char*)malloc(sizeof(5));
		//T1[i].Data = (int)malloc(sizeof(4));
		T1[i].End=(char*)malloc(sizeof(5));
	}
	for(i=0;i<K;i++){
		T2[i].Front=(char*)malloc(sizeof(5));
		//T2[i].Data = (int)malloc(sizeof(4));
		T2[i].End=(char*)malloc(sizeof(5));
	}
	for(i=0;i<K;i++){
		T3[i].Front=(char*)malloc(sizeof(5));
		//T3[i].Data = (int)malloc(sizeof(4));
		T3[i].End=(char*)malloc(sizeof(5));
	}
		
	for(i=0;i<K;i++){
		scanf("%s %d %s",T1[i].Front,&T1[i].Data,T1[i].End);
	}
	
	for(i=0;i<K;i++){
		if(strcmp(T1[i].Front,first)==0){
			fir = i;
		}	
	}
	
	strcpy(T2[0].Front,T1[fir].Front);
	T2[0].Data=T1[fir].Data;
	strcpy(T2[0].End,T1[fir].End);
	
	k=K;
	
	for(i=1;i<K;i++){
		if(strcmp(T2[i-1].End,y)==0){
			K=i;
			break;
		}
		for(j=0;j<k;j++){
			if(strcmp(T2[i-1].End,T1[j].Front)==0){
				strcpy(T2[i].Front,T1[j].Front);
	            T2[i].Data=T1[j].Data;
	            strcpy(T2[i].End,T1[j].End); 
			}
	    }
	}
	
	if(N!=0){
	part=K/N;
	rest=K%N;
	if(part){
		for(i=1;i<=part;i++){
			t=i*N-1;
			for(j=(i-1)*N;j<i*N;j++){
				strcpy(T3[j].Front,T2[t].Front);
				T3[j].Data=T2[t].Data;
				strcpy(T3[j].End,T2[t].End);
				t--;	
			}
		}
		if(rest){
			for(i=part*N;i<K;i++){
				strcpy(T3[i].Front,T2[i].Front);
				T3[i].Data=T2[i].Data;
				strcpy(T3[i].End,T2[i].End);	
			}
		}
		for(i=0;i<K-1;i++){
			strcpy(T3[i].End,T3[i+1].Front);
		}
		Print(T3,K);
    }
	else Print(T2,K);
    }
	if(N==0) Print(T2,K);
	return 0;
}
