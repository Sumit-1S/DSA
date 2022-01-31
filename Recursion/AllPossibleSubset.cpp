#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

void helper(int pos,vector<vector<int> >& ans,vector<int> &nums, vector<int> temp){
    ans.push_back(temp);
  for(int i=pos;i<nums.size();i++){
    if(i!=pos and nums[i]==nums[i-1])continue;
    temp.push_back(nums[i]);
    helper(i+1,ans,nums,temp);
    temp.pop_back();
  }
}
  
int main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i=0;i<n;i++)cin>>nums[i];
  sort(nums.begin(),nums.end());
  vector<vector<int> > res;
  vector<int> temp;
  helper(0,res,nums,temp);
  cout<<"Subset are:->\n";
  for(int i=0;i<res.size();i++)
  {
    for(int j=0;j<res[i].size();j++)
      cout<<res[i][j]<<" ";
    cout<<endl;
  }
}