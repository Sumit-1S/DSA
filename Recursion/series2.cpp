// Print 1 2 3 4 5
#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    if(n==0)return;
    print(--n);
    cout<<n+1<<" ";
}

int main()
{
    print(10);
    return 0;
}