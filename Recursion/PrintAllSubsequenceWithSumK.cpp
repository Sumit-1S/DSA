#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define vs vector<string>
#define vvl vector<vector<ll,ll> >
#define mll map<ll,ll>

void allSequence(vector<int> v,int n,int tar,vector<int>& arr,int pos,int sum){
  if(pos==n){
    if(tar==sum){
      for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
      cout<<endl;
    }
    return;
  }
  
  arr.push_back(v[pos]);
  sum=sum+v[pos];
  allSequence(v,n,tar,arr,pos+1,sum);
  arr.pop_back();
  sum=sum-v[pos];
  allSequence(v,n,tar,arr,pos+1,sum);
}

bool firstSequence(vector<int> v,int n,int tar,vector<int>& arr,int pos,int sum){
  if(pos==n){
    if(tar==sum){
      for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
      cout<<endl;
      return true;
    }
    return false;
  }
  
  arr.push_back(v[pos]);
  sum=sum+v[pos];
  if(firstSequence(v,n,tar,arr,pos+1,sum))return true;;
  arr.pop_back();
  sum=sum-v[pos];
  if(firstSequence(v,n,tar,arr,pos+1,sum))return true;
  return false;
}

int countSequences(vector<int> v,int n,int tar,vector<int>& arr,int pos,int sum){
  if(pos==n){
    if(tar==sum){
      return 1;
    }
    return 0;
  }
  
  arr.push_back(v[pos]);
  sum=sum+v[pos];
  int l = countSequences(v,n,tar,arr,pos+1,sum);
  arr.pop_back();
  sum=sum-v[pos];
  int r = countSequences(v,n,tar,arr,pos+1,sum);
  return l+r;
}

int main()
{
  int n;
  cin>>n;
  vector<int> v(n),arr;
  for(int i=0;i<n;i++)cin>>v[i];
  int tar,pos=0;
  cin>>tar;
  allSequence(v,n,tar,arr,pos,0);
  cout<<endl;
  firstSequence(v,n,tar,arr,pos,0);
  cout<<endl;
  cout<<countSequences(v,n,tar,arr,pos,0);
  return 0;
}