#include<iostream>
using namespace std;

// Dutch National Flag

void DNF(int *arr,int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            mid--;
            high--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];    
    
    DNF(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}