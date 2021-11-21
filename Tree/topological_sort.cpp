#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> g[],vector<bool> &visited,stack<int> &st,int i)
{
    visited[i]=true;
    int n=g[i].size();
    for(int j=0;j<n;j++)
        if(!visited[g[i][j]])
            sort(g,visited,st,g[i][j]);
    
    st.push(i);
}


void topological_sort(vector<int> g[],int v)
{
    vector<bool> visited(v,false);
    stack<int> st;
    for(int i=0;i<v;i++)
        if(!visited[i])
            sort(g,visited,st,i);

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    int e,v;
    cin>>e>>v;
    vector<int> g[v];
    for(int i=0;i<v;i++)
    {
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
    }
    topological_sort(g,v);
    return 0;
}