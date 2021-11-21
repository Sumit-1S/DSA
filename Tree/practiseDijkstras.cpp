#include<bits/stdc++.h>
using namespace std;
#define V 9

int min_key(int *key, int* visited)
{
  int min=INT_MAX,min_idx;
  for(int i=0;i<V;i++)
    if(!visited[i] and key[i]<min)
      min=key[i],min_idx=i;
  return min_idx;
}

int main()
{
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  int visited[V],key[V];
  for(int i=0;i<V;i++) visited[i]=0,key[i]=INT_MAX;
  key[0]=0;
  for(int i=0;i<V;i++)
  {
    int u= min_key(key,visited);
    visited[u]=1;
    for(int v=0;v<V;v++)
    {
      if(graph[u][v] and visited[v]==0 and key[u]!=INT_MAX and key[u]+graph[u][v]<key[v])
        key[v] = key[u]+graph[u][v];
    }
  }
  for(int i=0;i<V;i++)cout<<"Distance till "<<i<<" from source node is : "<<key[i]<<endl;
  return 0;
}