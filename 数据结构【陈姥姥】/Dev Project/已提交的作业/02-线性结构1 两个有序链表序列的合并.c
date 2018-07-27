#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1,List L2 )
{
  List rear1,rear2,tmp1,tmp2,L;
  rear1=L1;
  rear2=L2;
  while(rear1->Next){
    rear2=L2;
    while(rear2->Next && rear2->Next->Data<rear1->Next->Data)rear2=rear2->Next;
    if(rear2->Next==NULL){
      tmp1=rear1->Next->Next;
      rear1->Next->Next=NULL;
      rear2->Next=rear1->Next;
      rear1->Next=tmp1;
    }
    else if(rear2->Next->Data>=rear1->Next->Data){
      tmp1=rear1->Next->Next;
      tmp2=rear2->Next;
      rear2->Next=rear1->Next;
      rear2->Next->Next=tmp2;
      rear1->Next=tmp1;
    }
    //rear1=rear1->Next;
  }
  L = (List)malloc(sizeof(struct Node));
  L->Next = L2->Next;
  L1->Next = NULL;
  L2->Next = NULL;
  return L; 
}
