#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

void solve(string s,vector<vector<char> > &ans, vector<bool>&visited, vector<char> temp, int pos){
  if(pos==s.size()){
    ans.push_back(temp);
    return;
  }
  for(int i=0;i<s.size();i++){
    if(!visited[i]){
      visited[i]=1;
      temp.push_back(s[i]);
      solve(s,ans,visited,temp,pos+1);
      temp.pop_back();
      visited[i]=0;
    }
  }

}

int main()
{
  string s;
  cin>>s;
  vector<vector<char> > ans;
  vector<char> temp;
  vector<bool> visited(s.size(),0);
  solve(s,ans,visited,temp,0);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++)
      cout<<ans[i][j] ;
      cout<<endl;
  }

  return 0;
}