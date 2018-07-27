#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#define maxSize 100
typedef int Vertex;
struct Array{
	double x,y;
}T[maxSize];

bool Visited[maxSize];

bool Safe(double m,double n,double step)
{
	if( (50-m)<=step ) return true;
	else if( (m+50)<=step ) return true;
	else if( (50-n)<=step ) return true;
	else if( (n+50)<=step ) return true;
	else return false;
}

bool Step (Vertex v,Vertex w,double step)
{
	double length;
	length = sqrt( (T[v].x-T[w].x)*(T[v].x-T[w].x)+(T[v].y-T[w].y)*(T[v].y-T[w].y) );
	if( length<=20 ) return true;
	else return false;
}

bool FirstStep(double m,double n,double step)
{
	double length = sqrt( m*m+n*n ) -7.5;
	if( length<=step ) return true;
	else return false;
}

bool DFS( Vertex w,double step,int num )
{
	Vertex v;
	bool reason;
	if( Safe( T[w].x,T[w].y,step ) ) return true;
	else {
		for(v=0;v<num;v++){
			if( !Visited[v] && Step( w,v,step ) ){
				Visited[v] = true;
				reason = DFS( v,step,num );
				if(reason == true) return true;
			}
		}
	}
	return false;
}


bool Save007(int num,double step)
{
	Vertex i;
	bool reason=false;
	for(i=0;i<num;i++){
		if( FirstStep( T[i].x,T[i].y,step ) && !Visited[i] ){
			Visited[i] = true;
			reason = DFS( i,step,num );
			if( reason==true ) return true;
		}
	}
	return false;
}

int main()
{
	int num;
	Vertex i;
	double step,X,Y;
	scanf("%d %lf",&num,&step);
	
	for(i=0;i<num;i++){
		scanf("%lf %lf",&X,&Y);
		T[i].x = X;
		T[i].y = Y;
		Visited[i]=false;
	}
	
	if( Save007(num,step) ) printf("Yes");
	else printf("No");
	
	return 0;
}
