#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertexNum 10
#define INFINITY 65535
char Visited1[10]={false,false,false,false,false,false,false,false,false,false};
char Visited2[10]={false,false,false,false,false,false,false,false,false,false};

typedef int Vertex;
//下面邻接矩阵 
typedef struct GNode* PtrToGNode;
struct GNode{
	int vertexNum;
	int edgeNum;
	int G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode Graph;

typedef struct ENode* Edge;
struct ENode{
	Vertex v1,v2;
};

Graph CreateGraph(int maxVertexNum)
{
	Graph graph;
	Vertex v,w;
	graph = (Graph)malloc(sizeof(struct GNode));
	graph->vertexNum = maxVertexNum;
	graph->edgeNum = 0;
	for(w=0;w<graph->vertexNum;w++)
	    for(v=0;v<graph->vertexNum;v++)
	        graph->G[w][v] = INFINITY;
	
	return graph;
}

void InsertEdge(Graph graph,Edge edge)
{
	graph->G[edge->v1][edge->v2] = 1;
	graph->G[edge->v2][edge->v1] = 1;
}
//上面邻接矩阵 

//下面链队
typedef struct Node* PtrToNode;
struct Node{
	Vertex Vertex;
	PtrToNode Next;
};

typedef struct QNode* Queue;
struct QNode{
	PtrToNode front,rear;
};

Queue CreateQueue()
{
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->rear=Q->front=NULL;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->front==NULL);
}

void AddQueue(Queue Q,Vertex v)
{
	PtrToNode tmp;
	tmp = (PtrToNode)malloc(sizeof(struct Node));
	tmp->Vertex = v;
	tmp->Next = NULL;
	if(IsEmpty(Q)){
		Q->front = Q->rear = tmp;
	}
	else {
		Q->rear->Next = tmp;
		Q->rear = tmp;
	}
}

Vertex DeleteQueue(Queue Q)
{
	PtrToNode frontCell;
	Vertex v;

	frontCell = Q->front;
	if(Q->front == Q->rear) Q->rear = Q->front = NULL;
	else {
	    Q->front = Q->front->Next;
	}
	v = frontCell->Vertex;
	free(frontCell);
	return v;
}
//上面链队 

void Visit(Vertex v)
{
	printf("%d ",v);
}

bool IsEdge(Graph graph,Vertex V, Vertex W){
	return graph->G[V][W]<INFINITY?true:false;
}

void DFS(Graph graph , Vertex v ,void(*Visit)(Vertex))
{
	Vertex n;
	Visit(v);
	Visited1[v] = true;
	for(n=0;n<graph->vertexNum;n++)
		if((!Visited1[n]) && IsEdge(graph,v,n)){
			DFS(graph,n,Visit);
		}
}

void BFS(Graph graph,Vertex v,void (*Visit)(Vertex))
{
	Queue Q;
	Vertex m;
	Vertex n;
	Q = CreateQueue();
	Visit(v);
	Visited2[v]=true;
	AddQueue(Q,v);
	while(!IsEmpty(Q)){
		m = DeleteQueue(Q);
		for(n=0;n<graph->vertexNum;n++)
			if((!Visited2[n])&&IsEdge(graph,m,n)){
				Visit(n);
	            Visited2[n]=true;
	            AddQueue(Q,n);
			}
	}
}

void DFSBianLi(Graph graph,void (*Visit)(Vertex))
{
	
}

int main()
{
	int maxVertexNum,maxEdgeNum,i,t;
	Vertex w;
	Vertex m;
	Edge edge;
	Graph graph;
	scanf("%d %d",&maxVertexNum,&maxEdgeNum);
	graph = CreateGraph(maxVertexNum);
	graph->edgeNum = maxEdgeNum;
	if(graph->edgeNum!=0)
		for(i=0;i<graph->edgeNum;i++){
			edge = (Edge)malloc(sizeof(struct ENode));
		    scanf("%d %d",&edge->v1,&edge->v2);
		    InsertEdge(graph,edge);
		}
	t=1;
	for(m=0;m<graph->vertexNum;m++){
		if(!Visited1[m]) {
			if(t==1) printf("{ ");
			else printf("\n{ ");
			t++;
			DFS(graph,m,Visit);
			printf("}");
		}
	}
	printf("\n");
	t=1;
	for(m=0;m<graph->vertexNum;m++){
		if(!Visited2[m]) {
			if(t==1) printf("{ ");
			else printf("\n{ ");
			t++;
			BFS(graph,m,Visit);
			printf("}");
		}
	}
	return 0;
}


