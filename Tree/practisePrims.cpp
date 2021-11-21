#include<bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int *key,int *visited)
{
  int min=INT_MAX,min_idx;
  for(int i=0;i<V;i++)
    if(visited[i]==0 and key[i]<min)
      min=key[i],min_idx=i;
  return min_idx;
}

int main()
{
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };  
  int visited[V],key[V];
  for(int i=0;i<V;i++)
    visited[i]=0,key[i]=INT_MAX;
  key[0]=0;
  for(int i=0;i<V;i++)
  {
    int u=minKey(key,visited);
    visited[u]=1;
    for(int v=0;v<V;v++)
      if(graph[u][v] and !visited[v] and key[v]>graph[u][v])
        key[v]=graph[u][v];
  }
  int cost=0;
  for(int i=0;i<V;i++)
    cost+=key[i];
    cout<<cost;
  return 0;
}



