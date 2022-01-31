#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

void solve(int n,vector<int> v,vector<int> arr,int pos){
  if(pos==n){
    for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
    cout<<endl;
    return;
  }
  arr.push_back(v[pos]);
  solve(n,v,arr,pos+1);
  arr.pop_back();
  solve(n,v,arr,pos+1);
}

int main()
{
  int n;
  cin>>n;
  vector<int> v(n),arr;
  for(int i=0;i<n;i++)cin>>v[i];
  int pos=0;
  solve(n,v,arr,pos);
  return 0;
}