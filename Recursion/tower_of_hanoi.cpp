#include<iostream>
using namespace std;

int tower_hanoi(int n,char src,char dest,char helper,int count)
{
    if(n==0)
        return count;
    count = tower_hanoi(n-1,src,helper,dest,count+1);
    cout<<"Moved from "<<src<<"to"<<dest<<endl;
    count =  tower_hanoi(n-1,helper,dest,src,count+1);
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<tower_hanoi(n,'A','C','B',0)/2<<endl;
    return 0;
}