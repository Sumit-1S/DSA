#include<iostream>
using namespace std;

int part(int * arr,int l,int r)
{
    int j=l-1;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<arr[r])
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j+1],arr[r]);
    return j+1;
}

void QuickSort(int*arr , int l,int r)
{
    if(l<r)
    {
        int pivot = part(arr,l,r);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,r);
    }
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    QuickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}