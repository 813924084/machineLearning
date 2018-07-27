#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertexNum 10

char Visited1[10]={false,false,false,false,false,false,false,false,false,false};
char Visited2[10]={false,false,false,false,false,false,false,false,false,false};

typedef int Vertex;
//下面邻接表 
typedef struct ENode* Edge;
struct ENode{
	Vertex v1,v2;
};

typedef struct AdjNode* PtrToAdjNode;
struct AdjNode{
	Vertex index;
	PtrToAdjNode next;
};

typedef struct HNode{
	Vertex head;
	PtrToAdjNode firstEdge;
}AdjList[MaxVertexNum];

typedef struct GNode* Graph;
struct GNode{
	int vertexNum;
	int edgeNum;
	AdjList G;
};

Graph CreateGraph(int maxVertexNum)
{
	Graph graph;
	Vertex w;
	graph = (Graph)malloc(sizeof(struct GNode));
	graph->vertexNum = maxVertexNum;
	graph->edgeNum = 0;
	for(w=0;w<graph->vertexNum;w++)  graph->G[w].firstEdge=NULL;
	
	return graph;
}

void InsertEdge(Graph graph,Edge edge)
{
	PtrToAdjNode tmp;
	
	tmp=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
	tmp->index = edge->v2;
	tmp->next = graph->G[edge->v1].firstEdge;
	graph->G[edge->v1].firstEdge = tmp;
	
	tmp=(PtrToAdjNode)malloc(sizeof(struct AdjNode));
	tmp->index = edge->v1;
	tmp->next = graph->G[edge->v2].firstEdge;
	graph->G[edge->v2].firstEdge = tmp;
}
//上面邻接表 

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

void DFS(Graph graph , Vertex v ,void(*Visit)(Vertex))
{
	PtrToAdjNode w;
	Visit(v);
	Visited1[v] = true;
	for(w=graph->G[v].firstEdge;w;w=w->next)
		if(!Visited1[w->index]){
			DFS(graph,w->index,Visit);
		}
}

void BFS(Graph graph,Vertex v,void (*Visit)(Vertex))
{
	Queue Q;
	Vertex m;
	PtrToAdjNode n;
	Q = CreateQueue();
	Visit(v);
	Visited2[v]=true;
	AddQueue(Q,v);
	while(!IsEmpty(Q)){
		m = DeleteQueue(Q);
		for(n=graph->G[m].firstEdge;n;n=n->next)
			if(!Visited2[n->index]){
				Visit(n->index);
	            Visited2[n->index]=true;
	            AddQueue(Q,n->index);
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


