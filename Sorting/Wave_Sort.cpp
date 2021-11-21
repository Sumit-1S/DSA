#include<iostream>
using namespace std;

// Imp: Wave sort sorts in a pattern
// arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=.....

void WaveSort(int* arr,int n)
{
    for(int i=1;i<n;)
    {
        if(arr[i]>arr[i-1])
            swap(arr[i],arr[i-1]);
        if(arr[i]>arr[i+1] && i<n-1)
            swap(arr[i],arr[i+1]);
        i+=2;
    }
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    WaveSort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}