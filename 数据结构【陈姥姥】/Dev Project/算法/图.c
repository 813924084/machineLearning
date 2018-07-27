#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 65535  //##
#define Maxsize 100
typedef int WeightType;  //##
typedef int Vertex;

struct GNode{
	int Ne;
	int Nv;
	WeightType G[Maxsize][Maxsize];
	char W[Maxsize];
};
typedef struct GNode* MGraph;

struct ENode{
	Vertex V1,V2;
	WeightType Weight;
};
typedef struct ENode* Edge;

MGraph CreateGraph(int numVertex)
{
	Vertex V,W;
	
	MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Ne = 0;
	Graph->Nv = numVertex;
	
	for(V=0;V<numVertex;V++)
		for(W=0;W<numVertex;W++)
			Graph->G[V][W] = INFINITY;
			
	return Graph;  //##
}

void InsertEdge(MGraph Graph,Edge edge)
{
	Graph->G[edge->V1][edge->V2] = edge->Weight;
	Graph->G[edge->V2][edge->V1] = edge->Weight;
}

MGraph BuildGraph()
{
	int numVertex,i;
	MGraph Graph;
	Edge edge;
	
	scanf("%d",&numVertex);
	Graph = CreateGraph(numVertex);
	scanf("%d",&Graph->Ne);  //##
	if(Graph->Ne>0){
		edge = (Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			scanf("%d %d %d",&edge->V1,&edge->V2,&edge->Weight);
			InsertEdge(Graph,edge);
		}
		
	}
	return Graph;
}


//######################################################################
#define Maxsize 100
typedef int Vertex;
typedef int WeightType;

struct ENode{
	Vertex V1,V2;
	WeightType Weight;
};
typedef struct ENode* Edge;

typedef struct AdjNode* PtrToAdjNode;
struct AdjNode{
	Vertex V;
	WeightType Weight;//##
	PtrToAdjNode Next;
};

typedef struct Node{
	PtrToAdjNode FirstEdge;
}List[Maxsize];

struct GNode{
	int Ne,Nv;
	List G;
};
typedef struct GNode* LGraph;

LGraph CreateGraph(int numVertex)
{
	Vertex W;
	
	LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Ne = 0;
	Graph->Nv = numVertex;
	
	for(W=0;W<numVertex;W++){
		Graph->G[W].FirstEdge = NULL;
	}
	
	return Graph;
}

void InsertEdge(LGraph Graph,Edge E)
{
	PtrToAdjNode NewNode;
	
	NewNode = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
	NewNode->V = E->V2;
	NewNode->Weight = E->Weight;    //##
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	
	NewNode = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
	NewNode->V = E->V1;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
	
}

LGraph BuildGraph()
{
	int numVertex;
	LGraph Graph;
	Edge E;
	
	scanf("%d",&numVertex);
	Graph = CreateGraph(numVertex);
	scanf("%d",&Graph->Ne);
	if(Graph->Ne!=0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			scanf("%d %d %d",&edge->V1,&edge->V2,&edge->Weight);
			InsertEdge(Graph,edge);
		}
	}
	
	return Graph;
}






