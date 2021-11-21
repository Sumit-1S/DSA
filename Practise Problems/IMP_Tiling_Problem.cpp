#include<iostream>
using namespace std;

int tiling_ways(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return tiling_ways(n-1) + tiling_ways(n-2);
}

int main()
{
    cout<<tiling_ways(6);
    return 0;   
}