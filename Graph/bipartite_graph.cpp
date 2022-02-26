#include<bits/stdc++.h>
using namespace std;

bool bipartite(int curr,vector<vector<int> > graph,vector<int>& color)
{
  if(color[curr]==-1)color[curr]=1;
  for(int i=0;i<graph[curr].size();i++)
  {
    
    if(color[graph[curr][i]]==-1)
    {
      cout<<curr<<" ";
      color[graph[curr][i]]=1-color[curr];
      for(int j=0;j<color.size();j++)
        cout<<color[j]<<' ';
      cout<<endl;
      if(!bipartite(graph[curr][i],graph,color))
        return false;
    }
    else if(color[graph[curr][i]]==color[curr])
      return false;
  }
  return true;
}

bool solve(vector<vector<int> > graph){
  int n=graph.size();
  vector<int> color(n,-1);
  for(int i=0;i<n;i++)
  {
    if(color[i]==-1)
    {
      if(!bipartite(i,graph,color))
        return false;
    }
  }
  cout<<endl;
  return true;
}

int main()
{
  int n=5;
  vector<vector<int> > graph(n);
  graph[0].push_back((1,2));
  graph[1].push_back((0,2,3));
  graph[2].push_back((0,1,4));
  graph[3].push_back((1,2,4));
  graph[4].push_back((3,2));

  cout<<solve(graph);


  return 0;
}