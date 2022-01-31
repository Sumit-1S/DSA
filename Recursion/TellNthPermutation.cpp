#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

void solve(string v,vector<string>& ans,int pos){
  if(pos==v.size())
  {
    cout<<v<<endl;
    ans.push_back(v);
    return;
  }
  for(int i=pos;i<v.size();i++){
    swap(v[pos],v[i]);
    solve(v,ans,pos+1);
    swap(v[pos],v[i]);
  }
}
    
string getPermutation(int n, int k) {
  vector<string> ans;
  string temp="";
  for(int i=0;i<n;i++)temp+='0'+(i+1);
  solve(temp,ans,0);
  return ans[k-1];
}

int main()
{
  int n=4,k=9;
  cout<<getPermutation(n,k);
  return 0;
}
