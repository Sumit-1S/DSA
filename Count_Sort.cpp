#include<iostream>
using namespace std;

void Count(int* arr,int r)
{
    int maxi;
    for(int i=0;i<r;i++)
        maxi = max(arr[i],r);

    int *freq = new int[maxi+1];
    int *temp = new int[r];

    for(int i=0;i<=maxi;i++)
        freq[i]=0;

    for(int i=0;i<r;i++){
        freq[arr[i]]++;
    }

    for(int i=1;i<=maxi;i++)
        freq[i] +=freq[i-1];

    for(int i=r-1;i>=0;i--)
        temp[--freq[arr[i]]]=arr[i];
    
    for(int i=0;i<r;i++)
        arr[i] = temp[i];

}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    Count(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}