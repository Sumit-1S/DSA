#include<bits/stdc++.h>
using namespace std;

struct Edge{
  int src,dest,weight;
};

struct Graph{
  int E,V;
  Edge *edge = new Edge[V];
};

void BellmanFord(Graph *graph,int s)
{
  int V=graph->V,E=graph->E;
  int *distance = new int[V];
  for(int i=0;i<V;i++)
    distance[i]=INT_MAX;
  distance[s]=0;
  for(int i=1;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int w = graph->edge[j].weight;
      if(distance[u]!=INT_MAX and distance[u]+w<distance[v])
        distance[v] = distance[u]+w;
    }
  }
  for(int j=0;j<V;j++)
  {
    int u = graph->edge[j].src;
    int v = graph->edge[j].dest;
    int w = graph->edge[j].weight;
    if(distance[u]!=INT_MAX and distance[u]+w<distance[v]){
      cout<<"There Exists a Negative Cycle";
      return;
    }
  }
  for(int i=0;i<V;i++)
  cout<<"Distance of "<<i<<" from Source : "<<distance[i];
  return ;
}

int main()
{
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph *graph;
    graph->E=E;
    graph->V=V;
  
    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
  
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
  
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
  
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
  
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
  
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
  
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
  
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
    cout<<"Function called : \n";
    BellmanFord(graph, 0);
  
    return 0;
}