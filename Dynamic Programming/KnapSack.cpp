#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>


int topdown(vector<int> val,vector<int> wt,int w,vector<vector<int> > dp)
{
  int n = val.size();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=w;j++)
    {
      if(wt[i-1]<=j)
        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][w];
}

int memoize(vector<int> val,vector<int> wt,int w,int n,vector<vector<int> >&dp)
{
  if(w==0 or n==0)
    return 0;
  else if(dp[n][w]!=-1)return dp[n][w];
  else if(wt[n-1]<=w)
    return dp[n][w]=max(val[n-1]+memoize(val,wt,w-wt[n-1],n-1,dp),memoize(val,wt,w,n-1,dp));
  else 
    return dp[n][w] = memoize(val,wt,w,n-1,dp);
}

signed main()
{
  int n,w;
  cin>>n>>w;
  vector<int> val(n);
  vector<int> wt(n);
  for(int i=0;i<n;i++)
    cin>>val[i]>>wt[i];
  vector<vector<int> > dp1(n+1,vector<int>(w+1,0));
  cout<<topdown(val,wt,w,dp1);
  cout<<endl;
  vector<vector<int> > dp2(n+1,vector<int>(w+1,-1));
  memoize(val,wt,w,n,dp2);
  cout<<dp2[n][w];
  return 0;
}