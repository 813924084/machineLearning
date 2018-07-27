#include <stdio.h>
#include <stdlib.h>

typedef struct Poly* List;
struct Poly{
	int coe;
	int exp;
	List Next;
};

void Attach(int c,int e,List *r)
{
	List p = (List)malloc(sizeof(struct Poly));
	p->coe = c;
	p->exp = e;
	p->Next =NULL;
	(*r)->Next = p;
	*r = p;
}

List ReadPoly()
{
	int N;
	int c,e;
	List p,rear,tem;
	scanf("%d",&N);
	p = (List)malloc(sizeof(struct Poly));
	p->Next=NULL;
	rear = p;
	while(N){
		N--;
		scanf("%d %d",&c,&e);
		if(c==0)continue;
		Attach(c,e,&rear);
	}
	tem = p;
	p = p->Next;
	free(tem);
	return p;
}

int Compare(List L1,List L2)
{
	if(L1->exp>L2->exp) return 1;
	if(L1->exp<L2->exp) return -1;
	if(L1->exp==L2->exp) return 0;
	return 0;
}

List Mul(List L1,List L2)
{
	List p1,p2,p,rear,tmp,t;
	int e,c;
	p1=L1;
	p2=L2;
	if(p1==NULL || p2==NULL)return NULL;
	p = (List)malloc(sizeof(struct Poly));
	p->Next=NULL;
	rear = p;
	while(p2){
		Attach(p1->coe*p2->coe,p1->exp+p2->exp,&rear);
		p2 = p2->Next;
	}
	p1 = p1->Next;
	while(p1){
		p2 = L2;rear = p;
		while(p2){
			e = p1->exp+p2->exp;
			c = p1->coe*p2->coe;
			while(rear->Next && rear->Next->exp>e)rear=rear->Next;
			if (rear->Next && rear->Next->exp == e){
                if (rear->Next->coe + c)
                    rear->Next->coe += c;
                else {
                    tmp = rear->Next;
                    rear->Next = tmp->Next;
                    free(tmp);
                }
            }
            else {
                t = (List)malloc(sizeof(struct Poly));
                t->coe = c; t->exp = e;
                t->Next = rear->Next;
                rear->Next = t; rear = rear->Next;
            }
			p2=p2->Next;
		}
		p1=p1->Next;
	}
	t=p;
	p=p->Next;
	free(t);
	return p;
}
List Add(List L1,List L2)
{
	List p1,p2,p,rear,t;
	int sum;
	p1 = L1;
	p2 = L2;
	while(p1==NULL && p2==NULL)return NULL;
	while(p1==NULL) return p2;
	while(p2==NULL) return p1;
	p = (List)malloc(sizeof(struct Poly));
	rear = p;
	while(p1&&p2)
		switch(Compare(p1,p2)){
		case 1:Attach(p1->coe,p1->exp,&rear);p1=p1->Next;break;
		case -1:Attach(p2->coe,p2->exp,&rear);p2=p2->Next;break;
		case 0:sum=p1->coe+p2->coe;if(sum)Attach(sum,p1->exp,&rear);
			p1=p1->Next;p2=p2->Next;break;
	}
	for(;p1;p1=p1->Next)Attach(p1->coe,p1->exp,&rear);
	for(;p2;p2=p2->Next)Attach(p2->coe,p2->exp,&rear);
	t =p;
	p=p->Next;
	free(t);
	return p;
}
void Print(List L)
{
	List p =L;
	int flag=0;
	if(!p){printf("0 0\n");return;}
	while(p){
		if(!flag)
			flag=1;
		else printf(" ");
		printf("%d %d", p->coe, p->exp);
        p = p->Next;
	}
	printf("\n");
}
int main()
{
	List p1,p2,mul,add;
	p1 = ReadPoly();
	p2 = ReadPoly();
	mul = Mul(p1,p2);
	Print(mul);
	add = Add(p1,p2);
	Print(add);
	return 0;
}
