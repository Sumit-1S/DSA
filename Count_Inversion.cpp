#include<iostream>
using namespace std;

int MergeSort(int *arr,int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int *a = new int[n1];
    int *b = new int[n2];

    for(int i=0;i<n1;i++)
        a[i] = arr[i+l];
    for(int i=0;i<n1;i++)
        b[i] = arr[i+m+1];

    int i,j,k=l,inv=0;

    for(i=0,j=0;i<n1 && j<n2;)
    {
        if(a[i]>b[j])
        {
            arr[k] = b[j];
            inv += n1-i;            //Counting inversions
            k++;
            j++;
        }
        if(a[i]<b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }

    }
    while(i<n1)
    {
        arr[k] = a[i];
        k++;
        i++; 
    }
    while(j<n2)
    {
        arr[k] = b[j];
        k++;
        j++; 
    }
    return inv;
}

int Merge(int *arr,int l,int r)
{
    int inv=0;
    if(l<r)
    {
        int mid = (l+r)/2;
        inv+= Merge(arr,l,mid);
        inv+= Merge(arr,mid+1,r);
        inv+= MergeSort(arr,l,mid,r);
    }
    return inv;
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    cout<<Merge(arr,0,n-1)<<endl;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}