#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++)
          cin>>arr[i];
        int max_area=0,area;
        for(int i=0,j=n-1;i<j;)
        {
          area=min(arr[i],arr[j])*(j-i-1);
          if(area>max_area)max_area=area;
          arr[i]<=arr[j]?i++:j--;
        }
        cout<<max_area<<endl;
    }
    return 0;
}