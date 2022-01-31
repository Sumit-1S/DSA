#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v;
        cin>>v;
        int d[v][v];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cin>>d[i][j];
            }
        }
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<v;k++)
                {
                    if(d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
                cout<<d[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}