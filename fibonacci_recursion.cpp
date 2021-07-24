#include<iostream>
using namespace std;

void fibo(int a,int b,int n,int i) //find fibonacci series
{
    cout<<a+b<<" ";
    if(n==i)
        return;
    return fibo(b,a+b,n,++i);
}

int fibo2(int n) //find nth fibonacci number
{
    if(n==0||n==1)
        return n;

    return fibo2(n-1) + fibo2(n-2);
}

int main()
{
    int n,a=0,b=1;
    cin>>n;
    fibo(a,b,n,0);
    cout<<endl;
    cout<<fibo2(n);
    return 0;
}