#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

int helper(vector<int> v,int pos,int sum){
  if(pos==0){
    if(sum==0)return 1;
    return 0;
  }
  if(sum >= v[pos-1])return helper(v,pos-1,sum-v[pos-1]) + helper(v,pos-1,sum);
  return helper(v,pos-1,sum);
}

void solve(vector<int> v,int target){
  int sum=0;
  for(int i=0;i<v.size();i++)
    sum+=v[i];
  int find = (sum+target)/2;
  cout<<helper(v,v.size(),find);
}

signed main()
{
  int n,t;
  cin>>n>>t;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  solve(v,t);

  // solve();
  return 0;
}