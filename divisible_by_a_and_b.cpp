#include <iostream>
using namespace std;

//number of values between 1 to n divisible by a and b

int common(int n,int a,int b)
{
    int x = n/a;
    int y = n/b;
    int z = n/(a*b);
    return x+y-z;
}

int main()
{
    int a,b,n;
    std:cin>>n>>a>>b;
    cout<<common(n,a,b);
    return 0;
}