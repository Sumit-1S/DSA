#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

int mx=INT_MIN;

void helper(string s,int i,int j,int count){
  if(i>j){mx=max(mx,count);return;}
  if(i==j){mx=max(mx,count+1);return;}
  if(s[i]==s[j])helper(s,i+1,j-1,count+2);
  helper(s,i+1,j,count);
  helper(s,i,j-1,count);
}

signed main()
{
  string s;
  cin>>s;
  helper(s,0,s.size()-1,0);
  cout<<mx;
  return 0;
}