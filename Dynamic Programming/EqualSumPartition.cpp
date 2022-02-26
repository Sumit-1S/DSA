#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

bool topdown(vector<int> v,int sum,int n)
{
  vector<vector<bool> > dp(n+1,vector<bool>(sum+1));
  for(int i=0;i<=n;i++)
    dp[i][0]=true;
  for(int i=1;i<=sum;i++)
    dp[0][i]=false;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(v[i-1]<=j)
        dp[i][j] = dp[i-1][j-v[i-1]] or dp[i-1][j];
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][sum];
}

bool memoize(vector<int> v,int sum,int n,vector<vector<bool> > &dp)
{
  if(n==0)return dp[n][sum]=false;
  else if(sum-v[n-1]==0)return dp[n][sum]=true;
  else if(sum<v[n-1])return dp[n][sum] = memoize(v,sum,n-1,dp);
  else return dp[n][sum] = memoize(v,sum-v[n-1],n-1,dp) or memoize(v,sum,n-1,dp);
}

signed main()
{
  int n,sum=0;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i],sum+=v[i];
  if(sum%2==0){
    cout<<topdown(v,sum/2,n)<<endl;
    vector<vector<bool> >dp2(n+1,vector<bool>(sum+1,false));
    cout<<memoize(v,sum/2,n,dp2);
  }
  else cout<<-1;
  return 0;
}