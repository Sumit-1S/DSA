#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

// void solve(vector<int> v,int pos,vector<int> &sum,int s){
//   if(pos==0)return;
//   sum.push_back(s+v[pos-1]);
//   solve(v,pos-1,sum,s+v[pos-1]);
//   solve(v,pos-1,sum,s);
// }

// void find1(vector<int> v){
//   vector<int> sum;
//   solve(v,v.size(),sum,0);
//   sum.push_back(0);
//   sort(sum.begin(),sum.end());
//   // for(int i=0;i<sum.size();i++)cout<<sum[i]<<" ";
//   cout<<abs(sum[sum.size()/2-1]-sum[sum.size()/2]);
// }


void find2(vector<int> v)
{
  int sum=0;
  for(int i=0;i<v.size();i++)sum+=v[i];
  vector<vector<bool> > dp(v.size()+1,vector<bool>(sum+1));
  for(int i=0;i<=v.size();i++)
    dp[i][0]=true;
  for(int i=1;i<=sum;i++)
    dp[0][i]=false;
  for(int i=1;i<=v.size();i++)
  {
    for(int j=1;j<=sum;j++)
    {
      dp[i][j] = dp[i-1][j];
      if(v[i-1]<=j)
        dp[i][j] = dp[i][j] or dp[i-1][j-v[i-1]];
    }
  }
  for(int i=sum/2;i>=0;i--){
    if(dp[v.size()][i]==true)
    {
      cout<<sum-2*i<<endl;
      break;
    }
  }
  return;
}
signed main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  // find1(v);
  find2(v);
  return 0;
}