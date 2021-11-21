#include<bits/stdc++.h>
using namespace std;

bool subset(int *arr,int n,int sum)
{
  if(n==0) return false;
  if(sum==0) return true;
  if(sum<arr[n-1]) return subset(arr,n-1,sum);
  return subset(arr,n-1,sum) || subset(arr,n-1,sum-arr[n-1]);
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    int sum;
    cin>>sum;
    subset(arr,n,sum)?cout<<"Yes":cout<<"No";
    return 0;
}