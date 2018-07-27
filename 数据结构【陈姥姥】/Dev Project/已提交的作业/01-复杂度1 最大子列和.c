#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum(int List[],int N)
{
  int i;
  int ThisSum=0,MaxSum=0;
  for (i=0;i<N;i++)
  {
    ThisSum+=List[i];
    if(ThisSum>MaxSum)
    MaxSum = ThisSum;
    else if(ThisSum<0)
    ThisSum = 0;
  }
  return MaxSum;
}
int main()
{
  int K,k,max=0;
  scanf("%d",&K);
  int a[K];
  int M=K;
  while(M!=0){
    scanf("%d",&k);
    a[M-1]=k;
    M--;
  }
  max = MaxSubseqSum(a,K);
  printf("%d\n",max);
  return 0;
}
