#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,pair<int,int> >a, pair<int,pair<int,int> >b)
{
    return a.first > b.first;
}

int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n,weight,value,sack;
        cin>>n>>sack;
        vector<pair<int,pair<int,int> > > d;
        for(int i=0;i<n;i++)
        {
            cin>>weight>>value;
            d.push_back(make_pair(value/weight,make_pair(weight,value)));
        }
        sort(d.begin(),d.end(),compare);
        int profit=0;
        for(int i=0;i<n and sack>0;i++)
        {
            if(sack>=d[i].second.first)
            {
                sack-=d[i].second.first;
                profit+=d[i].second.second;
            }
            else
            {
                profit+=d[i].first*sack;
                sack=0;
            }
        }
        cout<<profit<<endl;
    }
    return 0;
}