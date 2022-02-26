#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

int topdown(vector<int>v,int sum,int n)
{
  vector<vector<int> > dp(n+1,vector<int>(sum+1));
  for(int i=0;i<=n;i++)
    dp[i][0]=0;
  for(int i=1;i<=sum;i++)
    dp[0][i]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(j>=v[i-1])
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]] + 1);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][sum];
}

int memoize(vector<int> v,int sum,int n,vector<vector<int> >&dp)
{
  if(n==0)return 0;
  else if(sum==v[n-1])return 1;
  else if(sum<v[n-1])return memoize(v,sum,n-1,dp);
  else return max(memoize(v,sum-v[n-1],n-1,dp)+1,memoize(v,sum,n-1,dp));
}

signed main()
{
  int n,sum=0;
  cin>>n>>sum;
  vector<int>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  cout<<topdown(v,sum,n)<<endl;
  vector<vector<int> >dp2(n+1,vector<int>(sum+1,0));
  cout<<memoize(v,sum,n,dp2);
  return 0;
}