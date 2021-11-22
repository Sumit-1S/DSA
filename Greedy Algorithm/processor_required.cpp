#include<bits/stdc++.h>
using namespace std;

struct comp
{
  bool operator()(pair<int,int> p1,pair<int,int> p2)
  {
    return p1.second<p2.second;
  }
};

int main()
{
  int n,s,e;
  cin>>n;
  vector<pair<int,int> > v;
  for(int i=0;i<n;i++)  
  {
    cin>>s>>e;
    v.push_back(make_pair(s,e));
  }
  sort(v.begin(),v.end(),comp());
  int prev_end=0,count=0,flag=0;
  while(flag<n){
    prev_end=0;
    for(int i=0;i<n;i++)
    {
      if(v[i].first>=prev_end and v[i].first!=-1)
      {
        v[i].first=-1;
        prev_end=v[i].second;
        flag++;
      }
    }
    count++;
  }
  cout<<count<<endl;
  return 0;
}