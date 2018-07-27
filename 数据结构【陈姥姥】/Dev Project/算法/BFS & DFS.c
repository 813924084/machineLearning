void Visit(Vertex V)
{
	printf("%d",V);
}

void DFS(LGraph Graph,Vertex S,void(*Visit)(Vertex))
{
	PtrToAdjVNode W;  //##
	Visit(S);
	Visited[S] = true;
	for(W=Graph->G[S].FirstEdge;W;W=W->Next){
		if(!Visited[W->AdjV]){						 //##
			DFS(Graph,W->AdjV,Visit);
		}
	}
}
//#############################################################

bool IsEdge(MGraph Graph,Vertex V1,Vertex V2)
{
	return (Graph->G[V1][V2]<INFINITY?true:false);
}

void BFS(MGraph Graph,Vertex S,void(*Visit)(Vertex))
{
	Queue Q;
	Vertex W,V;
	
	Q = CreateQueue();
	AddQ(Q,S);
	Visit(S);
	Visited[S] = true;
	
	while(!IsEmpty(Q)){
		V = DeleteQ(Q);
		for(W=0;W<Graph->Nv;W++){
			if(!Visited[W] && IsEdge(Graph,V,W)){
				Visit[W];
				Visited[W] = true;
				AddQ(Q,W);  //## 
			}
		}
	}
	
}
