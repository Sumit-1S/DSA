#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first > b.first;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > v;
        int deadline,profit;
        for(int i=0;i<n;i++)
        {
            cin>>profit>>deadline;
            v.push_back(make_pair(profit,deadline));
        }
        sort(v.begin(),v.end(),compare);
        int maxtime = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second>maxtime)
                maxtime=v[i].second;
        }
        int fill[maxtime];
        int count=0,maxProfit=0;

        for(int i=0;i<maxtime;i++)
            fill[i]=-1;

        for(int i=0;i<n;i++)
        {
            int j=v[i].second-1;
            while(j>=0 && fill[j]!=-1)
                j--;
            if(j>=0 && fill[j]==-1)
            {
                fill[j]=i;
                count++;
                maxProfit+=v[i].first;
            }
        }
        cout<<count<<" "<<maxProfit<<endl;
    }
    return 0;
}