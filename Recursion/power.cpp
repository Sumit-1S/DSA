#include<bits/stdc++.h>
using namespace std;
// Linear Time
int power(int n,int p)
{
    if(p==0)return n;
    return n*power(n,p-1);
}
// Log Time
int powerlog(int n,int p)
{
    if(p==1)return n;
    return power(n,p/2)*power(n,p/2);
}

int main()
{
    cout<<power(2,3);
    return 0;
}