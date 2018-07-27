BinTree Insert( BinTree BST, ElementType X )
{
  if(!BST){
    BST=(BinTree)malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Left=BST->Right=NULL;
  }
  else {
    if(X>BST->Data) BST->Right=Insert(BST->Right,X);
    else if(X<BST->Data) BST->Left=Insert(BST->Left,X);
    else ;
  }
  return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
  BinTree tmp;
  if(!BST)printf("Not Found\n");
  else{
    if(X>BST->Data) BST->Right=Delete(BST->Right,X);
    else if(X<BST->Data) BST->Left=Delete(BST->Left,X);
    else{
      if(BST->Left && BST->Right){
        tmp=FindMin(BST->Right);
        BST->Data = tmp->Data;
        BST->Right = Delete(BST->Right,BST->Data);
      }
      else{
        tmp=BST;
        if(!BST->Left) BST = BST->Right;
        else BST = BST->Left;
        free(tmp);
      }
    }
  }
  return BST;
}

Position Find( BinTree BST, ElementType X )
{
  while(BST){
    if(X>BST->Data) BST=BST->Right;
    else if(X<BST->Data) BST=BST->Left;
    else break;
  }
  return BST;
}

Position FindMin( BinTree BST )
{
  if(!BST) return NULL;
  else {
    while(BST->Left) BST=BST->Left;
  }
  return BST;
}

Position FindMax( BinTree BST )
{
  if(!BST) return NULL;
  else {
    while(BST->Right) BST=BST->Right;
  }
  return BST;
}
