#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MIN -20000

typedef struct HNode* Heap;
struct HNode{
	int* data;
	int capacity;
	int size;
};

Heap CreateHeap(int capacity)
{
	Heap h = (Heap)malloc(sizeof(struct HNode));
	h->data = (int *)malloc(sizeof(int)*(capacity+1));
	h->size=0;
	h->capacity = capacity;
	h->data[0]= MIN;
	return h;
}

bool Insert(Heap H,int X)
{
	int i;
	i=++H->size;
	for( ;H->data[i/2]>X;i/=2 ){
		H->data[i]=H->data[i/2];
	}
	H->data[i] = X;
	return true;
}

int main()
{
	int K,N,i,tmp;
	int count=0,count2;
	Heap H;
	scanf("%d %d",&K,&N);
	H = CreateHeap(K);
	for(i=0;i<K;i++){
		scanf("%d",&tmp);
		Insert(H,tmp);
	}
	
	for(i=0;i<N;i++){
		count2=0;
		scanf("%d",&tmp);
		while(tmp>=1){
			if(count2!=0) printf(" ");
			printf("%d",H->data[tmp]);
			count2++;
			tmp/=2;
		}
		count++;
		if(count!=(N)) printf("\n");
	}
	
	return 0;
}
