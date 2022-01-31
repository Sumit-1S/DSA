#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>
int n,r;
vector<vector<int> > v(n+1,vector<int>(r+1));

int combine(int n,int r){
  cout<<v[n][r]<<endl;
  if(r==0 or r==n)return 1;
  else if(r==1 or r==n-1)return n;
  else v[n][r]=combine(n-1,r)+combine(n-1,r-1);
}

int main()
{
  cin>>n>>r;
  for(int i=0;i<=n;i++)
  for(int j=0;j<=r;j++)
  v[i][j]=0;
  combine(n,r);
  cout<<v[n][r];
  return 0;
}