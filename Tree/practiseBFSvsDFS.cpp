#include<bits/stdc++.h>
using namespace std;

void printBFS(vector<vector<int> > graph,int visited[])
{
  queue <int> q;
  for(int i=0;i<graph.size();)
  {
    for(int j=0;j<graph[i].size();j++)
    {
      if(visited[graph[i][j]-1]==-1){
        q.push(graph[i][j]);
        visited[graph[i][j]-1]=1;
      }
    }
    i=q.front();
    cout<<i<<" ";
    q.pop();
  }

}

void printDFS(vector<vector<int> > graph,int *visited,int vertex)
{
  visited[vertex]=1;
  cout<<vertex<<" ";
  vector<int>::iterator i;
  for(i=graph[vertex].begin();i!=graph[vertex].end();i++)
    if(visited[*i]==-1)
      printDFS(graph,visited,*i);
}

int main()
{
  int n,t;
  cin>>n;
  vector<vector<int> > graph;
  vector<int> temp;
  int *visited = new int[n];
  for(int i=0;i<n;i++){
    t=0;
    visited[i]=-1;
    temp.push_back(i);
    while(t!=-1)
      cin>>t,temp.push_back(t);
    graph.push_back(temp);
  }  
  // printBFS(graph,visited);
  cout<<endl;
  printDFS(graph,visited,0);
  return 0;
}