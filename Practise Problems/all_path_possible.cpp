#include<iostream>
using namespace std;

int count_steps(int s,int e)
{
    if(s==e)
        return 1;
    if(s>e)
        return 0;
    int count=0;
    for(int i=1;i<=6;i++)
    {
        count+= count_steps(s+i,e);
    }
    return count;
}

int main()
{
    cout<<count_steps(0,6);
    return 0;
}
