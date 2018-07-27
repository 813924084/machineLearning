#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 10000
typedef int Vertex;
bool Visited[max];
//Down is Queue
typedef struct Node* PtrToNode;
struct Node{
	Vertex V;
	PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* Queue;
struct QNode{
	Position front,rear;
};

Queue CreateQueue()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = Q->rear = NULL;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->front==NULL);
}

bool AddQ(Queue Q,Vertex v)
{
	PtrToNode tmp;
	tmp = (PtrToNode)malloc(sizeof(struct Node));
	tmp->V = v;
	tmp->Next = NULL;
	if( IsEmpty(Q) ) Q->rear=Q->front=tmp;
	else {
		Q->rear->Next = tmp;
		Q->rear = tmp;
	}
	return true;
}

Vertex DeleteQ(Queue Q)
{
	PtrToNode frontNode;
	Vertex frontVertex;
	
	frontNode = Q->front;
	if(Q->rear==Q->front) Q->front=Q->rear=NULL;
	else  Q->front = frontNode->Next;
	frontVertex = frontNode->V;
	free( frontNode );
	return frontVertex;
}
//Up is Queue

//Down is Graph
typedef struct ENode* Edge;
struct ENode{
	Vertex V1,V2;
};

typedef struct GNode* Graph;
struct GNode{
	int numVertex;
	int numEdge;
	int G[max][max];  //这里容易错 
};

Graph CreateGraph(int vertexNum)
{
	Vertex m,n;
	Graph graph = (Graph)malloc(sizeof(struct GNode));
	graph->numEdge = 0;
	graph->numVertex = vertexNum;
	for(m=0;m<vertexNum;m++)
	    for(n=0;n<vertexNum;n++)
	        graph->G[m][n]=0;
	return graph;  
}

void InsertEdge(Graph graph,Edge edge)
{
	graph->G[edge->V1][edge->V2]=1;
	graph->G[edge->V2][edge->V1]=1;
}

bool IsEdge(Graph graph,Vertex W,Vertex V)
{
	return ( graph->G[W][V]==1 )?true:false;
}

int BFS(Graph graph,Vertex V)
{
	int count,level=0;
	Vertex tail,last;
	Queue Q;
	Vertex W,v1,v2;
	
	Q = CreateQueue();
	
	Visited[V] = true; count=1;
	//printf("\n第%d个点：%d\n",count,V);
	last = V;
	AddQ(Q,V);
	while( !IsEmpty(Q) ){
		W = DeleteQ(Q);
		for(v1=0;v1<graph->numVertex;v1++){
			if( !Visited[v1] && IsEdge(graph,W,v1) ){
				Visited[v1]=true;count++;
				AddQ(Q,v1);
				//printf("第%d个点：%d\n",count,v1);
				tail = v1;
			}
		}
		
		if( W==last ){
			level++; 
			last = tail;
		}
		
		if(level==6) break;	
	}
	return count;
}
//Up is Graph
void ResetVisited(int num)
{
	Vertex i;
	for(i=0;i<num;i++) Visited[i]=false;
}

int main()
{
	int N,i,count,cishu=0;
	double percent;
	Graph graph;
	Vertex v1;
	Vertex m,n;
	Edge edge;
	
	scanf("%d",&N);
	graph = CreateGraph(N);
	scanf("%d",&graph->numEdge);
	if(graph->numEdge!=0){
		edge = (Edge)malloc(sizeof(struct ENode));
		for(i=0;i<graph->numEdge;i++){
		    scanf("%d %d",&m,&n);
		    edge->V1 = m-1;
		    edge->V2 = n-1;
		    InsertEdge(graph,edge);	
	    }
	}
	/*
	for(m=0;m<graph->numVertex;m++){
		for(n=0;n<graph->numVertex;n++)
	        printf("%d ",graph->G[m][n]);
	    printf("\n");
	}*/
	    
	//for(v1=0;v1<N;v1++) Visited[v1]=false;
	
	for(v1=0;v1<N;v1++){
		ResetVisited(N);
		count = BFS(graph,v1);
		percent = 100.0*count/N;
		if(cishu!=0) printf("\n");
		cishu++;
		printf("%d: %.2f%%",v1+1,percent);
	}
	
	return 0;
}
