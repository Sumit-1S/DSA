#include<bits/stdc++.h>
using namespace std;

struct edge{
  int start;
  int dest;
  int weight;
};

struct comp{
  bool operator()(edge a,edge b)
  {
    return a.weight<b.weight;
  }
};

int main()
{
  int e,v,t;
  cout<<"Enter number of Edges: ";
  cin>>e;
  cout<<"Enter number of vertices: ";
  cin>>v;

  edge *graph = new edge[e];
  
  for(int i=0;i<e;i++)
    cin>>graph[i].weight>>graph[i].start>>graph[i].dest;

  sort(graph,graph+e,comp());

  int *visited = new int[v];
  for(int i=0;i<v;i++)  visited[i]=0;

  int total_cost=graph[0].weight;
  visited[graph[0].start]=visited[graph[0].dest]=1;

  for(int i=1;i<e;i++)
  {
    if(visited[graph[i].dest]==0 || visited[graph[i].start]==0)
    {
      total_cost+=graph[i].weight;
      visited[graph[i].start]=1;
      visited[graph[i].dest]=1;
    }
  }
  
  cout<<"Total cost is: "<<total_cost;
  return 0;
}