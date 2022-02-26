#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

ll max(ll a,ll b)
 {
     return a>=b?a:b;
 }
    
 ll solve(vector<int> v,int l,int r){
  ll left=INT_MIN;
  ll right=INT_MIN;
  ll temp=1;
  for(int i=l;i<=r;i++)
    temp=temp*v[i],left=max(left,temp);
  temp=1;
  for(int i=r;i>=l;i--)
    temp=temp*v[i],right=max(right,temp);
    
  return  max(left,right);
}

int maxProduct(vector<int>& nums)
{
  ll i=0,j=0,mx=INT_MIN;
  for(int j=0;j<nums.size();j++)
  {
    if(nums[j]==0){
        mx = max(mx,max(0,solve(nums,i,j-1))),i=j+1;
    }
    else if(j==nums.size()-1)
      mx = max(mx,solve(nums,i,j));
  }
  return mx;
}

signed main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];  
  cout<<maxProduct(v);
  return 0;
}