#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

int helper(vector<int> v,int pos,int sum){
  // cout<<sum<<" ";
  if(sum==0)return 1;
  else if(pos==0)return 0;
  else if(sum<v[pos-1])return helper(v,pos-1,sum);
  return helper(v,pos-1,sum-v[pos-1])+helper(v,pos-1,sum);
}

// Memoization
void solve(vector<int> v, int k){
  int sum=0;
  for(int i=0;i<v.size();i++)sum+=v[i];
  cout<<helper(v,v.size(),(sum+k)/2);
}

// TopDown
void solve2(vector<int> v,int k)
{
  int sum=0;
  for(int i=0;i<v.size();i++)sum+=v[i];
  sum=(sum+k)/2;
  vector<vector<int> > dp(v.size()+1,vector<int>(sum+1,0));
  for(int i=1;i<=v.size();i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(j<v[i-1])dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j] , dp[i-1][j-v[i-1]]+1);
    }
  }
  cout<<dp[v.size()][sum];
}

signed main()
{
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  solve(v,k);
  cout<<endl;
  solve2(v,k);
  return 0;
}