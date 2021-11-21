#include<iostream>
using namespace std;

//Find numbers of ways in which a friend can remain single or can be paired up

int friend_pair(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;

    return friend_pair(n-1)+friend_pair(n-2)*(n-1);
}

int main()
{
    cout<<friend_pair(4);
    return 0;
}