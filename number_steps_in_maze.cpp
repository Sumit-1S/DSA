#include<iostream>
using namespace std;

//count number of path possible to reach end from start
//only allowed direction is in right or downward

int countPath(int n,int i,int j)
{
    if (i==n-1 && j==n-1)
        return 1;
    if(i>=n || j>=n)
        return 0;
    
    return countPath(n,i+1,j)+countPath(n,i,j+1);
}

int main()
{
    cout<<countPath(10,0,0)<<endl;
    return 0;
}