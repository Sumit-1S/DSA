#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int> > graph,vector<int> &visited,int n)
{
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0)
    {
      queue<int> q;
      q.push(i);
      while(!q.empty()){
        int curr = q.front();
        visited[curr]=1;
        q.pop();
        cout<<curr<<" ";
        for(int j=0;j<graph[curr].size();j++)
          if(visited[graph[curr][j]]==0)
            q.push(graph[curr][j]),visited[graph[curr][j]]=1;
      }
    }
  }
}

void print_dfs(int curr,vector<vector<int> > graph,vector<int> &visited)
{
  for(int i=0;i<graph[curr].size();i++)
  {
    if(visited[graph[curr][i]]==0)
    {
      visited[graph[curr][i]]=1;
      cout<<graph[curr][i]<<" ";
    }
  }
}

void dfs(vector<vector<int> > graph,vector<int> &visited,int n)
{
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0)
      cout<<i<<" ";visited[i]=1,print_dfs(i,graph,visited);
  }
}

int main()
{
  int n=6;
  vector<vector<int> > graph(n);
  graph[0].push_back((1,2));
  graph[1].push_back((0,2,3,4));
  graph[2].push_back((0,1,3,4));
  graph[3].push_back((1,2,4,5));
  graph[4].push_back((1,2,3,5));
  graph[5].push_back((3,4));
  
  vector<int>visited(n,0);
  cout<<"BFS:-> ";
  bfs(graph,visited,n);
  cout<<endl;
  cout<<"DFS:-> ";
  vector<int>visited2(n,0);
  dfs(graph,visited2,n);
  return 0;
}