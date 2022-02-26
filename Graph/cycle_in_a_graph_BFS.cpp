#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int> > graph,vector<int> &visited,int i){
  queue<pair<int,int>  > q;
  q.push(make_pair(i,-1));
  while(!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for(int j=0;j<graph[node].size();j++)
    {
      if(visited[graph[node][j]]==0)
      {
        visited[graph[node][j]]=1;
        q.push(make_pair(graph[node][j],node));
      }
      else if(parent!=graph[node][j])
        return true;
    }
  }
  return false;
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
  vector<int> visited(n,0);
  int flag=0;
  for(int i=0;i<n;i++){
    if(visited[i]==0){
      visited[i]=1;
      if(solve(graph,visited,i)){
        flag=1;break;
      }
    }
  }
  flag==0?cout<<"no cycle exists":cout<<"cycle exists";


  return 0;
}