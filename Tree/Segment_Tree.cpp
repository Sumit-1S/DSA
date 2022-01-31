#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

vector<int>a(1e5+2),tree(4e5+2);

void build(int node,int st,int end){
  if(st==end)
  {
    tree[node]=a[st];
    return;
  }
  int mid=(st+end)/2;
  build(2*node,st,mid);
  build(2*node+1,mid+1,end);

  tree[node] = tree[2*node]+tree[2*node+1]; //If we want to maintain sum in a range
  // tree[node] = max(tree[2*node],tree[2*node+1]); //If we want to maintain the max element
}

signed main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  build(1,0,n-1);
  for(int i=1;i<20;i++)cout<<tree[i]<<" ";
  return 0;
}